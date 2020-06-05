#include<bits/stdc++.h>

using namespace std;

#define ll long long int


int main()
{
    ll tc;
    cin >> tc;

    while(tc--){
        ll n,t,a,b;
        cin >> n >> t >> aa >> bb;
        ll maxn = n+5 , totalMen = 0;

        ll M[maxn] , sum = 0;
        for (int i=0;i<n;i++)cin  >> M[i];

        vector < pair < ll , ll > > v;

        for (int i=0;i<n;i++){
            ll a;
            cin >> a;
            v.push_back({a,M[i]});
            if (M[i])sum += bb;
            else sum += aa;
            if (M[i]==1)totalMen++;
        }
        if (sum<=t){
            cout << n << endl;
            continue;
        }
        sort(v.begin(),v.end());

        ll mendetory[maxn];
        memset(mendetory,0,sizeof(mendetory));

        for (int i=0;i<n;i++)mendetory[i+1] = mendetory[i] + v[i].second;

        for (int i=0;i<n;i++){
            ll time = v[i].first - 1;
            ll men = mendetory[i];
            ll nonmen = i - men;
            ll remMen = totalmMen-men ;
            ll remNonMen = n - men - nonmen - remMen;

            if (men*bb + nonmen*aa <= time){
                ll total = i;
                time -= (men*bb + nonmen*aa);

                ll mn = time / a;
            }
        }
    }

    return 0;
}
