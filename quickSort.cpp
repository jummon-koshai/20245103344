#include <iostream>
#include <algorithm>
using namespace std;

int partitionJ(int A[], int low, int high)
{
    int pivot = A[high];
    int j = high;
    int i = low - 1;
    while(true)
    {
        do
        {
            i++;
        }
        while(A[i] < pivot);
        {
            do
            {
                j--;
            }
            while(j >= low && A[j]>pivot);
            if(i >= j)
            {
                break;
            }
            swap(A[i], A[high]);
        }
    }
    swap(A[i], A[high]);
    return i;
}
void quickSort(int A[], int low, int high)
{
    if(low < high)
    {
        int pi = partitionJ(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}
void printArray(int A[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}
int main()
{
    int A[] = {3, 12, 7, 6, 22, 1, 17, 33};
    int n = sizeof(A) / sizeof(A[0]);
    quickSort(A, 0, n - 1);
    cout << "Sorted array: ";
    printArray(A, n);
    return 0;
}
