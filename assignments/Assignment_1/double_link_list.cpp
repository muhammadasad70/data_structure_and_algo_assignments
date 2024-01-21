#include<iostream>
using namespace std;
struct Node{
    int marks;
    int id;
    struct Node *next;
    struct Node *previous;

};
Node *next=NULL;
Node *previous=NULL;
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
    cout<<k->id;
    return k;
}
void insert_at_first(){
    int marks;
    int id;
    cout<<"Enter the marks of the student :"<<endl;
    cin>>marks;
    cout<<"Enter the id of the student :"<<endl;
    cin>>id;
    Node *currrent_node=new Node;
    currrent_node->marks=marks;
    currrent_node->id=id;
    if(first==NULL){
        first=last=currrent_node;
    }
    else{
        currrent_node->next=first;
        first->previous=currrent_node;
        first=currrent_node;
        currrent_node->previous=NULL;
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
    if(first==NULL){
        first=last=current_node;
    }
    else{
        last->next=current_node;
        current_node->previous=last;
        last=current_node;
    }

}
void insert_after_specific(int key){
    Node *p=serch(key);
    Node *current_node=new Node;
    if(p==NULL){
        cout<<"Sorry the not found at the given index:"<<endl;
    }
    else if(p==last){
        insert_at_end();
    }
    else{

        int marks;
        int id;
        cout<<"Enter the marks of the student :"<<endl;
        cin>>marks;
        cout<<"Enter the id of the student :"<<endl;
        cin>>id;
        current_node->marks=marks;
        current_node->id=id;
        current_node->next=p->next;
        current_node->previous=p;
        p->next->previous=current_node;
        p->next=current_node;

    }

}
void insert_befor_specific(int key){
    Node *p=serch(key);
    Node *current_node=new Node; 
    if(p==first){
        insert_at_first();
    }
    else{
        int marks;
        int id;
        cout<<"Enter the marks of the student :"<<endl;
        cin>>marks;
        cout<<"Enter the id of the student :"<<endl;
        cin>>id;
        current_node->marks=marks;
        current_node->id=id;
        Node *q=serch_befor(key);
        current_node->next=q->next;
        current_node->previous=q;
        q->next->previous=current_node;
        q->next=current_node;

    }
}
void delete_at_first(){
    Node *p=first;
    if(p==NULL){
        cout<<"Nothing to delete in this list"<<endl;
    }
    else{
        first=first->next;
        first->previous=NULL;
        delete p;
    }
}
void delete_at_last(){
    Node *p=first;
    if(p==NULL){
        cout<<"Nothing to delete in this list"<<endl;

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
        while (p->next->next!=NULL){
            p=p->next;
        }
        q=p->next;
        last=p;
        p->next=NULL;
        delete q;
        
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
        p->previous->next=p->next;
        p->next->previous=p->previous;
        delete p;

    }
}
void display(){
    Node *p=first;
    while(p!=NULL){
        cout<<"The marks of the student is: "<<p->marks<<endl;
        cout<<"The id of the student is: "<<p->id<<endl;
        p=p->next;
    }
}
void reverse_display(){
    Node *p=last;
    while (p!=NULL)
    {
        cout<<"The marks of the student is: "<<p->marks<<endl;
        cout<<"The id of the student is: "<<p->id<<endl;
        p=p->previous;
    }
    
}
void reverse_display_using_swap(struct Node*p){
    p=first;
    Node *temp;
    while (p!=NULL)
    {
        temp=p->next;
        p->next=p->previous;
        p->previous=temp;
        p=p->previous;
        if(p!=NULL&&p->next==NULL){
            first=p;
        }
    }
}
int main(){
    int choice;
    int key, x, y;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at First\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before Specific\n";
        cout << "4. Insert After Specific\n";
        cout << "5. Delete at First\n";
        cout << "6. Delete at Last\n";
        cout << "7. Delete Specific\n";
        cout << "8. Display\n";
        cout << "9. Search\n";
        cout << "10. For search_befor ";
        cout << "11. Recursive Display\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert_at_first();
                break;
            case 2:
                insert_at_end();
                break;
            case 3:
                cout << "Enter ID before which you want to insert: ";
                cin >> key;
                insert_befor_specific(key);
                break;
            case 4:
                cout << "Enter ID after which you want to insert: ";
                cin >> key;
                insert_after_specific(key);
                break;
            case 5:
                delete_at_first();
                break;
            case 6:
                delete_at_last();
                break;
            case 7:
                cout << "Enter ID to delete: ";
                cin >> key;
                delete_at_specific(key);
                break;
            case 8:
                display();
                break;
            case 9:
                cout << "Enter The you want to search: ";
                cin >> key;
                serch(key);
                break;
            case 10:
                cout << "Enter The you want to search: ";
                cin >> key;
                serch_befor(key);
                break;
            case 11:
                reverse_display();
                break;
            case 12:
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    }

    return 0;
}
