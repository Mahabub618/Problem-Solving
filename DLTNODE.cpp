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

ll a[N], dp[N], sum[N], Gcd[N];

vector<int> g[N];

ll ans = 0LL;

void dfs(int u, int p)

{

    Gcd[u] = a[u];

    for(auto v: g[u])

    {

        if(v == p) continue;

        dfs(v, u);

        Gcd[u] = __gcd(Gcd[v], Gcd[u]);

    }

}

void dfs2(int u, int p, ll p_gcd)

{

    ll cur_ans = p_gcd;

    vector<ll> vv;

    //debug3(u, cur_ans, p_gcd);

    for(auto v: g[u])

    {

        if(v == p) continue;

        vv.pb(Gcd[v]);

        cur_ans += Gcd[v];

    }

    ans = max(ans, cur_ans);

    //debug2(u, ans);

    int sz = vv.size();

    vector<ll> pre(sz, 0), suf(sz, 0);

    for(int i=0; i<sz; i++)

    {

        if(i==0) pre[i] = vv[i];

        else pre[i] = __gcd(pre[i-1], vv[i]);

    }

    for(int i=sz-1; i>=0; i--)

    {

        if(i == sz-1) suf[i] = vv[i];

        else suf[i] = __gcd(suf[i+1], vv[i]);

    }

    // for(int i=0;i <sz; i++)

    // {

    //     debug3(i, pre[i], suf[i]);

    // }

    p_gcd = __gcd(p_gcd, a[u]);

    int i = 0;

    for(auto v: g[u])

    {

        if(v == p) continue;

        ll new_gcd = p_gcd;

        if(i == 0) new_gcd = __gcd(suf[i+1], new_gcd);

        else if(i == sz-1) new_gcd = __gcd(pre[i-1], new_gcd);

        else

        {

            ll temp = __gcd(pre[i-1], suf[i+1]);

            new_gcd = __gcd(temp, new_gcd);

        }

        dfs2(v, u, new_gcd);

        i++;

    }

}

int main()

{

    init_code();

    int t;

    cin >> t;

    while(t--)

    {

        

        int n;

        cin >> n;

        for(int i=1; i<=n; i++)

        {

            g[i].clear();

            Gcd[i] = 0;

        }

        for(int i=1; i<n; i++)

        {

            int u, v;

            cin >> u >> v;

            g[u].pb(v);

            g[v].pb(u);

        }

        for(int i=1; i<=n; i++) cin >> a[i];

        dfs(1, -1);

        ans = 0LL;

        dfs2(1, -1, 0LL);

        

        cout << ans << nl;

    }

return 0;

}

