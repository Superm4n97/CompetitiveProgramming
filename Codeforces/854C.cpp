#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;

ll n;
vector < ll > v;
map < ll , ll > mp , ck;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        ck[a]++;
        ck[b]++;
        ck[b+1]++;

        mp[a]++;
        mp[b+1]--;

        if (ck[a]==1)v.pb(a);
        if (ck[b]==1)v.pb(b);
        if (ck[b+1]==1)v.pb(b+1);
    }
    sort(v.begin(),v.end());

    ll pre = 0;
    bool ans = true;

    for (int i=0;i<v.size();i++){
        mp[v[i]] += pre;
        pre = mp[v[i]];

        if (pre > 2)ans = false;
    }

    cout << (ans?"YES":"NO") << endl;

    return 0;
}
