/*
*    @Date    : 2020-09-30 10:00:26
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

set<int> vis;
map<int, vector<int>> graph;

int dfs(int i, vector<int> &dp)
{
    if (dp[i] != -1)
        return dp[i];
    int ans = 0;
    vis.insert(i);
    if (graph[i].empty())
        return dp[i] = 0;
    for (auto &child : graph[i])
        if (vis.find(child) == vis.end())
            ans = max(ans, dfs(child, dp));
    vis.erase(i);
    return dp[i] = ans + 1;
}

signed main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        graph[i];

    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
    }
    vector<int> dp(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (vis.find(i) == vis.end())
            dfs(i, dp);
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}
