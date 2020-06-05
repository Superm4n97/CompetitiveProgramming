#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    //cout << __gcd(4,-2) << endl;
    ll tc;
    cin >> tc;
    for (int _t = 1; _t<=tc ; _t++){
        ll n;
        cin >> n;

        //cout << " n : " << n << endl;

        ll X[n+5] , Y[n+5] , ans = 1;

        for (int i=0;i<n;i++)cin >> X[i] >> Y[i];

        for (int i=0;i<n;i++){
            map < pair < ll , ll > , ll > mp;

            for (int j=0;j<n;j++){
                if (i==j)continue;

                ll dx = (X[i]-X[j]) , dy = (Y[i]-Y[j]);

                ll g = __gcd(dx,dy);
                dx/=g , dy/=g;

                if (dx<0 && dy>0)dx*=-1, dy*=-1;

                mp[{dx,dy}]++;
                ans = max(ans , mp[{dx,dy}]+1);
            }
        }
        cout << "Case "<< _t<< ": " << ans << endl;
    }


    return 0;
}
