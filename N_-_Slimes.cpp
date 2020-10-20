/*
*    @Date    : 2020-10-12 00:00:03
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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0, prev = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] += prev;
        prev = v[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, INTMAX_MAX));

    auto sum = [&](int l, int r) -> int {
        if (l == 0)
            return v[r];
        else
            return v[r] - v[l - 1];
    };
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
            {
                for (int k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum(i, j));
            }
        }
    }
    cout << dp[0][n - 1];
    return 0;
}
