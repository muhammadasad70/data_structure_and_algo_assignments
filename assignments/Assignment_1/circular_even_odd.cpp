#include<iostream>
using namespace std;

struct Node{

    int num;
    Node *next;
};
Node *first = NULL;
Node *last=NULL;
Node *oddlist = NULL;
Node *evenlist = NULL;
void insert(int data) {
    Node* current = new Node();
    current->num=data;
    if (first==NULL) {
        first = current;
        current->next = first;
    } else {
        Node* p = first;
        while (p->next != first) {
            p = p->next;
        }
        p->next = current;
        current->next = first;
    }
}
void split_List(int data, Node*& head) {
    Node* current = new Node();
    current->num = data;
    current->next = NULL;

    if (head == NULL) {
        head = current;
        head->next = head; 
    } else {
        Node *p= head;
        while (p->next != head) {
            p = p->next;
        }
        p->next = current;
        current->next = head;
    }
}
void Even_odd() {
    if (first==NULL) {
        return;
    }

    Node* current = first;
    do {
        if (current->num % 2 == 0) {
            split_List(current->num,evenlist );
        } else {
            split_List(current->num,oddlist);

        }
        delete current;
        current = current->next;
    } while (current != first);
    first=last=NULL;
}
void display(Node *head) {
    if (head==NULL) {
        cout<<"list is empty"<<endl;
        return;
    }
    Node *current = head;
    do {
        cout << current->num <<",";
        current = current->next;
    } while (current != head);
}

int main() {
    cout<<"How much values you want to enter in the list"<<endl;
    int list_length;
    cin>>list_length;
    int num;
    cout<<"Enter the value you want to enter in this list"<<endl;
    for (int i = 1; i <=list_length; i++) {
        cin>>num;
        insert(num);
    }
    cout<<"The numbers in the list are following"<<endl;
    display(first);
    Even_odd();
    cout<<endl;
    cout<<"Even numbers in the list are"<<endl;
    display(evenlist);
    cout<<endl;
    cout<<"Odd numbers in the list are"<<endl;
    display(oddlist);
}