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

#define       pll                  pair<ll, ll>

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

const int N = 1e5+5;

vector<int> g[N];

int a[N], ans;

pii dp[N];

pii change(int x, pii p)

{

    if(x == 1) return p;

    if(x == -1) return {p.S, p.F};

    if(x == 2) return {p.F+1, p.S+1};

    if(x == -2) return {p.S+1, p.F+1};

}

void dfs(int u, int p)

{

    //debug(u);

    dp[u] = {0, -inf};

    vector<pii> pos, neg;

    for(auto v: g[u])

    {

        if(v == p) continue;

        dfs(v, u);

        pos.pb({dp[v].F, v});

        neg.pb({dp[v].S, v});

    }

    sort(pos.rbegin(), pos.rend());

    sort(neg.rbegin(), neg.rend());

    int sz = pos.size();

    if(sz >= 1)

    {

        dp[u].F = max(dp[u].F, pos[0].F);

        dp[u].S = max(dp[u].S, neg[0].F);

    }

    dp[u] = change(a[u], dp[u]);

    if(sz >= 2)

    {

        pii temp = {0, -inf};

        if(pos[0].S == neg[0].S)

        {

            temp.S = max(pos[0].F + neg[1].F, neg[0].F + pos[1].F);

        }

        else temp.S = pos[0].F + neg[0].F;

        temp.F = max(pos[0].F + pos[1].F, neg[0].F + neg[1].F);

        temp = change(a[u], temp);

        ans = max(ans, temp.F);

    }

    ans = max(ans, dp[u].F);

}

ll bigmod(ll a, ll b, ll m){if(b==0) return 1%m;ll x=bigmod(a, b/2, m);x=(x*x)%m;if(b%2==1)x=(x*a)%m;return x;}

int main()

{

    init_code();

    int t;

    cin >> t;

    while(t--)

    {

        int n;

        cin >> n;

        for(int i=1; i<=n; i++) g[i].clear();

        for(int i=1; i<n; i++)

        {

            int u, v;

            cin >> u >> v;

            g[u].pb(v);

            g[v].pb(u);

        }

        for(int i=1; i<=n; i++) cin >> a[i];

        if(n==1 and a[1] < 0) cout << (a[1]+mod)%mod << nl;

        else

        {

            ans = 0;

            dfs(1, -1);

           // debug(ans);

            cout << bigmod((ll)2, (ll)ans, mod) << nl;

        }

    }

     

return 0;

}

