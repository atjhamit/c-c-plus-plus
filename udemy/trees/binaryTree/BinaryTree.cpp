#include "../../lib/commonImport.hpp"

typedef struct Node
{
    int data;
    Node* left;
    Node* right;
}Node;

enum Type
{
    recursive=0,
    iterative
};

class Tree
{
public:
    Node* root;
    Tree() : root(0) {    }

    Node* createNode(int data)
    {
        Node* newnode = new Node;
        newnode->data = data;
        newnode->left = newnode->right = 0;
        return newnode;
    }

    void create()
    {
        LOG_T("Enter the root element:");
        int data;
        std::cin >> data;
        root = createNode(data);

        // level order insertion
        std::queue<Node*> q;
        q.push(root);

        Node* head;
        while(!q.empty())
        {
            head = q.front(); q.pop();
            LOG_T("\nEnter left child of " << head->data << ". ( 0 -> no child ):");
            std::cin >> data;
            if(data)
            {
                head->left = createNode(data);
                q.push(head->left);
            }
            LOG_T("\nEnter right child of " << head->data << ". ( 0 -> no child ):");
            std::cin >> data;
            if(data)
            {
                head->right = createNode(data);
                q.push(head->right);
            }
        }
    }

    void rInorder(Node* head)
    {
        if(!head) return;

        rInorder(head->left);
        LOG_T(head->data);
        rInorder(head->right);
    }

    void iInorder()
    {
        Node* temp = root;
        std::stack<Node*> stack;

        while(temp || !stack.empty())
        {
            if(temp)
            {
                stack.push(temp);
                temp = temp->left;
            }
            else
            {
                temp = stack.top(); stack.pop();
                LOG_T(temp->data);
                temp = temp->right;
            }
        }
    }

    void inorder(Type val)
    {
        if(val > iterative) return;

        if(val == recursive)
            rInorder(root);
        else
            iInorder();
        LOG("");
    }


    void rPreorder(Node* head)
    {
        if(!head) return;

        LOG_T(head->data);
        rPreorder(head->left);
        rPreorder(head->right);
    }

    void iPreorder()
    {
        Node* temp = root;
        std::stack<Node*> stack;

        while(temp || !stack.empty())
        {
            if(temp)
            {
                LOG_T(temp->data);
                stack.push(temp);
                temp = temp->left;
            }
            else
            {
                temp = stack.top(); stack.pop();
                temp = temp->right;
            }
        }
    }

    void preorder(Type val)
    {
        if(val > iterative) return;

        if(val == recursive)
            rPreorder(root);
        else
            iPreorder();
        LOG("");
    }


    void rPostorder(Node* head)
    {
        if(!head) return;

        rPostorder(head->left);
        rPostorder(head->right);
        LOG_T(head->data);
    }

    void iPostorder()
    {
        Node* temp = root;
        std::stack<Node*> stack;
        long int addr = 0;

        while(temp || !stack.empty())
        {
            if(temp)
            {
                stack.push(temp);
                temp = temp->left;
            }
            else
            {
                addr = (long int) (stack.top()); stack.pop();
                if(addr > 0)
                {
                    stack.push((Node*)(-1 * addr));
                    temp = (Node*) addr;
                    temp = temp->right;
                }
                else
                {
                    addr = addr * -1;
                    temp = (Node*)addr;
                    LOG_T(temp->data);
                    temp = 0;
                }
            }
        }
    }

    void postorder(Type val)
    {
        if(val > iterative) return;

        if(val == recursive)
            rPostorder(root);
        else
            iPostorder();
        LOG("");
    }

    void levelorder()
    {
        Node* temp = root;
        std::queue<Node*> queue;

        queue.push(temp);
        LOG_T(temp->data);

        while(!queue.empty())
        {
            temp = queue.front(); queue.pop();
            if(temp->left)
            {
                LOG_T(temp->left->data);
                queue.push(temp->left);
            }
            if(temp->right)
            {
                LOG_T(temp->right->data);
                queue.push(temp->right);
            }
        }
        LOG("");
    }

};

int main()
{
    Tree tree;
    tree.create();
    LOG("inorder");
    tree.inorder(iterative);
    tree.inorder(recursive);

    LOG("preorder");
    tree.preorder(iterative);
    tree.preorder(recursive);

    LOG("postorder");
    tree.postorder(iterative);
    tree.postorder(recursive);

    LOG("levelorder");
    tree.levelorder();
    return 0;
}
