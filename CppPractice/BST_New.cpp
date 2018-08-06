// Created By Anant Agarwal on 06/08/2018


#include<iostream>
using namespace std;
//Definition of Node for Binary search tree






// To insert data in BST, returns address of root node

class BST
{
public: BST()
    {
        root = nullptr;
    }
    class BstNode {
    public:
        int data;
        BstNode* left;
        BstNode* right;

    public:  BstNode(int data)
        {
            this->data = data;
            this->right = right;
            this->left = left;
        }
    };
public:BstNode* root;


BstNode* Insert(BstNode* root,int data) {
    if(root == nullptr) { // empty tree
        root = new BstNode(data);
    }
        // if data to be inserted is lesser, insert in left subtree.
    else if(data <= root->data) {
        root->left = Insert(root->left,data);
    }
        // else, insert in right subtree.
    else {
        root->right = Insert(root->right,data);
    }

    return root;
}

public:void Insert(int data)
{
   root = Insert(root,data);
}
//To search an element in BST, returns true if element is found
bool Search(BstNode* root,int data) {
    if(root == nullptr) {
        return false;
    }
    else if(root->data == data) {
        return true;
    }
    else if(data <= root->data) {
        return Search(root->left,data);
    }
    else {
        return Search(root->right,data);
    }

}

public: bool Search(int data)
{
    if(Search(root,data))
        return true;
    else return false;
}

public: BstNode* Delete(BstNode* node, int data)
{
    BstNode* temp;
    if(root == nullptr) {return root;}
    else if(data < root->data) root->left =  Delete(root->left,data);
    else if(data > root->data) root->right = Delete(root->right,data);

    else if(root->left && root->right)
    {
        temp = min(root->right);

        root->data = temp->data;
        root->right = Delete(root->right,temp->data);
    }
    else
    {
        temp = root;
        if(root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }

        else if(root->left == nullptr)
        {
             temp = root;
            root = root->right;
            delete temp;
        }

        else if( root->right == nullptr)
        {
             temp = root;
            root = root->left;
            delete temp;
        }
    }

    return root;


}

public: void Delete(int data)
{
   root =  Delete(root,data);
}

BstNode* min(BstNode* root)
{
    while (root->left != nullptr) root = root->left;
    return root;
}
};
int main() {
      // Creating an empty tree
    /*Code to test the logic*/
    BST b;
    b.Insert(15);
    b.Insert(10);
   b.Insert(20);
    b.Insert(25);
   b.Insert(8);
    b.Insert(12);
//   b.Delete(25);
    int number;
    cout<<"Enter number be searched\n";
    cin>>number;

    if(b.Search(number)) cout<<"Found\n";
    else cout<<"Not Found\n";
    b.Delete(25);

}