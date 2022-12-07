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
ll a[N], sz[N], dp[N], n;
vector<int> g[N];
void calc(int u, int p)
{
    sz[u] = 1;
    for(auto v: g[u])
    {
        if(v == p) continue;
        calc(v, u);
        sz[u]+=sz[v];
    }
}
ll dfs(int u, int p)
{
    dp[u] = 0;
    //debug3(u, dp[u].F, dp[u].S);
    for(auto v: g[u])
    {
        if(v == p) continue;
        dp[u] = (((dp[u]-dfs(v, u))%mod)+mod)%mod;
    }
    dp[u] = (((dp[u]+a[u]*sz[u])%mod)+mod)%mod;
    return dp[u];
}
ll ans = 0LL;
void dfs2(int u, int p, ll sum)
{
    ll temp = dp[u];
    ans = (((ans + dp[u] + sum)%mod)+mod)%mod;
    ans = (((ans + a[u]*(n-sz[u]))%mod)+mod)%mod;
    for(auto v: g[u])
    {
        if(v == p) continue;
        temp = (((temp-a[u]*sz[v])%mod)+mod)%mod;
        temp = (((temp + dp[v])%mod)+mod)%mod;
        ll k = (((-(temp+sum+a[u]*(n-sz[u])))%mod)+mod)%mod;
        dfs2(v, u, k);
        temp = (((temp + a[u]*sz[v])%mod)+mod)%mod;
        temp = (((temp - dp[v])%mod)+mod)%mod;
    }
}
int main()
{
    init_code();
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    calc(1, -1);
    dfs(1, -1);
    dfs2(1, -1, 0);
    //debug2(dp[1].F, dp[1].S);
    cout << ans % mod << nl;
return 0;
}
