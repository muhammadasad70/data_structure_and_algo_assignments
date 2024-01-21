#include<iostream>
using namespace std;
struct Node{
    int marks;
    int id;
    struct Node *next;
};
Node *first=NULL;
Node *last=NULL;

Node *serch(int key){
    Node *p=first;
    Node *q=p;
    while (p->next!=first){
        if(key==p->id)
            return p;
        p=p->next;    
    }
    if(p->id==key){
        cout<<p->id<<endl;
        return p;
    }
    return NULL;
    
}
Node *serch_befor(int key){
    Node *p=first;
    Node *k;
    while (p->id!=key){
        if(p==NULL){
            break;
        }
        k=p;
        p=p->next;
    }
    return k;
}
void insert_in_a_list(){
    int marks;
    int id;
    struct Node *currrent;
    cout<<"Enter the marks of the student :"<<endl;
    cin>>marks;
    cout<<"Enter the id of the student :"<<endl;
    cin>>id;
    currrent->marks=marks;
    currrent->id=id;
    currrent->next=first;
    first=currrent;
}
void insert_at_first(){
    int marks;
    int id;
    cout<<"Enter the marks of the student :"<<endl;
    cin>>marks;
    cout<<"Enter the id of the student :"<<endl;
    cin>>id;
    Node *current_node=new Node;
    current_node->marks=marks;
    current_node->id=id;
    
    if(first==NULL){
        first=last=current_node;
    }
    else{
        current_node->next=first;
        first=current_node;
        last->next=first;
    }

}
void insert_at_end(){
    int marks;
    int id;
    cout<<"Enter the marks of the student :"<<endl;
    cin>>marks;
    cout<<"Enter the id of the student :"<<endl;
    cin>>id;
    Node *current_node=new Node;
    current_node->marks=marks;
    current_node->id=id;
    if(last==NULL){
        last=first=current_node;
    }
    else{
        last->next=current_node;
        last=current_node;
        current_node->next=first;
    }
    
}
void display_circular(){
    Node *p=first;
    do
    {
        cout<<"The marks of the student is: "<<p->marks<<endl;
        cout<<"The id of the student is: "<<p->id<<endl;
        p=p->next;

    } while (p!=first);
    
}
void insert_after_specific(int key){
    Node *p=serch(key);
    cout<<p<<endl;
    if(p==NULL){
        cout<<"The key not found at the given index:"<<endl;
    }
    else if (p==last)
    {
        insert_at_end();
    }
    else{
        int marks;
        int id;
        cout<<"Enter the marks of the student :"<<endl;
        cin>>marks;
        cout<<"Enter the id of the student :"<<endl;
        cin>>id;
        Node *current_node=new Node;
        current_node->marks=marks;
        current_node->id=id;
        current_node->next=p->next;
        p->next=current_node;
    }
}
void insert_befor_specific(int key){
    Node *p=serch(key);
    Node *current_node=new Node;
    if(p==first){
        insert_at_first();
    }
    else if(p==NULL){
        cout<<"The key not exist";
    }
    else{
        int marks;
        int id;
        cout<<"Enter the marks of the student :"<<endl;
        cin>>marks;
        cout<<"Enter the id of the student :"<<endl;
        cin>>id;
        Node *q=serch_befor(key);
        current_node->next=q->next;
        q->next=current_node;
        current_node->marks=marks;
        current_node->id=id;

    }
}
void delete_at_first(){
    Node *p=first;
    if(p==NULL){
        cout<<"Nothing to delete"<<endl;
    }
    else{
        p=first;
        last->next=p->next;
        first=first->next;
        delete p;
    }

}
void delete_at_last(){
    Node *p=first;
    if(first==NULL){
        cout<<"Nothing to delete"<<endl;
    }
    else if (first==last)
    {
        p=first;
        first=last=NULL;
        delete p;
    }
    else{
         Node *p=first;
        Node *q=new Node;
        while (p->next->next!=first){
            p=p->next;
            }
        q=p->next;
        p->next=q->next;
        last=p;
        delete p;
    }
}
void delete_at_specific(int key){
    Node *p=serch(key);
    if(p==first){
        delete_at_first();
    }
    else if (p==last){
        delete_at_last();
    }
    else
    {
        Node *q=serch_befor(key);
        q->next=q->next->next;
        q=q->next;
        delete q;
    }
    
}
int main() {
    int choice;
    while(true) {
        cout << "Menu:" << endl;
        cout << "1. Insert at Start" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert Before Specific ID" << endl;
        cout << "4. Insert After Specific ID" << endl;
        cout << "5. Delete At First" << endl;
        cout << "6. Delete At Last" << endl;
        cout << "7. Delete Specific ID" << endl;
        cout << "8.  Search" << endl;
        cout << "9.  Search Befor" << endl;
        cout << "10.  Display The circular list" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        
        cin >> choice;

        switch(choice) {
            case 1:
                insert_at_first();
                break;
            case 2:
                insert_at_end();
                break;
            case 3:
                int key;
                cout << "Enter the ID after which you want to insert: ";
                cin >> key;
                insert_befor_specific(key);
                break;
            case 4:
                int key_after;
                cout << "Enter the ID after which you want to insert: ";
                cin >> key_after;
                insert_after_specific(key_after);
                break;
            case 5:
                delete_at_first();
                break;
            case 6:
                delete_at_last();
                break;
            case 7:
                int key_delete;
                cout << "Enter the ID you want to delete: ";
                cin >> key_delete;
                delete_at_specific(key_delete);
                break;
            case 8:
                int key_val;
                cout<<"Enter the key you want to search: ";
                cin >> key_val;
                serch(key_val);
            case 9:
                int key_va;
                cout<<"Enter the key you want to search: ";
                cin >> key_va;
                serch_befor(key_va);
            case 10:
                display_circular();
            case 11:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}