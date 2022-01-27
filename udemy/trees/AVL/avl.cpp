#include "../../lib/commonImport.hpp"

typedef struct Node
{
	int data;
	int height;
	Node* left;
	Node* right; 
}Node;

class AVL
{
	Node* root;
public:
	AVL() : root(0)	{}
	
	Node* newnode(int data)
	{
		Node* newnode = new Node;
		newnode->data = data;
		newnode->height = 1;
		newnode->left = newnode->right = NULL;
		return newnode;
	}
	
	int height(Node* head)
	{
		if(!head) return 0;
		
		int x = height(head->left);
		int y = height(head->right);
		
		if(x > y) 
			return x + 1;
		else
			return y + 1;		
	}
	
	int balancefactor(Node* head)
	{
		if(!head) return 0;
		
		return (height(head->left) - height(head->right));
	}
	
	Node* llRotation(Node* head)
	{
		Node* headl = head->left;
		Node* headlr = headl->right;
		
		headl->right = head;
		head->left = headlr;
		
		headl->height = height(headl);
		head->height = height(head);
		
		if(root == head)
			root = headl;
		
		return headl;
	}
	
	Node* rrRotation(Node* head)
	{
		return 0;
	}
	
	Node* lrRotation(Node* head)
	{
		Node* headl = head->left;
		Node* headlr = headl->right;
		
		headl->right = headlr->left;
		head->left = headlr->right;
		headlr->left = headl;
		headlr->right = head;
		
		head->height = height(head);
		headl->height = height(headl);
		headlr->height = height(headlr);
		
		if(head == root)
			root = headlr;
		
		return headlr;
	}
	
	Node* rlRotation(Node* head)
	{
		return 0;
	}	
	
	Node* rinsert(Node* head, int data)
	{
		if(!head)
		{
			head = newnode(data);
			if(!root)
				root = head;
			return head;
		}
		
		if(head->data < data)
			head->right = rinsert(head->right, data);
		else
			head->left = rinsert(head->left, data);
		
		head->height = height(head);
		
		// rotations
		if((balancefactor(head) == 2) && (balancefactor(head->left) == 1))
			return llRotation(head);
		else if((balancefactor(head) == -2) && (balancefactor(head->left) == -1))
			return rrRotation(head);
		else if((balancefactor(head) == 2) && (balancefactor(head->left) == -1))
			return lrRotation(head);
		else if((balancefactor(head) == -2) && (balancefactor(head->left) == 1))
			return rlRotation(head);
		
		return head;
	}
	
	void create(std::vector<int> vec)
	{
		for(auto ele : vec)
		{
			rinsert(root, ele);
		}
	}
	
	void inorder(Node* head)
	{
		if(!head) return;
		inorder(head->left);
		LOG("data : " << head->data << "\theight : " << head->height);
		inorder(head->right);
	}
	
	void inorder()
	{
		inorder(root);
	}
};

int main()
{
	AVL obj;
	std::vector<int> vec = {50,10,20};
	obj.create(vec);
	
	obj.inorder();
}
