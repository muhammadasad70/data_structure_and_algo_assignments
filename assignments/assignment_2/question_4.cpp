#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
};

Node* top = nullptr;

void push(char x) {
    Node* t = new Node;
    if (t == nullptr) {
        cout << "Stack is full" << endl;
        return;
    }
    t->data = x;
    t->next = top;
    top = t;
}

char pop() {
    if (top == nullptr) {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    Node* t = top;
    char x = t->data;
    top = top->next;
    delete t;
    return x;
}

void Display() {
    Node* p = top;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int pre(char x) {
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

char* InToPost(char* infix) {
    int i = 0, j = 0;
    char* postfix;
    int len = strlen(infix);
    postfix = new char[len + 2];

    while (infix[i] != '\0') {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            if (pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    while (top != nullptr)
        postfix[j++] = pop();

    postfix[j] = '\0';
    return postfix;
}

int main() {
    char* infix = "a+b*c-d/e";
    push('#');
    char* postfix = InToPost(infix);
    cout << postfix << " ";
    delete[] postfix;
    return 0;
}