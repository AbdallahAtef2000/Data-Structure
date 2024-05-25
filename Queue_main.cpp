#include <iostream>

using namespace std;

class Node{
public :
    int data;
    Node* ptr;
    Node(int value){
        this->data = value;
        this->ptr = nullptr;
    }
};

class Queue{
private:
    Node* first;
    Node* last;
public:
    Queue(){
        this->first = nullptr;
        this->last = nullptr;
    }
    bool isempty(){
        return(first == nullptr);
    }
    void enqueue(int item){
        Node* newnode = new Node(item);
        if (isempty()){
            first = newnode;
            last = newnode;
        }
        else{
            last->ptr = newnode;
            last = newnode;
        }
    }
    void dequeue(){
        if (isempty()){
            cout<< "the queue is empty\n";
        }
        else if(first == last && first != nullptr){
            Node* delptr = first;
            first = nullptr;
            last = nullptr;
            delete delptr;
        }
        else{
        Node* delptr = first;
        first = first->ptr;
        delete delptr;
        }
    }
    void display(){
        if (isempty()){
            cout<< " the queue is empty "<<endl;
        }
        else{
        Node* temp = first;
        while(temp != nullptr){
            cout<< temp->data<<" ";
            temp = temp->ptr;
        }
        cout<< endl;
        delete temp;
        }
    }
    int getfirst(){
        return first->data;
    }
    int getlast(){
        return last->data;
    }
    int countnodes(){
        Node* temp = first;
        int counter = 0;
        while(temp!= nullptr){
            counter++;
            temp =temp->ptr;
        }
        return counter;
    }
    void clearnodes(){
        while(!isempty()){
            dequeue();
        }
    }

} ;

int main(){
    int input;
    int noofvalues;
    Queue q1;
    cout<< q1.isempty()<<endl;
    cout<< " the no of values to add"<<endl;
    cin>>noofvalues;
    for(int i =0 ; i< noofvalues ; i++){
        cout<< " the value no " << i+1 <<endl;
        cin>>input;
        q1.enqueue(input);

    }

    q1.display();
    q1.dequeue();
    cout<< "after deletion \n";
    q1.display();
    cout<<q1.getfirst()<< " is the first value" <<endl;
    cout<<q1.getlast()<< " is the last value "<<endl;
    q1.clearnodes();
    q1.display();


    return 0;
}
