#include <iostream>
#include <algorithm>
using namespace std;

struct Item {int value, weight;};
bool cmp (struct Item a, struct Item b)
{
    double r1 = (double)a.value/a.weight;
    double r2 = (double)b.value/b.weight;
    return r1 > r2;
}
double fractionalKnapsack (struct Item A[], int N, int Size)
{
    sort(A, A + Size, cmp);
    int curWeight = 0;
    double finalValue = 0.0;
    for (int i = 0; i < Size; i++)
    {
        if (curWeight + A[i].weight <= N)
        {
            curWeight += A[i].weight;
            finalValue += A[i].value;
        }
        else
        {
            int remain = N - curWeight;
            finalValue += A[i].value* ((double)remain/A[i].weight);
            break;
        }
    }
    return finalValue;
}
int main()
{
    int N = 60;
    Item A[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int Size = sizeof(A) / sizeof(A[0]);
    cout << "Max Profit earned: " << fractionalKnapsack(A, N, Size) << endl;
}
