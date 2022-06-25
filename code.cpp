        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;



void solve(void){
    ll n, xf, xs, yf, ys;
    xf = xs = yf = ys = -1;
    cin >> n;
    vector<ll> v(n);
    rpt(n)
        cin >> v[i];

    bool flag = false;

    int i;
    for(i = 0; i < n-1; i++)
        if(v[i] == v[i+1]){
            
            if(!flag){
                flag = true;
                xf = i;
                xs = i+1;
            }
            else
                xs = i+1;
        }
        else if(flag)
            break;

    flag = false;

    for(int j = n-1; j > i-1; j--)
        if(v[j] == v[j-1]){
            if(!flag){
                flag = true;
                yf = j;
                ys = j+1;
            }
            else
                ys = j+1;
        }
        else if(flag)
            break;
        
    cout << xf << " " << xs << " " << yf << " " << ys;

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


