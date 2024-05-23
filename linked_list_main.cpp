#include <iostream>
#include <string>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        this->data = val;
        this->next= nullptr;
    }
};


class Linkedlist{
public:
    Node* head;
    Linkedlist(){
        head= NULL;
    }
    bool isempty(){
        return(head== nullptr);
    }
    void insertfirst(int value){
        Node *newnode = new Node(value);
        newnode->next =head;
        head = newnode;
    }

    void display(){
        Node* temp = head;
        cout<< "the content is"<<endl;
        while(temp!= nullptr){
            cout<< temp->data<<" ";
            temp = temp->next;

        }
        cout<<"\n";
    }

    bool isfound(int item){
        Node* temp = head;
        while(temp != nullptr){
           if (temp->data == item){
            return true;
            break;
           }
           else{
            temp=temp->next;
           }
        }
        return false;
    }

    int countnodes(){
        Node* temp= head;
        int counter=0;
        while(temp != nullptr){
            counter++;
            temp = temp->next;
        }
        return counter;

    }

    void insertlast(int value){
        Node* newnode = new Node(value);
        Node* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newnode;

    }

    void insertbefore(int item, int newvalue){
        Node* newnode = new Node(newvalue);
        Node* temp= head;
        while(temp->next->data != item && temp != nullptr){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp ->next = newnode;
    }

    void deletitem(int item){
        Node* delptr = head;
        delptr = delptr->next;
        Node* preptr = head;
        while(delptr!= nullptr && delptr->data != item){
            delptr= delptr->next;
            preptr = preptr->next;
        }
        preptr->next = delptr->next;
        delete delptr;
    }

    void replacenodes(int item1, int item2){
        Node* temp1 = head;
        Node* temp2 =head;
        while (temp1->next->data != item1 && temp1!= nullptr){
            temp1= temp1->next;
        }
        while (temp2->next->data != item2 && temp2!= nullptr){
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp2->next->next;

    }


};



int main()
{
    int no_items;
    int itema;
    Linkedlist lst;
    cout<<lst.isempty()<<endl;
    cout<< "enter the no of values"<<endl;
    cin>> no_items;
    for (int i =0 ; i < no_items;i++){
        cout<< "the item no "<< i+1 <<endl;
        cin>>itema;
        lst.insertfirst(itema);
    }
    lst.display();
    cout<< "value to add at the end of list"<<endl;
    cin>>itema;
    lst.insertlast(itema);
    lst.display();
    cout<< "the value to insert in the list"<<endl;
    cin>>itema;
    int pos;
    cout<< "the item should be after this value "<<endl;
    cin>>pos;
    lst.insertbefore(pos,itema);
    lst.display();
    int delitem;
    cout<< " the item you want to delete \n";
    cin>>delitem;
    lst.deletitem(delitem);
    lst.display();






    return 0;
}
