/*  */
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
#define inf                     ((ll)(1e9+5))
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

<<<<<<< HEAD

void solve(void){
    ll n; cin >> n;
    ll x; cin >> x;

    ll gcd = x, mmax = x; 
    rpt(i, 0, n - 1) {
        cin >> x;
        gcd = __gcd(gcd, x);
        mmax = max(mmax, x);
    }

    cout << mmax / gcd;

=======
class cmp
{
public:
    int operator() (pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    
    return a.first < b.first;
}
};
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         
        int n = grid.size(),
            m = grid[0].size();
        priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
        
        vector<vector<int>> dist(n, vector<int> (m, inf));
        
        int sx = source.first,
            sy = source.second,
            dx = destination.first,
            dy = destination.second;
        
        dist[sx][sy] = 0;
        
        if(grid[sx][sy] == 0 || grid[dx][dy] == 0) 
            return dist[dx][dy] == inf ? -1 : dist[dx][dy];
        
        pq.push({0, {sx, sy}});
        
        int delX[] = {-1, 0, 1, 0},
            delY[] = {0, 1, 0, -1};
        
        while(!pq.empty()) {
            
            int d = pq.top().first,
                x = pq.top().second.first,
                y = pq.top().second.second;
            pq.pop();
            
            debug(x, y, d);

            for(int i = 0; i < 4; i++) {
                
                int adjX = x + delX[i],
                    adjY = y + delY[i];
                
                if(adjX >= 0 && adjY >= 0 && adjX < n && adjY < m && grid[adjX][adjY] == 1) {
                    
                    if(dist[adjX][adjY] > dist[x][y] + 1)
                        dist[adjX][adjY] = dist[x][y] + 1,
                        pq.push({dist[x][y] + 1, {adjX, adjY}});
                    
                }
                
            }
            
        }
        print(dist);

        return dist[dx][dy] == inf ? -1 : dist[dx][dy];
    }
};


void solve(void){
    
    Solution obj;

    ll n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int> (m));
    rpt(i, 0, n)
        rpt(j, 0, m)
            cin >> grid[i][j];


    obj.shortestPath(grid, {0, 1}, {2, 2});

>>>>>>> 8c828aca40c6a4c51545ae31be163e92b62b1d3a
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
