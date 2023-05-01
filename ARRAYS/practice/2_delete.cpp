#include<iostream>
using namespace std;



int delEle(int *arr,int n,int pos){
    int idx=pos-1;
    for(int i=idx;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    return n-1;
}
void printArr(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[5]={1,2,3,4,5};
    printArr(arr,5);
    delEle(arr,5,4);
    printArr(arr,4);
    return 0;
}