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
        char Top();
        bool empty();
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

bool stack::empty(){
    if(top == NULL){
        return true;
    }
    else{
        return false;
    }
}

Node* stack::getTop() {
    return top;
}

char stack::Top(){
    if(top){
        return top->data;
    }
    else {
        return -1;
    }
}

bool isbalancing(char *exp){
    stack *st = new stack();
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='('){
            st->push(exp[i]);
        }
        else if(exp[i]==')'){
            if(st->getTop() == NULL){
                delete st;
                return false;
            } else {
                st->pop();
            }
        }
    }
    if(st->getTop() == NULL){
        delete st;
        return true;
    }
    else{
        delete st;
        return false;
    }
}

bool check_paranthesis(char *exp){
    stack *st=new stack();
    char c;
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            st->push(exp[i]);
        }
        else if (exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(st->empty()){
                delete st;
                return false;
            }
            c = st->Top();
            if((c=='(' && exp[i]==')') || (c=='{' && exp[i]=='}') || (c=='[' && exp[i]==']')){
                st->pop();
            }
            else {
                delete st;
                return false;
            }
        }
    }
    bool result = st->empty();
    delete st;
    return result;
}

void stack::display(){
    Node *p=top;
    while (p!=NULL){
        cout<<"The data of the student is "<<p->data<<endl;
        p=p->next;
    }
}

int main(){
    char E[]="{[(a+b)*(a+c)]}";
    cout<<check_paranthesis(E)<<endl;
    return 0;
}
