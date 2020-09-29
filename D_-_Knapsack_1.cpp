/*
*    @Date    : 2020-09-29 14:29:28
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

#define int long long

signed main()
{
    int n, w;
    cin >> n >> w;
    vector<int> wt(n + 1), val(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> wt[i] >> val[i];
    vector<vector<int>> dp(n + 1, vector<int>(w + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (j >= wt[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i]] + val[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][w];
    return 0;
}
