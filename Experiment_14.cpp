//Write a program to solve the 0/1 Knapsack problem using Dynamic Programming.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, capacity;

    printf("\nEnter number of items: ");
    cin >> n;

    vector<int> profit(n), weight(n);

    printf("\nEnter profit and weight of all items in one go: ");
    for (int i = 0; i < n; i++)
        cin >> profit[i] >> weight[i];

    printf("\nEnter knapsack capacity: ");
    cin >> capacity;

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (weight[i - 1] <= w)
                dp[i][w] = max(profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("\nMaximum profit using 0/1 knapsack: %d\n", dp[n][capacity]);

    return 0;
}
//Name- Hari krishna k
// Branch - CSDA
//Roll no. - 25/DA/028