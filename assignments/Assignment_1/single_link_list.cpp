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
    while (p!=NULL){
        if(key==p->id)
            return p;
        p=p->next;
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
void display(){
    Node *p=first;
    while(p!=NULL){
        cout<<"The marks of the student is: "<<p->marks<<endl;
        cout<<"The id of the student is: "<<p->id<<endl;
        p=p->next;
    }
}
void recursive_display(Node *p){
    if(p!=NULL){
        cout<<"The marks of the student is: "<<p->marks<<endl;
        cout<<"The id of the student is: "<<p->id<<endl;
        recursive_display(p->next);

    }

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
    Node *currrent_node=new Node;
    currrent_node->marks=marks;
    currrent_node->id=id;
    if(first==NULL){
        first=last=currrent_node;
    }
    else{
        currrent_node->next=first;
        first=currrent_node;
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
        last=current_node;
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
        Node *q=serch_befor(key);
        current_node->next=q->next;
        q->next=current_node;
        current_node->marks=marks;
        current_node->id=id;

    }
}
void insert_after_specific(int key){
    Node *p=serch(key);
    Node *current_node=new Node;
    if(p==last){
        insert_at_end();
    }
    else{
        
        int marks;
        int id;
        cout<<"Enter the marks of the student :"<<endl;
        cin>>marks;
        cout<<"Enter the id of the student :"<<endl;
        cin>>id;
        current_node->next=p->next;
        p->next=current_node;
        current_node->marks=marks;
        current_node->id=id;
    }
    
}
void delete_at_first(){
    Node *p=first;
    if(p==NULL){
        cout<<"Nothing to delete in this list"<<endl;
    }
    else{
        first=first->next;
        delete p;
    }
}
void delete_at_last(){
    Node *p=first;
    if(first==NULL){
        cout<<"Nothing in this to delete:"<<endl;
    }
    else if (first==last){
        p=first;
        first=last=NULL;
        delete p;
    }
    else{
        Node *q=new Node;
        q=first;
        while (q->next->next!=NULL){
            q=q->next;
        }
        last=q;
        last->next=NULL;
        q=q->next;
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
        Node *q=serch_befor(key);
        q->next=q->next->next;
        q=q->next;
        delete q;
    }
    
}
void reverse_link_list_by_sliding_pointer(Node *p){
    Node *q=NULL;
    Node *r=NULL;
    while (p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void recursive_reverse(Node *q,Node *p){
    if(p!=NULL){
        recursive_reverse(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}
void swap(int x,int y){
    if(x==y){
        return;
    }
    Node *currx=first;
    Node *prevx=NULL;
    while (currx && currx->id!=x)
    {
        prevx=currx;
        currx=currx->next;
    }
    Node *curry=first;
    Node *prevy=NULL;
    while (curry&&curry->id!=y)
    {
        prevy=curry;
        curry=curry->next;
    }
    if(!currx||!curry){
        return ;
    }
    if(currx!=first){
        prevx->next=curry;
    }    
    else{
        first=curry;
    }
    if(curry!=first){
        prevy->next=currx;
    }
    else{
        first=currx;
    }
    Node *temp=currx->next;
    currx->next=curry->next;
    curry->next=temp;
}
int main(){
    int choice;
    int key, x, y;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert in a List\n";
        cout << "2. Insert at First\n";
        cout << "3. Insert at End\n";
        cout << "4. Insert Before Specific\n";
        cout << "5. Insert After Specific\n";
        cout << "6. Delete at First\n";
        cout << "7. Delete at Last\n";
        cout << "8. Delete Specific\n";
        cout << "9. Reverse List By sliding pointer\n";
        cout << "10. Reverse List (Recursive)\n";
        cout << "11. Swap Nodes\n";
        cout << "12. Display\n";
        cout << "13. Recursive Display\n";
        cout << "14. For search";
        cout << "15. For search_befor ";
        cout << "16. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert_in_a_list();
                break;
            case 2:
                insert_at_first();
                break;
            case 3:
                insert_at_end();
                break;
            case 4:
                cout << "Enter ID before which you want to insert: ";
                cin >> key;
                insert_befor_specific(key);
                break;
            case 5:
                cout << "Enter ID after which you want to insert: ";
                cin >> key;
                insert_after_specific(key);
                break;
            case 6:
                delete_at_first();
                break;
            case 7:
                delete_at_last();
                break;
            case 8:
                cout << "Enter ID to delete: ";
                cin >> key;
                delete_at_specific(key);
                break;
            case 9:
                reverse_link_list_by_sliding_pointer(first);
                break;
            case 10:
                recursive_reverse(NULL, first);
                break;
            case 11:
                cout << "Enter IDs to swap: ";
                cin >> x >> y;
                swap(x, y);
                break;
            case 12:
                display();
                break;
            case 16:
                return 0; 
            case 13:
                recursive_display(first); 
                break;
            case 14:
                cout << "Enter The you want to search: ";
                cin >> key;
                serch(key);
                break;
            case 15:
                cout << "Enter The you want to search: ";
                cin >> key;
                serch_befor(key);
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    }

    return 0;
}
