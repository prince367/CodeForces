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

int32_t main()
{

    //kiimati 4 line for sublime text
    #ifndef ONLINE_JUDGE
    freopen("/home/prince367/Desktop/PRINCE/CODES/input.txt", "r", stdin);
    freopen("/home/prince367/Desktop/PRINCE/CODES/output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);//FAST
    int n,m;cin>>n>>m;
    int A[n+1];
    rep(i,0,n)
    cin>>A[i];
    int B[n+2]={0};
    while(m--)
    {
        int l,r;cin>>l>>r;
        B[l-1]+=1;
        B[r]-=1;
    }
    int cur=0;
    rep(i,0,n)
    {
        cur+=B[i];
        B[i]=cur;
    }
    sort(B,B+n);
    sort(A,A+n);
    ll sum=0;
    rep(i,0,n)
    {
        sum=sum+(1LL*A[i])*(1LL*B[i]);
    }
    cout<<sum;
    return 0;
}
