/**********************/
/* Mahabub Rahman     */
/* Cse 10th           */
/* Comilla University */
/**********************/

#include<bits/stdc++.h>
using namespace std;
#define       ll                  long long int
#define       veci                 vector<int>
#define       vecl                 vector<long long int>
#define       pb                   push_back
#define       newline cerr << endl
#define       pii                  pair<int, int>
#define       F                    first
#define       S                    second
#define       nl                   "\n"
#define       all(v)               v.begin(), v.end()
///============ CONSTANT ===============///
#define mx9   1000000007
#define mx5   200005
#define inf   1<<30                                           //infinity value
#define eps   1e-9
#define mod   mx9
///=============== Debugging ============================///
#ifndef ONLINE_JUDGE
#define       debug(x) cout << #x << " = " << x << endl
#define       debug2(x, y)             cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define       debug3(x, y, z)          cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define       debug4(a, b, c, d)       cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#endif
void init_code()
{
    ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif    
}
const int N = 2e5+5;
ll a[N], dp[N], sum[N];
vector<int> g[N];
void dfs(int u, int p)
{
    sum[u] = a[u];
    for(auto v: g[u])
    {
        if(v == p) continue;
        dfs(v, u);
        sum[u] += sum[v];
        dp[u] += sum[v] + dp[v];
    }
}
ll ans = 0LL;
void dfs2(int u, int p)
{
    ans = max(ans, dp[u]);
    for(auto v: g[u])
    {
        if(v == p) continue;
        ll newCost = dp[u]-dp[v]-sum[v];
        ll newSum = sum[u]-sum[v];
        dp[v] += newCost + newSum;
        sum[v] += newSum;
        dfs2(v, u);
    }
}
int main()
{
    init_code();
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, -1);
    dfs2(1, -1);
     
     cout << ans << nl;
return 0;
}
