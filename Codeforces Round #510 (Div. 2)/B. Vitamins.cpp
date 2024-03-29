/* https://codeforces.com/contest/1042/problem/B */
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
// #define TESTCASE
#define SIEVE_SIZE                ((ll)(1e5))
/*_________________________________________________________________________________________________________________________________________*/

template<class T>
T inline max(T a, T b, T c, T d = ninf, T e = ninf);
template<class T>
T inline min(T a, T b, T c, T d = inf, T e = inf);
template<class T>
void inline print(vector<T> v);
template<class T>
void inline print(vector<vector<T>> v);

bitset<SIEVE_SIZE> isComposit;
void setSieve();

set<ll> allPrimes;
void storePrimes();
/*_________________________________________________________________________________________________________________________________________*/
/*_________________________________________________________________________________________________________________________________________*/

void init(){

    return;
}

bool allVit(vector<ll> &tgt) {
    rpt(i, 0, 3) if(tgt[i] == 0) return false;
    return true;
}

int idx(vector<ll> &arr) {
    ll idx = 0; 
    rpt(i, 0, 3) idx += arr[i] * pow(2, i);
    return idx;
}

ll f(vector<ll> &arr, vector<string> &vit, vector<vector<ll>> &dp, ll ind, vector<ll> tgt) {
    debug(ind, tgt);
    if(allVit(tgt)) return 0;
    if(ind == 0) { 
        for(char x : vit[0]) tgt[x - 'A'] = 1;
        if(allVit(tgt)) return arr[0];
        else return inf;
    }

    if(dp[ind][idx(tgt)] != inf) return dp[ind][idx(tgt)];

    ll nottake = f(arr, vit, dp, ind - 1, tgt);
    
    for(char x : vit[ind]) tgt[x - 'A'] = 1;
    ll take = arr[ind] + f(arr, vit, dp, ind - 1, tgt);
    
    return dp[ind][idx(tgt)] = min(take, nottake);
    
}

void solve(void){
    
    ll n; cin >> n;
    vll arr(n);
    vector<string> vit(n);
    rpt(i, 0, n)
        cin >> arr[i] >> vit[i];

    vector<ll> tgt(3, 0);
    vector<vector<ll>> dp(n, vector<ll> (8, inf));
    ll ans = f(arr, vit, dp, n - 1, tgt);
    cout << (ans == inf ? -1 : ans);
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

    while(t--) 
        solve();

    return 0;
}

/*_________________________________________________________________________________________________________________________________________*/

template<class T>
T inline max(T a, T b, T c, T d, T e){
    return max(max(max(a, b), max(c, d)), e);
}

template<class T>
T inline min(T a, T b, T c, T d, T e){
    return min(min(min(a, b), min(c, d)), e);
}

template<class T>
void inline print(vector<T> v){
    for(auto x : v)
        cout << x << " ";
}

template<class T>
void inline print(vector<vector<T>> v){
    for(auto x : v){
        for(auto y : x)
            cout << y << " ";
        nl;
    }
}

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
