#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
int main()
{
    ll n,k,sum=0;
    cin >> n >> k;
    vector < ll > v;
    v.pb(0);
    for(ll i=0;i<n;i++)
    {
        ll a;
        scanf("%lld",&a);
        sum+=a;
        v.pb(sum);
    }
    double mx=0.0;
    for(ll i=k;i<v.size();i++)
    {
        ll sum=0;
        for(ll j=i;j<v.size();j++)
        {
            sum=v[j]-v[j-i];
            double joss=(sum*1.00)/(i*1.00);
            mx=max(mx,joss);
            //cout <<  mx << endl;
        }
    }
    cout << setprecision(10) << mx << endl;
}

