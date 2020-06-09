#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define maxn 200005

int main()
{
    ll tc;
    cin >> tc;

    while(tc--){
        ll n,p,k;
        cin >> n >> p >> k;

        vector < ll > v;
        v.push_back(0);

        for (int i=0;i<n;i++){
            ll a;
            cin >> a;
            v.push_back(a);
        }

        sort(v.begin(),v.end());
        ll ans = 0 , csum = 0;

        for (ll i=0;i<k;i++){
            csum += v[i];
            ll sum = csum;

            if (sum<=p)ans = max(ans,i);

            for (ll j=i+k;j<=n;j+=k){
                sum += v[j];
                if (sum<=p){
                    ans = max(ans,j);
                }
                else break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
