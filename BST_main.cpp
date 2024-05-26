#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left= nullptr;
        right= nullptr;
    }
};
class BST{
public:
    Node* root;
    BST(){
        root = nullptr;
    }
    Node* insertnode(Node* p, int value){
        if (p ==nullptr){
            Node* newnode = new Node(value);
            p = newnode;
        }
        else if (value < p->data){
            p->left = insertnode(p->left,value);
        }
        else {
            p->right = insertnode(p->right,value);
        }
    }
    void insertnode(int value){
        root = insertnode(root,value);
    }
    void preorder_display(Node* ptr){
        if (ptr == nullptr){
            return;
        }
        else {
            cout<< ptr->data << " ";
            preorder_display(ptr->left);
            preorder_display(ptr->right);
        }
    }
    void inorder_display(Node* ptr){
        if (ptr == nullptr){
            return;
        }
        else {
            inorder_display(ptr->left);
            cout<< ptr->data << " ";
            inorder_display(ptr->right);
        }
    }
    void postorder_display(Node* ptr){
        if (ptr == nullptr){
            return;
        }
        else {
            postorder_display(ptr->left);
            postorder_display(ptr->right);
            cout<< ptr->data << " ";
        }
    }
    Node* findnode(Node* p, int item){
        if (p == nullptr)
            return 0;
        else if (item == p->data)
            return p;
        else if (item < p->data)
            return findnode(p->left,item);
        else
            return findnode(p->right,item);


    }
    bool findnode(int item){
        Node* result = findnode(root,item);
        if (result == nullptr)
            return false;
        else
            return true;

    }
    Node* findmin(Node* pt){
        if (pt == nullptr)
            return nullptr;
        else if (pt->left== nullptr)
            return pt;
        else
            return (findmin(pt->left));
    }
    Node* findmax(Node* pt){
        if (pt == nullptr)
            return nullptr;
        else if (pt->right== nullptr)
            return pt;
        else
            return (findmax(pt->right));
    }
    int findmin(){
        return findmin(root)->data;
    }
    int findmax(){
        return findmax(root)->data;
    }
    Node* delnode(Node* p, int item){
        if (p == nullptr)
            return nullptr;
        else if (item < p->data)
            p->left = delnode(p->left,item);
        else if (item > p->data)
            p->right = delnode(p->right,item);
        else {
                if (p->left == nullptr && p->right == nullptr)
                    p=nullptr;
                else if (p->left != nullptr && p->right==nullptr){
                    p->data = p->left->data;
                    delete p->left;
                    p->left = nullptr;
                }
                else if (p->left == nullptr && p->right!= nullptr){
                    p->data = p->right->data;
                    delete p->right;
                    p->right = nullptr;
                }
                else{
                    Node* predes = findmax(p->left);
                    p->data = predes->data;
                    p->left = delnode(p->left,predes->data);
                }



             }

        return p;


    }


};


int main()
{
    cout << "Hello world!" << endl;
    BST tree1;
    tree1.insertnode(45);
    tree1.insertnode(15);
    tree1.insertnode(20);
    tree1.insertnode(65);
    tree1.insertnode(70);
    tree1.insertnode(90);
    tree1.insertnode(12);
    tree1.insertnode(55);
    tree1.preorder_display(tree1.root);
    cout<< "\n ****************************************** \n";
    tree1.inorder_display(tree1.root);
    cout<< "\n ****************************************** \n";
    tree1.postorder_display(tree1.root);
    cout<< "\n ****************************************** \n";
    cout<<tree1.findnode(10)<<endl;
    cout<<tree1.findnode(15)<<endl;
    cout<<tree1.findmax()<<endl;
    cout<<tree1.findmin()<<endl;
    Node* res = tree1.delnode(tree1.root,90);
    tree1.preorder_display(res);
    cout<< "\n ****************************************** \n";



    return 0;
}
