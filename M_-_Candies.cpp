/*
*    @Date    : 2020-10-20 09:14:01
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
const int mod = 1e9 + 7;

signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j > v[i - 1])
                dp[i][j] = dp[i - 1][j] % mod - dp[i - 1][j - v[i - 1] - 1] % mod + dp[i][j - 1] % mod;
            else
                dp[i][j] = dp[i - 1][j] % mod + dp[i][j - 1] % mod;
            dp[i][j] %= mod;
        }
    }
    if (k)
    {
        int a = dp[n][k] - dp[n][k - 1];
        if (a < 0)
            a += mod;
        cout << a;
    }
    else
        cout << dp[n][k];
    return 0;
}
