#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define ll long long

#define all(x) x.begin(), x.end()
ll BE(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a * 1LL);
        }
        a = (1LL * a * a);
        b = b >> 1;
    }
    return res;
}
ll mod = 1e9 + 7;
vector<vector<int>> adj;
vector<int> SIV;
vector<int> value;
void dfs(int node, int va)
{
    SIV[node] = 1;
    int st = va;
    if (node == 1)
    {
        st = va - 1;
    }
    else
        st = va - 2;
    for (auto x : adj[node])
    {
        if (SIV[x] == 0)
        {
            value[x] = st;

            dfs(x, va);
            st--;
        }
    }
    return;
}
void pro()
{

    int n, k;
    cin >> n >> k;
    adj.assign(n + 1, {});
    SIV.assign(n + 1, 0);
    value.assign(n + 1, 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    value[1] = k;
    for (int i = 1; i <= n; i++)
    {
        if (SIV[i] == 0)
        {
            dfs(i, k);
        }
    }
    ll ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= value[i];
        ans %= mod;
    }
    cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("ouput.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;

    ll count = 1;
    while (t--)
    {

        pro();
        count++;
    }
}