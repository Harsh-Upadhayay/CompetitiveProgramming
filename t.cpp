        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, ans;
    cin >> n;

    map<ll, vector<ll>> tree;

    rpt(n-1){
        ll u, v;
        cin >> u >> v;
        if(tree.count(u))
            tree[u].pb(v);
        else{
            vector<ll> v;
            v.pb(u);
            tree[u] = v;
        }
    }
    for(auto x : tree){
        cout << x.first << " : ";
        for(auto y : x.second)
            cout << y << " ";
        cout << endl;
    }
    cout<<endl;

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


