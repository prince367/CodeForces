//PRINCE
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define ll long long int
typedef vector<ll> vll;
typedef vector<int> vii;

#define MOD 1000000007
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";

ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll power(ll x,ll n){if(n==0)return 1;if(n%2)return x*power(x*x,(n-1)/2);return power(x*x,n/2);}
ll powerm(ll x,ll n){if(n==0)return 1;if(n%2)return (x*powerm((x*x)%MOD,(n-1)/2))%MOD;return powerm((x*x)%MOD,n/2);}
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
set<pair<ll,int>> st;
int32_t main()
{

    //kiimati 4 line for sublime text
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);//FAST
    int n,m,d;cin>>n>>m>>d;
    vector<ll> A(n+1);
    rep(i,1,n+1)
    {
        cin>>A[i];
        st.insert({A[i],i});
    }
    vector<int> ans(n+1);
    int day = 0;
    while(!st.empty())
    {
        day++;
        int pos = st.begin()->second;
        st.erase(st.begin());
        ans[pos] = day;
        while(true)
        {
            auto high = st.lower_bound({A[pos]+d+1, 0});
            if(high == st.end())
                break;
            pos = high->second;
            st.erase(high);
            ans[pos] = day;
        }
    }
    cout<<day<<"\n";
    rep(i,1,n+1)
    cout<<ans[i]<<" ";
    return 0;
}
