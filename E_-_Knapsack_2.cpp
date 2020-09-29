/*
*    @Date    : 2020-09-29 15:03:16
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
    int maxVal = 1000 * n;
    vector<vector<int>> dp(n + 1, vector<int>(maxVal + 1,INT_MAX));
    dp[0][0]=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= maxVal; j++)
        {
            if (j >=  val[i])
                dp[i][j] = min(dp[i-1][j], dp[i - 1][j - val[i]] + wt[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int ans = 0;
    for (int i = 0; i <= maxVal; i++)
        if (dp[n][i] <= w)
            ans = i;
    cout << ans;
    return 0;
}
