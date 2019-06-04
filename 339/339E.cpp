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
int A[10001];
vector<pii> ans;
int n;
int check()
{
	for(int i=0;i<n;i++)
	{
		if(A[i]!=i+1)
		{
			return 0;
		}
	}
	return 1;
}
int solve(int K)
{
	if(check()) return 1;
	if(K==0)
	{
		return 0;
	}
	vector<int> p;
	p.pb(0);
	for(int i=1;i<n-1;i++)
	{
		if(abs(A[i]-A[i-1])!=1 or abs(A[i]-A[i+1])!=1)
		{
			p.pb(i);
			//cout<<i<<" ";
		}
	}
	p.pb(n-1);
	for(int i=0;i<p.size();i++)
	{
		for(int j=i+1;j<p.size();j++)
		{
			reverse(A+p[i],A+p[j]+1);
			if(solve(K-1))
			{
				if(check())
				{
					ans.pb({p[i],p[j]});
					//cout<<i<<" "<<j<<"\n";
					return 1;
				}
			}
			reverse(A+p[i],A+p[j]+1);
		}
	}
	return 0;
}
int32_t main()
{

    //kiimati 4 line for sublime text
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);//FAST
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>A[i];
    }
    solve(3);
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)
    {
    	cout<<ans[i].ff+1<<" "<<ans[i].ss+1<<"\n";
    }
    return 0;
}