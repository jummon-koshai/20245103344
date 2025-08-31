#include <iostream>
#include <algorithm>
using namespace std;

struct RodPiece{int length, profit;};
void rodcutting(RodPiece arr[], int n, int N)
{
int dp[n+1][N+1];
for(int i = 0; i <= n; i++)
    {
     for(int j = 0; j <= N; j++)
        {
         if(i == 0 || j == 0)
         {
             dp[i][j] = 0;
         }
         else if(arr[i-1].length <= j)
         {
             dp[i][j] = max(arr[i-1].profit+dp[i][j-arr[i-1].length], dp[i-1][j]);
         }
         else
            {
             dp[i][j] = dp[i-1][j];
            }
        }
    }
int res = dp[n][N];
int i = n;
int j = N;
int cuts[N];
int cutCount = 0;
while(i > 0 && res >0)
{
    if(dp[i][j] == dp[i-1][j])
    {
       i--;
    }
    else
    {
        cuts[cutCount++] = arr[i-1].length;
        res -= arr[i-1].profit;
        j -= arr[i-1].length;
    }
}
cout << "Maximum Obtainable Value = " << dp[n][N] <<endl;
cout << "Cut sizes: ";
for(int k = 0; k < cutCount; k++)
{
    cout << " " << cuts[k];
}
cout <<endl;
}
int main()
{
    RodPiece pieces[] = {{1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}};
    int n = sizeof pieces/sizeof(pieces[0]);
    int N = 8;
    rodcutting(pieces, n, N);
    return 0;
}
