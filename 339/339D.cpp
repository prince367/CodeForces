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
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll power(ll x,ll n){if(n==0)return 1;if(n%2)return x*power(x*x,(n-1)/2);return power(x*x,n/2);}
ll powerm(ll x,ll n){if(n==0)return 1;if(n%2)return (x*powerm((x*x)%MOD,(n-1)/2))%MOD;return powerm((x*x)%MOD,n/2);}
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int treee[4*(1<<18)];
int n;
vector<int> v;
void build(int node,int start,int end,int lvl)
{
	if(start==end)
	{
		treee[node]=v[start];
		return;
	}
	int mid=(start+end)/2;
	build(2*node,start,mid,lvl^1);
	build(2*node+1,mid+1,end,lvl^1);
	if(lvl)
	{
		treee[node]=treee[node*2]|treee[node*2+1];
	}
	else
	{
		treee[node]=treee[node*2]^treee[node*2+1];
	}
}
int new_value;
void update(int node,int start,int end,int lvl,int pos)
{
	if(start==end)
	{
		treee[node]=new_value;
		return;
	}
	int mid=(start+end)>>1;
	if(pos<=mid)
	{
		update(node*2,start,mid,lvl^1,pos);
	}
	else
	{
		update(node*2+1,mid+1,end,lvl^1,pos);
	}
	if(lvl)
	{
		treee[node]=treee[node*2]|treee[node*2+1];
	}
	else
	{
		treee[node]=treee[node*2]^treee[node*2+1];
	}
}
int main()
{

    //kiimati 4 line for sublime text
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);//FAST
    int N,M;cin>>N>>M;
    int a;
    n=1<<N;
    for(int i=0;i<n;i++)
    {
    	cin>>a;
    	v.pb(a);
    }
    build(1,0,n-1,N&1);
    while(M--)
    {
    	int p,b;cin>>p>>b;
    	new_value=b;
    	update(1,0,n-1,N&1,p-1);
    	cout<<treee[1]<<"\n";
    }
    return 0;
}