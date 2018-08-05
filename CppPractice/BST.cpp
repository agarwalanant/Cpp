//
// Created by Anant Agarwal on 8/5/18.
//

#include "iostream"

using namespace std;



class BST
{
private: class Node
    {
    public:
        long value = INT64_MIN;
        Node* left = nullptr;
        Node* right = nullptr;
    public:
        Node (long value)
        {
            this->value = value;
        }

    };
private: Node* root = nullptr;

public:
    long put( long value)
    {
        if(root == nullptr)
        {
            root = new Node(value);

        }
        else if(value <= root->value)
        {
            root->left->value = put(value);
        } else
        {
            root->right->value = put(value);
        }

        return value;

    }

    bool get(long value)
    {
        get(root,value);
    }

    bool get(Node* root, long value)
    {
        if(root == nullptr) return false;
        else if(root->value == value) return true;
        else if (root->value > value) return get(root->left,value);
        else return  get(root->right,value);
    }

    Node* find(Node* root, long value)
    {
        if(root == nullptr) return false;
        else if(root->value == value) return root;
        else if (root->value > value) return find(root->left,value);
        else return  find(root->right,value);
    }

    void del(long key)
    {
        del(root,key);
    }

    void del(Node*root, long value)
    {
        if(get(value))
        {
            Node* node = find(root,value);

            //no children
            if(node->right == nullptr && node->left == nullptr)
            {
                delete(node);
            }
            else if (node->right == nullptr && node->left != nullptr)
            {
                auto temp = node;
                node = node->left;
                delete(temp);
            }
            else if (node->left == nullptr && node->right != nullptr)
            {
                auto temp = node;
                node = node->right;
                delete(temp);
            }

            else if(node->left != nullptr && node->right != nullptr)
            {
                node->value = node->right->value; // copying value on the right of node to node
                node->right->left = node->left; // moving left of the node to the

                auto temp = node;
                node = node->right;
                delete(temp);

            }
        } else cout<<"Value specified is not present"<<endl;
    }


};


int main()
{
    BST bst;
    cout<<bst.put(12)<<endl;
    cout<<bst.get(123)<<endl;
    cout<<bst.get(12)<<endl;


    return 0;
}