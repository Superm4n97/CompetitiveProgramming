#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
#define mod 1000000007
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll ans = 1;

ll bigMod(ll a , ll pw)
{
    if (pw==0)return 1;
    if (pw==1)return a;
    ll temp = bigMod(a,pw/2);
    temp*=temp;
    temp%=mod;

    if (pw%2)temp*=a;
    temp%=mod;

    return temp;
}

int main()
{
    ll n,k;
    cin >> n >> k;

    ll lim = sqrt(n)+1;

    ll ii = 2;

    while(ii<=lim){
        if (n%ii==0){
            ll temp = ii;
            while(n%ii==0){
                n/=ii;
            }
            ll cnt = 0;
            while(k%temp==0){
                temp*=ii;
                cnt++;
            }

            temp = bigMod(ii,cnt);
            show(ii);
            show(cnt);
            show(temp);
            ll tut = bigMod(temp,k/ii);
            ans*=tut;
            ans%=mod;
        }
        ii++;
    }

    if (n!=1){
        ll temp = n , cnt = 0;

        while(k%temp==0){
            temp*=n;
            cnt++;
        }
        temp = bigMod(n,cnt);
        ll tut = bigMod(temp,k/n);

        ans *= tut;
        ans%=mod;
    }

    cout << ans << endl;


    return 0;
}
