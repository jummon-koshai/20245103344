#include <iostream>
#include <algorithm>
using namespace std;

void Merge(int A[], int start, int mid, int End)
{
    int len1 = mid - start + 1;
    int len2 = End - mid;
    int leftArr[len1], rightArr[len2];

    for(int i = 0; i < len1; i++)
    {
        leftArr[i] = A[start + i];
    }
    for(int j = 0; j < len2; j++)
    {
        rightArr[j] = A[mid + 1 + j];
    }
    int x = 0, y = 0, k = start;
    while(x < len1 && y < len2)
    {
        if(leftArr[x] <= rightArr[y])
        {
            A[k] = leftArr[x];
            x++;
        }
        else
        {
            A[k] = rightArr[y];
            y++;
        }
        k++;
    }
    while(x < len1)
    {
        A[k] = leftArr[x];
        x++;
        k++;
    }
    while(y < len2)
    {
        A[k] = rightArr[y];
        y++;
        k++;
    }
}
void mergeSort(int A[], int start, int End)
{
    if(start < End)
    {
       int mid =  start + (End - start)/2;
       mergeSort(A, start, mid);
       mergeSort(A, mid + 1, End);
       Merge(A, start, mid, End);
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
    mergeSort(A, 0, n - 1);
    cout << "Sorted array: ";
    printArray(A, n);
    return 0;
}
