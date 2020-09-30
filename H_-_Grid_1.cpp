/*
*    @Date    : 2020-09-30 10:48:25
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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> m(h, vector<char>(w));
    for (auto &i : m)
        for (auto &j : i)
            cin >> j;
    vector<vector<int>> dp(h, vector<int>(w, 0));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (m[i][j] != '#')
            {
                if (i == 0 and j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1];
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= mod;
            }
        }
    }

    cout << dp[h - 1][w - 1];
    return 0;
}
