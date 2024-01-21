#include <iostream>
using namespace std;
void display(int A[], int n){
    for (int i = 0; i < n; i++){
        cout << A[i] <<",";
    }
    cout<<endl;
}
void swap(int* x, int* y){
    int temp;
    temp= *x;
    *x = *y;
    *y = temp;
}
void BubbleSort(int A[], int n){
    int flag = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (A[j] > A[j + 1]){
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0){
            return;
        }
    }
}
void InsertionSort(int A[],int n){
    for(int i=1;i<n;i++){
        int j,x;
        j=i-1;
        x=A[i];
        while(j>-1&&A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}
void SelectionSort(int A[],int n){
    for(int i=0;i<n-1;i++){
        int k,j;
        for(j=k=i;j<n;j++){
            if(A[j]<A[k]){
                k=j;
            }
        }
        swap(&A[i],&A[k]);
    }
}
int main() {
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4,2};
    int n = sizeof(A) / sizeof(A[0]);
    display(A,n);
    cout<<"Bubble sort"<<endl;
    BubbleSort(A, n);
    display(A, n);
    cout<<"Insertion sort"<<endl;
    InsertionSort(A,n);
    display(A, n);
    cout<<"Selection sort"<<endl;
    SelectionSort(A,n);
    display(A,n);
    return 0;
}
