#include <iostream>
using namespace std;
void SELECTION_SORT(int A[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min_j = i;
        int min_x = A[i];
        for(int j = i + 1; j < n; j++)
        {
            if(A[j] < min_x)
            {
                min_j = j;
                min_x = A[j];
            }
        }
        A[min_j] = A[i];
        A[i] = min_x;
    }
}
void PRINT_ARRAY(int A[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}
int main()
{
    int A[8] = {14, 33, 27, 10, 35, 19, 42, 44};
    SELECTION_SORT(A, 8);
    cout << "The sorted list of array is: ";
    PRINT_ARRAY(A, 8);
    cout << "\nJIMMYSUAVECONNOISSEUR" << endl;
    return 0;
}
