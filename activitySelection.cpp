#include <iostream>
#include <algorithm>
using namespace std;

struct Activity{int start, finish;} ;
bool activityCompare (Activity s1, Activity s2)
{
    return (s1.finish < s2.finish);
}
void printMaxActivities(Activity A[], int n)
{
    sort(A, A + n, activityCompare);
    cout << "Following activities are selected: ";
    int i = 0;
    cout << "(" << A[i].start << ", " << A[i].finish << ")";
    for(int j = 1; j < n; j++)
    {
        if(A[j].start >= A[i].finish)
        {
            cout << ", (" << A[j].start << ", " << A[j].finish << ")";
            i = j;
        }
    }
}
int main()
{
    Activity A[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(A) / sizeof(A[0]);
    printMaxActivities(A, n);
}

