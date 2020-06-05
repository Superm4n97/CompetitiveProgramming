#define ll long long int
#include<bits/stdc++.h>
#define pb      push_back

using namespace std;

vector < pair < ll , ll > > v , solution;
map < pair < ll , ll > , ll > mp;

int main()
{
    int n;
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        v.pb({a,b});
    }
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            ll x = v[i].first+v[j].first , y = v[i].second+v[j].second;
            if (!mp[{x,y}]){
                solution.pb({x,y});
            }
            mp[{x,y}]++;
        }
    }
    ll ans = 0;
    for (int i=0;i<solution.size();i++){
        ll x = solution[i].first , y = solution[i].second;
        ans+=(mp[{x,y}]*(mp[{x,y}]-1))/2;
    }
    cout << ans << endl;


    return 0;
}
