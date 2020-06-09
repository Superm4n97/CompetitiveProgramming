#define pb push_back
#define ff first
#define ss second
#define ll long long int
//#define maxn 400005
#define mod 1000000007
#include <bits/stdc++.h>
#define inf 10000000000013

using namespace std;



int main()
{
    ll tc;
    scanf("%lld" , &tc);

    while(tc--){
        ll n,m;
        scanf("%lld %lld",&n,&m);
        ll maxn = n*4+5;
        ll mx = n+5;
        ll A[maxn] , X[maxn] , C[maxn];
        //cin >> n >> m;
        memset(C,0,sizeof(C));

        for (int i=1;i<=m;i++)scanf("%lld" , &A[i]);//cin >> A[i];
        for (int i=1;i<=m;i++)scanf("%lld" , &X[i]);//cin >> X[i];

        for (int i=1;i<=m;i++){
            ll a = A[i] , b = A[i]+X[i];
            if (a>b)swap(a,b);
            a+=mx ;
            b+=mx;
            C[a]++ , C[b+1]--;
        }
        ll ans = 0 , time = 0;
        map < ll , ll > mp;

        for (int i=1;i<maxn;i++){
            C[i] += C[i-1];
            ll temp = i-mx;
            temp%=n;
            if (temp<=0)temp+=n;

            mp[temp]+=C[i];

            if (mp[temp]>ans || (mp[temp]==ans && temp<time)){
                ans = mp[temp];
                time = temp;
            }
        }
        printf("%lld %lld\n",time,ans);
        //cout << time << " " << ans << endl;
    }



    return 0;
}


