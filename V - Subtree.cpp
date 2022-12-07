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
vector<int> g[N];
ll mod, dp[N], ans[N];
ll mul(ll a, ll b)
{
    return (a%mod * b%mod)%mod;
}
ll add(ll a, ll b)
{
    return (((a+b)%mod)+mod)%mod;
}
void dfs(int u, int p)
{
    dp[u] = 1LL;
    for(auto v: g[u])
    {
        if(v == p) continue;
        dfs(v, u);
        dp[u] = mul(dp[u], dp[v]+1);
    }
}
void dfs2(int u, int p, ll m)
{
    //debug3(u, p, m);
    vector<ll> vv;
    for(auto v: g[u])
    {
        if(v == p) continue;
        vv.pb(dp[v]);
    }
    ll sz = vv.size();
    ll pre[sz+1], suf[sz+1];
    pre[0] = 1LL, suf[sz] = 1LL;
    for(int i=0; i<sz; i++) pre[i+1] = mul(pre[i], vv[i]+1);
    for(int i=sz-1; i>=0; i--) suf[i] = mul(suf[i+1], vv[i]+1);
    ll n_prod = 1LL;
    int c = 0;
    for(auto v: g[u])
    {
        if(v == p) continue;
        n_prod = mul(pre[c], suf[c+1]);
        n_prod = mul(n_prod, m+1);
        ans[v] = mul(n_prod+1, dp[v]);
        c++;
        dfs2(v, u, n_prod);
    }
}
int main()
{
    init_code();
    int n;
    cin >> n >> mod;
    for(int i=1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, -1);
    ans[1] = dp[1];
    dfs2(1, -1, 0LL);
    for(int i=1; i<=n; i++) cout << ans[i] << nl;
return 0;
}
