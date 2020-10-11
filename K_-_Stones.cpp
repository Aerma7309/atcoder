/*
*    @Date    : 2020-10-11 08:22:00
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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    vector<bool> dp(k + 1, false);
    for (int i = 1; i <= k; i++)
        for (int j = 0; j < n; j++)
            if (i - v[j] < 0)
                break;
            else
                dp[i] = (not dp[i - v[j]]) or dp[i];
    cout << (dp[k] ? "First" : "Second");
    return 0;
}
