#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int x) {
    Node* t = new Node;
    if (t == nullptr) {
        std::cout << "Stack is full" << std::endl;
        return;
    }
    t->data = x;
    t->next = top;
    top = t;
}

int pop() {
    if (top == nullptr) {
        std::cout << "Stack is Empty" << std::endl;
        return -1;
    }
    Node* t = top;
    int x = t->data;
    top = top->next;
    delete t;
    return x;
}

void Display() {
    Node* p = top;
    while (p != nullptr) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int isBalanced(char* exp) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')') {
            if (top == nullptr)
                return 0;
            pop();
        }
    }
    if (top == nullptr)
        return 1;
    else
        return 0;
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

int Eval(char* postfix) {
    int i = 0;
    int x1, x2, r = 0;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            x2 = pop();
            x1 = pop();
            switch (postfix[i]) {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            }
            push(r);
        }
    }
    return top->data;
}

int main() {
    char* postfix = "234*+82/-";
    int result = Eval(postfix);
    cout << "Result is " << result << endl;
    return 0;
}
