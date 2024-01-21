#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class stack{
    private:
        Node *top;
    public:
        stack(){top=NULL;}
        void push(char x);
        int pop();
        Node* getTop();
        void display();
};

void stack::push(char x){
    Node *current_node=new Node;
    if(current_node==NULL){
        cout<<"The stack is full or stack is overflow"<<endl;
    }
    else{
        current_node->data=x;
        current_node->next=top;
        top=current_node;
    }
}
int stack::pop(){
    int x=-1;
    if(top==NULL){
        cout<<"The stack is empty:";
    }
    else{
        x=top->data;
        Node *t=top;
        top=top->next;
        delete t;
    }
    return x;
}
Node* stack::getTop() {
    return top;
}
int ispalindrome(char *exp){
    stack *st = new stack();
    char c;
    int check=-1;
    for(int i=0;i<strlen(exp);i++){
        st->push(exp[i]);
    }
    for(int i=0;i<strlen(exp);i++){
        c=st->pop();
        if(c!=exp[i]){
            check=0;
            break;
        }
    }
    if(check==0){
        return 0;

    }
    else{
        return 1;
    }

}
void stack::display(){
    Node *p=top;
    while (p!=NULL){
        cout<<"The data of the student is "<<p->data<<endl;
        p=p->next;
    }
}
int main(){
    char E[]="laal";
    cout<<ispalindrome(E)<<endl;
    return 0;
}
 