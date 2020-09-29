/*
*    @Date    : 2020-09-29 22:37:43
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
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < t.size(); j++)
        {
            if (s[i] == t[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    vector<char> res(dp[s.size()][t.size()]);
    int p = res.size();
    for (int i = s.size(), j = t.size(); i > 0 and j > 0;)
    {
        if (s[i - 1] == t[j - 1])
        {
            res[--p] = s[i - 1];
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            --i;
        else
            --j;
    }
    for (auto &i : res)
        cout << i;
    return 0;
}
