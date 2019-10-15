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
vector<vector<int>> adj(1000001);
ll C[1000001][3];
int n;
vector<int> color = {0,1,2};
ll dfs(int v, int p, int k)
{
    ll sum = C[v][color[k%3]];
    for(auto u: adj[v])
    {
        if(u != p)
        {
            sum+=dfs(u, v, k+1);
        }
    }
    return sum;
}
vector<int> res(1000001);
void dfs1(int v,int p,int k)
{
    res[v] = color[k%3];
    for(auto u : adj[v])
    {
        if(u != p)
        {
            dfs1(u, v, k+1);
        }
    }
}
int32_t main()
{

    //kiimati 4 line for sublime text
    #ifndef ONLINE_JUDGE
    freopen("/home/prince367/Desktop/PRINCE/CODES/input.txt", "r", stdin);
    freopen("/home/prince367/Desktop/PRINCE/CODES/output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);//FAST
    cin>>n;
    rep(j,0,3)
    {
        for(int i = 1; i <= n; i++)
        {
            cin>>C[i][j];
        }
    }
    int a,b;
    rep(i,0,n-1)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int s;
    for(int i = 1; i <= n; i++)
    {
        if(adj[i].size() > 2)
        {
            return cout<<-1,0;
        }
        if(adj[i].size() == 1)
        {
            s = i;
        }
    }
    ll ans = LLONG_MAX;
    vector<int> min_per;
    do
    {
        ll x = dfs(s, -1, 0);
        if(x < ans)
        {
            ans = x;
            min_per = color;
        }
    }while(next_permutation(color.begin(),color.end()));
    cout<<ans<<"\n";
    color = min_per;
    dfs1(s, -1, 0);
    rep(i,1,n+1)
    {
        cout<<res[i]+1<<" ";
    }
    return 0;
}
