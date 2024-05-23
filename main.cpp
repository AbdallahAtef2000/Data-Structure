#include <iostream>

using namespace std;


class Node{
public :
    int data;
    Node* ptr;
    Node(int val){
        this->data = val;
        this->ptr = nullptr;
    }
};

class Stack{
public :
    Node* top;
    Stack(){
        top = nullptr;
    }
    bool isempty(){
        return(top == nullptr);
    }
    void push(int item){
        Node* newnode = new Node(item);
        newnode->ptr = top;
        top = newnode;
    }
    void pop(){
        Node* delptr = top;
        top = top->ptr;
        delete delptr;
    }
    void display(){
        Node* temp = top;
        while (temp!= nullptr){
            cout<< temp->data<< " ";
            temp = temp->ptr;
        }
        delete temp;
        cout<<endl;
    }
    int peek(){
        return(top->data);
    }
    int countnodes(){
        int counter = 0;
        Node* temp = top;
        while(temp!=nullptr){
            counter++;
            temp = temp->ptr;
        }
        return counter;
        delete temp;

    }
    bool isfound(int item){
        Node* temp = top;
        while(temp!= nullptr){
            if (temp->data == item){
                return true;
                break;
            }
            else{
                temp = temp->ptr;
            }
        }
        delete temp;
    }
    void isfull(){
         Node* fulptr = new Node(0);
         if(fulptr == nullptr){
            cout<< "the stack is full"<<endl;
         }
         else {
            cout<< " still have space in the memory"<<endl;
         }
         delete fulptr;
    }


    };


int main()
{
    Stack st1;
    int item;
    int no_of_items;
    cout<< " The number of values to add "<<endl;
    cin>> no_of_items;
    for(int i =0 ; i < no_of_items; i++){
        cout<< "the item no "<< i+1<<endl;
        cin>>item;
        st1.push(item);
    }
    st1.display();
    st1.pop();
    cout<<st1.peek()<<endl;
    cout<<st1.countnodes()<<endl;
    cout<< " The value to search for "<<endl;
    cin>>item;
    cout<<st1.isfound(item)<<endl;
    st1.isfull();


    return 0;
}
