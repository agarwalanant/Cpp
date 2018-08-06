// Created By Anant Agarwal on 06/08/2018


#include<iostream>
using namespace std;
//Definition of Node for Binary search tree
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





// To insert data in BST, returns address of root node

class BST
{
    BstNode* root;

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

public:BstNode* Insert(int data)
{
    Insert(root,data);
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

    int number;
    cout<<"Enter number be searched\n";
    cin>>number;

    if(b.Search(number)) cout<<"Found\n";
    else cout<<"Not Found\n";
}