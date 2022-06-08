        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, k, w = 0;
    cin >> n >> k;

    string s;
    cin >> s;

    rpt(k)
        w += (s[i] == 'W');

    ll ans = w;

    for(int i = k; i < n; i++, w += (s[i] == 'W') - (s[i-k] == 'W'))
        ans = min(ans, w);
    
    cout << ((ans < 0) ? 0 : ans) << "\n";

}

int main() {
    srand(time(0));

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    #ifdef TESTCASE
        cin>>t;
        T=t;
        #else
        t = 1;
    #endif

    while(t--) 
        solve();

    return 0;
}
