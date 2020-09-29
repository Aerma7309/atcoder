/*
*    @Date    : 2020-09-26 17:30:34
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
    vector<int> v(n, 0), dp(n, INT_MAX);
    for (auto &i : v)
        cin >> i;
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= 2; j++)
            if (i - j >= 0)
                dp[i] = min(dp[i], dp[i - j] + abs(v[i] - v[i - j]));
    }
    cout << dp[n - 1];
    return 0;
}
