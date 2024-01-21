#include<iostream>
using namespace std;
struct Array
{
    int A[10];
    int size;
    int length;

};
void display(Array *arr){
    cout<<"The element innthe array are "<<endl;
    for(int i =0;i<arr->length;i++){
        cout<<arr->A[i]<<endl;

    }
}
void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;

}
int LinearSearch(Array *arr,int key){
    for(int i=0;i<arr->length;i++){
        if(key==arr->A[i]){
            // swap(&arr->A[i],&arr->A[i-1]); transposition
            // swap(&arr->A[i],&arr->A[0]); move to head
            return i;
        }
    }
    return -1;

}
void initializeArray(struct Array *arr, int elements[], int size, int length) {
    for (int i = 0; i < length; i++){
        arr->A[i] = elements[i];
        arr->size = size;
        arr->length = length;
    }
}
int main(){
    struct Array arr;
    int elements[]={2,4,6,8,10};
    int size=10;
    int length =5;
    initializeArray(&arr,elements,size,length);
    cout<<LinearSearch(&arr,6)<<endl;
    display(&arr);
    return 0;

}
