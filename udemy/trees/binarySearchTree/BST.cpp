#include "../../lib/commonImport.hpp"

typedef struct Node
{
    Node* left;
    Node* right;
    int data;
}Node;

enum Type
{
    recursive = 0,
    iterative
};

class BST
{
    Node* root;
public:
    BST() : root(0) { }

    Node* newnode(int data)
    {
        Node* node = new Node;
        node->left = node->right = 0;
        node->data = data;
        return node;
    }

    void create(std::vector<int> vec, Type type)
    {
        if(type > 1) return;
        for(const int& val : vec)
           insert(val, type);
    }

    Node* rInsert(Node* head, int data)
    {
        if(!head)
        {
            head = newnode(data);
            if(!root)
                root = head;
            return head;
        }

        if(head->data == data)
            return head;
        else if(head->data < data)
            head->right = rInsert(head->right, data);
        else
            head->left = rInsert(head->left, data);
        return head;
    } 

    void iInsert(int data)
    {
        if(!root)
            root = newnode(data);
        else
        {
            Node* head = root;
            Node* tail;
            while(head)
            {
                tail = head;
                if(head->data == data)
                    return;
                else if(head->data < data)
                    head = head->right;
                else
                    head = head->left;
            }
            if(tail-> data < data)
                tail->right = newnode(data);
            else
                tail->left = newnode(data);
        }
    }

    void insert(int data, Type val)
    {
        if(val > 1) return;
        if(val == recursive)
            rInsert(root, data);
        else
            iInsert(data);
    }

    Node* rsearch(Node* head, int key)
    {
        if(!head) return 0;

        if(head->data == key)
            return head;
        else if(head->data < key)
            return rsearch(head->right, key);
        else
            return rsearch(head->left, key);
    }

    Node* isearch(int key)
    {
        Node* head = root;
        while(head)
        {
            if(head->data == key)
                return head;
            else if(head->data < key)
                head = head->right;
            else
                head = head->left;
        }
        return 0;
    }

    Node* search(int key, Type val)
    {
        if(val > 1) return 0;
        if(val == recursive)
            return rsearch(root, key);
        else
            return isearch(key);
    }

    void rInorder(Node* head)
    {
        if(!head) return;

        rInorder(head->left);
        LOG_T(head->data);
        rInorder(head->right);
    }

    void inorder()
    {
        rInorder(root);
        LOG("");
    }

    int level(Node* head)
    {
        if(!head) return 0;
        int x = level(head->left);
        int y = level(head->right);
        if(x > y)
            return x + 1;
        else
            return y + 1;
    }

    Node* inorderPredecessor(Node* head)
    {
        if(!head) return NULL;

        Node* tail;
        while(head)
        {
            tail = head;
            head = head->right;
        }
        return tail;
    }

    Node* inorderSuccessor(Node* head)
    {
        if(!head) return NULL;

        Node* tail;
        while(head)
        {
            tail = head;
            head = head->left;
        }
        return tail;
    }

    Node* deleteNode(Node* head, int data)
    {
        if(!head) return NULL;

        if((!head->left) && (!head->right))
        {
            if(head == root)
                root = NULL;
            delete(head);
            return NULL;
        }

        if(head->data < data)
            head->right = deleteNode(head->right, data);
        else if(head->data > data)
            head->left = deleteNode(head->left, data);
        else
        {
            Node* temp;
            if(level(head->left) > level(head->right))
            {
                temp = inorderPredecessor(head->left);
                head->data = temp->data;
                head->left = deleteNode(head->left, temp->data);
            }
            else
            {
                temp = inorderSuccessor(head->right);
                head->data = temp->data;
                head->right = deleteNode(head->right, temp->data);
            }
        }
        return head;
    }

    void deleteNode(int data)
    {
        deleteNode(root,data);
    }

    void generateFromPreorder(std::vector<int> pre)
    {
        // REMEMBER : for post order start from end of vector and decrement till beginning
        root = NULL; // discard previous values
        int size = pre.size();
        root = newnode(pre[0]);
        std::stack<Node*> stack;
        int data;

        Node* temp = root;
        for(int i = 1; i < size; i++)
        {
            data = pre[i];
            if(data < temp->data)
            {
                temp->left = newnode(data);
                stack.push(temp);
                temp = temp->left;
            }
            else if(data > temp->data)
            {
                int stackTop = (stack.empty())? INT32_MAX : (stack.top())->data;
                if(data < stackTop)
                {
                    temp->right = newnode(data);
                    temp = temp->right;
                    
                }
                else
                {
                    temp = stack.top(); stack.pop();
                    --i; // to accomodate for ++i later, since we do not want to increment for this condition
                }
            }
        }
    }

};

int main()
{
    BST obj;
    // std::vector<int> vec = {7,5,6,1,4,3,2};
    // obj.create(vec, iterative);

    std::vector<int> pre = {30,20,10,15,25,40,50,45};
    obj.generateFromPreorder(pre);
    obj.inorder();

    return 0;
}
