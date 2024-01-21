#include <iostream>
using namespace std;

const int size = 10;

struct Chain {
    int data;
    Chain*next = NULL;
};

Chain* table[size] = { NULL };

void insertHashing(int num) {
    int index = num % size;
    Chain* curr = new Chain;
    curr->data = num;
    curr->next = NULL;

    if (table[index] == NULL) {
        table[index] = curr;
    } else {
        Chain* p = table[index];
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = curr;
    }
}

void deleteHashing(int num) {
    int index = num % size;
    if (table[index] != NULL) {
        Chain* p = table[index];
        Chain* k = NULL;
        while (p != NULL && p->data != num) {
            k = p;
            p = p->next;
        }
        if (p != NULL && p->data == num) {
            if (k == NULL) {
                table[index] = p->next;
                delete p;
            } else {
                k->next = p->next;
                delete p;
            }
        }
    }
}

void display() {
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << ": ";
        Chain* p = table[i];
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    insertHashing(2);
    insertHashing(12);
    insertHashing(22);
    insertHashing(32);
    insertHashing(42);


    display();


    deleteHashing(22);


    display();

    return 0;
}

