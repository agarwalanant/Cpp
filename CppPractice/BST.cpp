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
            this->right = this->left = nullptr;
        }

    };
private: Node* root = nullptr;

public:
    Node* put( Node* root,long value)
    {
        if(root == nullptr)
        {
            root = new Node(value);

        }
        else if(value <= root->value)
        {
            root->left = put(root->left,value);
        } else
        {
            root->right = put(root->right,value);
        }

        return root;

    }

    long put(long value)
    {
        put(root,value);

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
                del(node->right,root->value);

            }
            cout<<value<<" deleted"<<endl;
        } else cout<<"Value specified is not present"<<endl;
    }


};


int main()
{
    BST bst;
    cout<<bst.put(12)<<endl;
    cout<<bst.get(12)<<endl;
    cout<<bst.put(123)<<endl;
    bst.put(2);
    bst.put(6);
    bst.put(33);
    bst.put(7);
    bst.put(9);
    bst.put(0);
    bst.put(255);
    bst.put(65);
    bst.put(765);
    bst.put(2644);
    cout<<"Executed"<<endl;

    bst.del(12);
    cout<<bst.get(12)<<endl;

    return 0;
}