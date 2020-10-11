/*
*    @Date    : 2020-10-11 11:22:51
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
    for (auto &i : v)
        cin >> i;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int a = 0; a < n; a++)
        for (int i = 0, j = a; j < n; j++, i++)
            if (i == j)
                dp[i][j] = v[i];
            else
                dp[i][j] = max(v[j] - dp[i][j - 1], v[i] - dp[i + 1][j]);
    cout << dp[0][n - 1];
    return 0;
}
