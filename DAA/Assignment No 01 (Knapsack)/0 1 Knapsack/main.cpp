#include <bits/stdc++.h>
using namespace std;

int knapsack(int cap, int n, int v[], int w[])
{
    int knap[n + 1][cap + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            if (i == 0 || j == 0)
                knap[i][j] = 0;
            else if (w[i - 1] <= cap)
                knap[i][j] = max(v[i - 1] +
                                     knap[i - 1][j - w[i - 1]],
                                 knap[i - 1][j]);
            else
                knap[i][j] = knap[i - 1][j];
        }
    }
    return knap[n][cap];
}

int main()
{
    cout << "Enter the numer of weights :";
    int n;
    cin >> n;
    cout << "\nEnter the values :";
    int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "\nEnter the weights :";
    int w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    cout << "\nEnter the knapsack weight :";
    int cap;
    cin >> cap;
    cout << "\nAnswer :" << knapsack(cap, n, v, w) << "\n";
}