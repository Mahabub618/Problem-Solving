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
vector<int> g[N];
int st_n, en_n, node, mx = 0;
int st[N], en[N];
void Find(int u, int p, int level)
{
    if(level > mx)
    {
        mx = level;
        node = u;
    }
    for(auto v: g[u])
    {
        if(v == p) continue;
        Find(v, u, level+1);
    }
}
void dfs(int u, int p, int level, int bit)
{
    if(bit)
    {
        st[u] = level;
        if(st[u] > mx)
        {
            mx = st[u];
            node = u;
        }
    }
    else en[u] = level;
    for(auto v: g[u])
    {
        if(v == p) continue;
        dfs(v, u, level+1, bit);
    }
}
int main()
{
    init_code();
    int n;
    cin >> n;
    for(int i=1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    Find(1, -1, 0);
    mx = 0;
    dfs(node, -1, 0, 1);
    dfs(node, -1, 0, 0);
    for(int i=1; i<=n; i++) cout << max(st[i], en[i]) << ' ';
    cout << nl;
     
return 0;
}
