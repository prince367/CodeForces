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
ll N, K, A[100005], prefix_sum[100005], suffix_sum[100005];

ll possible(ll start, ll end)
{
    ll total_operation = 0;

    ll less_than_start = lower_bound(A+1, A+N+1, start) - A;
    less_than_start--;
    total_operation += ((less_than_start * start) - prefix_sum[less_than_start]);
    ll more_than_end = upper_bound(A+1, A+N+1, end) - A;
    return total_operation += (suffix_sum[more_than_end] - ((N-more_than_end+1)*end));

}
bool check(ll diff)
{
    ll ans = LLONG_MAX;
    for(int i = 1; i <= N; i++)
    {
        ans = min(ans, possible(A[i], A[i] + diff));
        ans = min(ans, possible(A[i] - diff, A[i]));
        if(ans <= K)
            return true;
    }
    return false;
}
int32_t main()
{

    //kiimati 4 line for sublime text
    #ifndef ONLINE_JUDGE
    freopen("/home/prince367/Desktop/PRINCE/CODES/input.txt", "r", stdin);
    freopen("/home/prince367/Desktop/PRINCE/CODES/output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);//FAST
    cin>>N>>K;
    rep(i,1,N+1)
    {
        cin>>A[i];
    }
    sort(A+1,A+N+1);
    rep(i,1,N+1)
        prefix_sum[i] = prefix_sum[i-1]+A[i];
    per(i,1,N+1)
        suffix_sum[i] = suffix_sum[i+1]+A[i];

    ll lo = 0, hi = A[N] - A[1];
    while(lo < hi)
    {
        ll mid = (lo+hi)/2;
        if(check(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout<<lo<<"\n";
    return 0;
}
