/*  *//*  */
#include<bits/stdc++.h>
using namespace std;

#ifdef DarkLord
    #include "debug.h"
#else
    #define debug(x...) 
    class Timer{};
#endif

/*_________________________________________________________________________________________________________________________________________*/

#define ll                      long long int
#define ull                     unsigned ll
#define ld                      long double
#define p(x, y)                 pair<x, y> 
#define pb                      push_back
#define fi                      first
#define se                      second
#define lb                      lower_bound
#define ub                      upper_bound
#define vll                     vector<ll>
#define vvll                    vector<vector<ll>>
#define ninf                    ((ll)((-1)*1e18+5))
#define inf                     ((ll)(1e18+5))
#define MOD                     ((ll)(1e9+7))
#define nmin(v)                 *min_element(all(v))
#define nmax(v)                 *max_element(all(v))
#define rpt(i, begin, end)      for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(x)                  (x).begin(), (x).end() 
#define yes                     cout << "YES";
#define no                      cout << "NO";
#define nl                      cout << "\n";
#define kill(x)                 {cout << x << "\n"; return; }
#define SIEVE_SIZE                ((ll)(1e5))
/*_________________________________________________________________________________________________________________________________________*/

template <typename T>
ostream& operator<<(ostream &os, vector<T> &v) {
    for(T x : v) os << (x == inf ? -1 : x) << " ";
    return os;
}

template <typename T>
istream& operator>>(istream &is, vector<T> &v) {
    for(T &x : v) is >> x;
    return is;
}

template <typename T1, typename T2>
ostream& operator<<(ostream &os, pair<T1, T2> &x) {
    cout << "(" << x.fi << "," << x.se << ")";
    return os;
}

template <typename T>
istream& operator>>(istream &is, vector<vector<T>> &v) {
    for(auto &x : v) is >> x;
    return is;
}

template <typename T>
ostream& operator<<(ostream &os, vector<vector<T>> &v) {
    for(auto x : v) os << x << "\n";
    return os;
}


bitset<SIEVE_SIZE> isComposit;
void setSieve();

set<ll> allPrimes;
void storePrimes();
/*_________________________________________________________________________________________________________________________________________*/
/*_________________________________________________________________________________________________________________________________________*/

void init(){

    return;
}

struct nd {
    ll u, v, t;

    nd(ll _u, ll _v, ll _t) {
        u = _u;
        v = _v;
        t = _t;
    }
    nd(ll _v, ll _t) {
        v = _v;
        t = _t;
    }
};

ll fun(vector<nd> adj[], ll dst, vvll &dp, ll src, ll places) {
    debug(src, places);
    if(places == 0)
        return src == dst ? 0 : inf;

    if(dp[src][places] != -1)
        return dp[src][places];

    ll minT = inf;

    for(auto adjN : adj[src]) {

        minT = min(minT, 
                        adjN.t + fun(adj, dst, dp, adjN.v, places - 1));

    }

    return dp[src][places] = minT;
}

ll minAdj(vector<nd> adj[], vvll &dp, ll i) {

    ll n = -1, t = inf;

    for(auto adjN : adj[i]) {
        if(t > adjN.t) 
            t = adjN.t,
            n = adjN.v;
    }

    return n;
}

// #define TESTCASE
void solve(ll __T__){

    ll n, m, tim; cin >> n >> m >> tim;
    vector<nd> adj[n + 1];

    rpt(i, 0, m) {
        ll u, v, t; cin >> u >> v >> t;
        adj[u].push_back(nd(u, v, t));
    }

    // rpt(i, 1, n + 1) {
    //     cout << i << ": ";
    //     for(auto x : adj[i])
    //         cout << x.v << "," << x.t << "   ";
    //     cout << "\n";
    // }

    /* fun(src, place) -> minimum time to visit place number of showplaces from source. */

    /* 
    rpt(place, 1, n + 1) {
        if(fun(1, place) <= tim)
            cout << place;
    }
    */

    vvll dp(n + 1, vll(n + 1, -1));

    ll tgt = -1;
    rpt(place, n + 1, 0) {
        if(fun(adj, n, dp, 1, place) <= tim) { 
            tgt = place + 1;
            cout << place + 1 << "\n";
            break;
        }
    }

    if(tgt == -1)
        return;

    ll src = 1;
    while(tgt) {

        cout << src << " ";

        src = minAdj(adj, dp, src);

        tgt -= 1;
    } 

    nl;
    cout << dp;

    nl;
}


/*_________________________________________________________________________________________________________________________________________*/
/*_________________________________________________________________________________________________________________________________________*/

int main() {
    Timer _;
    srand(time(0));
    #ifdef DarkLord
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("err.txt","w",stderr);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    init();

    ll t = 1;

    #ifdef TESTCASE
        cin >> t;
    #endif

    rpt(i, 1, t + 1) 
        solve(i);

    return 0;
}

/*_________________________________________________________________________________________________________________________________________*/

void setSieve(){
    isComposit[0] = isComposit[1] = 1;
    for(long long i = 2; i*i <= SIEVE_SIZE; i++)
        if(isComposit[i] == 0)
            for(long long j = i*i; j <= SIEVE_SIZE; j += i)
                isComposit[j] = 1;

}

void storePrimes(){
    if(isComposit[2])
        setSieve();
    for(ll i = 2; i < SIEVE_SIZE; i++)
        if(!isComposit[i])
            allPrimes.insert(i);
}

/*_________________________________________________________________________________________________________________________________________*/

