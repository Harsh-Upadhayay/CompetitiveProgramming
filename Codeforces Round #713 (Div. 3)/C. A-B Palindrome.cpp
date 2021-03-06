/* https://codeforces.com/problemset/problem/1512/C */
#include<bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
    #define debug(x...) 
    class Timer{};
#else
    #include "debug.h"
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
#define kill(x)                 {cout << x; nl; return;}
#define nl                      cout << "\n";
#define TESTCASE
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

bool inline isPallindrom(string s){
    rpt(i, 0, s.size())
        if(s[i] != s[s.size() - i - 1])
            return false;
    return true;
}

void solve(void){
    ll a, b; cin >> a >> b;
    string s; cin >> s;
    ll n = a + b;

    ll one = b - count_if(all(s), [](char ch){ return ch == '1';}),
       zero = a - count_if(all(s), [](char ch){ return ch == '0';});

    rpt(i, 0, n/2)
        if(s[i] != s[n - i - 1] && (s[i] == '?' || s[n - i - 1] == '?'))
            if(s[i] == '1')
                one--, s[n - i - 1] = '1';
            else if(s[n - i - 1] == '1')
                one --, s[i] = '1';
            else if(s[i] == '0')
                zero --, s[n - i - 1] = '0';
            else if(s[n - i - 1] == '0')
                zero --, s[i] = '0';

    rpt(i, 0, n/2)
        if(s[i] == '?')
            if(one > 1)
                one -= 2, s[i] = '1', s[n - i - 1] = '1';
            else if(zero > 1)
                zero -= 2, s[i] = '0', s[n - i - 1] = '0';

    if(n % 2) if (s[n / 2] == '?')  if(one > 0) {s[n/2] = '1'; one--;} else if(zero > 0) {s[n/2] = '0'; zero--;};


    debug(one, zero, s);
    if(one == 0 && zero == 0 && isPallindrom(s))
        cout << s;
    else 
        cout << "-1";

    nl;
}


/*_________________________________________________________________________________________________________________________________________*/
/*_________________________________________________________________________________________________________________________________________*/

int main() {
    Timer _;
    srand(time(0));
    #ifndef ONLINE_JUDGE
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
