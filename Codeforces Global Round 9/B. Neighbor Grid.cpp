/* https://codeforces.com/problemset/problem/1375/B */
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

bool inline chkCorners(vector<vll> grid) {
    ll n = grid.size(), m = grid[0].size();
    return grid[0][0] <= 2 && grid[n-1][0] <= 2 && grid[0][m-1] <= 2 && grid[n-1][m-1] <= 2;
}

bool inline chkBorders(vector<vll> grid) {
    ll n = grid.size(), m = grid[0].size();
    
    for(ll i = 0; i < m; i++)
        if(grid[0][i] > 3 || grid[n - 1][i] > 3)
            return false;

    for(ll i = 0; i < n; i++)
        if(grid[i][0] > 3 || grid[i][m - 1] > 3)
            return false;

    return true;
}

bool inline chkGrid(vector<vll> grid) {
    ll n = grid.size(), m = grid[0].size();
    for(auto x : grid)
        for(auto y : x)
            if(y > 4) 
                return false;
    return true;
}

void solve(void){
    ll n, m; cin >> n >> m;
    
    vector<vll> grid(n, vll(m)); 
    rpt(i, 0, n) { 
        rpt(j, 0, m) { 
            cin >> grid[i][j];
        }
    }

    bool flag = chkCorners(grid);
    flag &= chkBorders(grid);
    flag &= chkGrid(grid);

    cout << (flag ? "YES" : "NO");
    nl;

    if(flag) {
        rpt(i, 0, n) {
            rpt(j, 0, m)
                if((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i ==  n - 1 && j == m - 1))
                    cout << "2 ";
                else if(i == 0 || i == n - 1 || j == 0 || j == m - 1)
                    cout << "3 ";
                else
                    cout << "4 ";
            nl;
        }
    }
    // print(grid);
    // nl;
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
