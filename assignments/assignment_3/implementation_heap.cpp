#include <iostream>

using namespace std;

void Insert(int A[], int key, int i) {
    int temp = A[i];
    A[i] = key;

    while (i > 0 && temp > A[i % 2 == 0 ? (i / 2) - 1 : i / 2]) {
        A[i] = A[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    A[i] = temp;
}

void CreateHeap(int A[], int n) {
    for (int i = 0; i < n; i++) {
        Insert(A, A[i], i);
    }
}

void CreateInplaceHeap(int A[], int n) {
    for (int i = 0; i < n; i++) {
        Insert(A, A[i], i);
    }
}

void PrintArray(int A[], int n, char c) {
    cout << c << ": [";
    for (int i = 0; i < n; i++) {
        cout << A[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {

    cout << "Create Heap" << endl;
    int b[] = {10, 20, 30, 25, 5, 40, 35};
    PrintArray(b, sizeof(b) / sizeof(b[0]), 'b');

    int v[sizeof(b) / sizeof(b[0])]; // Using array instead of vector
    CreateHeap(v, sizeof(b) / sizeof(b[0]));
    PrintArray(v, sizeof(v) / sizeof(v[0]), 'v');

    cout << "Inplace Insert" << endl;
    int c[sizeof(b) / sizeof(b[0])]; // Using array instead of vector
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++) {
        c[i] = b[i];
    }
    CreateInplaceHeap(c, sizeof(c) / sizeof(c[0]));
    PrintArray(c, sizeof(c) / sizeof(c[0]), 'c');

    return 0;
}
