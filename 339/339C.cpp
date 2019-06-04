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
string s;
vector<int>ans;
int m;
int dp(int x,int y,int cur,int step)
{
	if(step==m)
	{
		return 1;
	}
	bool p=0;
	if(step%2==0)
	{
		for(int i=1;i<11;i++)
		{
			if(s[i-1]=='1' and cur!=i and x+i>y)
			{
				int z=dp(x+i,y,i,step+1);
				if(z==1 and p==0)
				{
					p=1;
					ans.pb(i);
					break;
				}
			}
		}
	}
	else
	{
		for(int i=1;i<11;i++)
		{
			if(s[i-1]=='1' and cur!=i and y+i>x)
			{
				bool z=dp(x,y+i,i,step+1);
				if(z==1 and p==0)
				{
					ans.pb(i);
					p=1;
					break;
				}
			}
		}	
	}
	return p;
}
int32_t main()
{

    //kiimati 4 line for sublime text
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);//FAST
    cin>>s;
    cin>>m;
    if(dp(0,0,0,0))
    {
    	cout<<"YES\n";
    	for(int i=ans.size()-1;i>=0;i--)
    	{
    		cout<<ans[i]<<" ";
    	}
    }
    else
    {
    	cout<<"NO";
    }
    return 0;
}