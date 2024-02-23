#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {

        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class binaryTree
{
public:
    node *root;

    binaryTree()
    {
        this->root = NULL;
    }

    int height(node *root)
    {
        if (root == NULL)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        return max(left, right) + 1;
    }

    bool check_balanced(node *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        bool left = check_balanced(root->left);
        bool right = check_balanced(root->right);

        bool diff = abs(height(root->left)) - (height(root->right)) <= 1;

        return left && right && diff;
    }
};

int main()
{

    binaryTree bt;
    bt.root = new node(1);

    bt.root->left = new node(2);
    bt.root->right = new node(3);
    bt.root->left->left = new node(4);
    bt.root->left->left->left = new node(23);
    bt.root->left->right = new node(5);
    bt.root->left->right->right = new node(45);
    bt.root->left->right->right->right = new node(78);
    bt.root->left->right->right->right->right = new node(67);
    bt.root->right->left = new node(6);
    bt.root->right->right = new node(7);

    //                  1
    //                /   \ 
    //              2       3
    //             / \     / \ 
    //            4   5   6   7
    //           /     \   
    //          23      45
    //                   \  
    //                    78
    //                     \ 
    //                      67

    cout << "Is Balanced : " << bt.check_balanced(bt.root) << endl;

    return 0;
}