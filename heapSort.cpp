#include <iostream>
using namespace std;

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int l = 2 * i + 1;
    int right = 2 * i + 2;
    int r = 2 * i + 2;
    if(l < N && arr[l] > arr[largest])
    {
        largest = l;
    }
    if(r < N && arr[r] > arr[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)
{
    for(int i = N / 2 - 1; i >= 0; i--)
    {
        heapify(arr, N, i);
    }
    for(int i = N - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
       cout << arr[i] << " "; 
    }
}
int main()
{
    int arr[]={14, 33, 27, 10, 35, 19, 42, 44};
    int N = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, N);
    cout << "The sorted list of array is: ";
    printArray(arr, N);
    cout<<"\nJIMMYSUAVECONNOISSEUR"<<endl;
}
