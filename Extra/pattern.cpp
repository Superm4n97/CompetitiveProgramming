#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll even(ll a)
{
    ll kop=5,sum=0;
    for(;;)
    {
        ll ans=a/kop;
        sum+=ans;
        if(ans==0)return sum;
        kop*=5;
    }
}
int main()
{
    ll kop=0;
    for(ll i=0;i<=150;i++)
    {
        ll ans=i;
        ll ans2=even(ans);
        if(ans2%2==0)kop++;
        cout << i <<  " " << ans2 <<" "<< kop << endl;
    }
    /*while(1)
    {
        ll n;
        scanf("%lld",&n);
        if(n==-1)break;
        ll ans=n/10;
        ll mod=n%10;
        ans=ans*10;
        ll ans2=ans/2 +1;
        if(mod>4)ans2+=4;
        else ans2+=mod;
        cout << ans2 << endl;
    }*/
}
