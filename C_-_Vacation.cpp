/*
*    @Date    : 2020-09-29 14:02:56
*    @Author  : aerma7309 
*/

#include <bits/stdc++.h>
using namespace std;
int FastIO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(3));
    for (auto &i : m)
        for (auto &j : i)
            cin >> j;
    vector<vector<int>> dp(n, vector<int>(3, INT_MIN));
    dp[0] = m[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (j not_eq k)
                    dp[i][j] = max(dp[i - 1][k] + m[i][j], dp[i][j]);
            }
        }
    }
    cout << *max_element(dp[n - 1].begin(), dp[n - 1].end());
    return 0;
}
