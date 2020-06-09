#include<bits/stdc++.h>
#define ll long long int
#define srt(v) sort(v.begin(),v.end())
#define scf2(a,b) scanf("%lld%lld",&a,&b)
#define scf(a) scanf("%lld",&a)
#define pb push_back

using namespace std;

int main()
{
    ll tc;
    cin >> tc;
    while(tc--)
    {
        ll n,k,sum=0;
    scf2(n,k);
    vector < ll > v,w;
    //v.pb(0);
    //w.pb(0);
    for(ll i=0;i<n;i++)
    {
        ll a;
        scf(a);
        sum+=a;
        w.pb(a);
        v.pb(a);
    }
    ll low=1, high=10000000000000016;
    ll ans=0;
   // cout << mid << endl;

    while(low<=high)
    {
        ll row=0,ager=0;

        ll mid=(low+high)/2;

        for(ll i=0;i<n;i++)
        {
            ll a = v[i];
            ll emni = mid - ager;
            if (a>=emni){
                a-=emni;
                row++;
            }
            row+=(a/mid);
            ager = a%mid;
        }

        //for(ll i=0;i<=n;i++)v[i]=w[i];

        if(row>=k)
        {
            ans=max(mid,ans);
            low=mid + 1;
        }
        else high=mid-1;


    }
    printf("%lld\n",ans*k);
    }
}

