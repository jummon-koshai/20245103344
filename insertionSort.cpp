#include<iostream>
using namespace std;
void INSERTION_SORT(int arr[], int n)
{
    int key, j=0;
    for(int i=2; i<=n; i++)
    {
       key=arr[i];
       j=i-1;
       while(j>=0 && arr[j]>key)
       {
           arr[j+1] = arr[j];
           j--;
       }
       arr[j+1] = key;
    }
}
void PRINT_ARRAY(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[8] = {14,33,27,10,35,19,42,44};
    INSERTION_SORT(arr,8);
    cout<<"The sorted list of array is: ";
    PRINT_ARRAY(arr, 8);
    cout<<"\nJIMMYSUAVECONNOISSEUR"<<endl;
}
