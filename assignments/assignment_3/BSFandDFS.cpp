
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(int x) {
    Node* t = new Node;
    if (t == nullptr) {
        cout << "Queue is Full" << endl;
    } else {
        t->data = x;
        t->next = nullptr;
        if (front == nullptr) {
            front = rear = t;
        } else {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue() {
    int x = -1;
    Node* t;
    if (front == nullptr) {
        cout << "Queue is Empty" << endl;
    } else {
        x = front->data;
        t = front;
        front = front->next;
        delete t;
    }
    return x;
}

bool isEmpty() {
    return front == nullptr;
}

void BFS(int G[][7], int start, int n) {
    int i = start, j;
    int visited[7] = {0};
    cout << i << " ";
    visited[i] = 1;
    enqueue(i);

    while (!isEmpty()) {
        i = dequeue();
        for (j = 1; j < n; j++) {
            if (G[i][j] == 1 && visited[j] == 0) {
                cout << j << " ";
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

void DFS(int G[][7], int start, int n) {
    static int visited[7] = {0};
    int j;

    if (visited[start] == 0) {
        cout << start << " ";
        visited[start] = 1;

        for (j = 1; j < n; j++) {
            if (G[start][j] == 1 && visited[j] == 0) {
                DFS(G, j, n);
            }
        }
    }
}

int main() {
    int G[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    cout << "BFS Traversal: ";
    BFS(G, 1, 7);

    cout << "\nDFS Traversal: ";
    DFS(G, 1, 7);

    return 0;
}



