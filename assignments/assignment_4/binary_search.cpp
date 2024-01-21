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
int RbinarySearch(int A[],int l,int h,int key){
    int mid;
    if(l<=h){
        mid=(l+h)/2;
        if(key==A[mid]){
            return mid ;
        }
        else if(key<A[mid]){
            return RbinarySearch(A,l,mid-1,key);

        }
        else{
            return RbinarySearch(A,mid+1,h,key);
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
    int elements[]={2,3,4,5,6};
    int size=10;
    int length =5;
    initializeArray(&arr,elements,size,length);
    cout<<RbinarySearch(elements,0,length-1,6)<<endl;
    display(&arr);
    return 0;

}
