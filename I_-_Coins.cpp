/*
*    @Date    : 2020-10-10 06:34:09
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
    vector<double> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = p[i] * dp[i - 1][j - 1] + (1 - p[i]) * dp[i - 1][j];
    cout << setprecision(10) << dp[n][n / 2 + 1];
    return 0;
}
