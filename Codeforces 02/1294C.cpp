#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define show(x) cout << #x << " : " << x << endl
#define mk              make_pair
#define inf             10000000000000016

#define maxn            1000006

using namespace std;

int main()
{
    ll tc;
    cin >> tc;
    while(tc--){
        ll n;
        cin >> n;
        vll v;

        for (ll i = 2 ; i*i <= n; i++){
            while(n%i==0){
                v.pb(i);
                n/=i;
            }
        }
        if (n>1)v.pb(n);
        srt(v);
        v.pb(1);
        if (v.size()<3){
            cout << "NO" << endl;
            continue;
        }
        map < ll , ll > mp;
        vll v2;
        ll cnt = 0 , temp = 1;
        for (int i=0;i<v.size()-1;i++){
            if (mp[v[i]]==0){
                v2.pb(v[i]);
                cnt++;
                mp[v[i]]++;

                if (cnt==3){
                    for (int j=i+1; j <v.size()-1;j++){
                        v2[2]*=v[j];
                    }
                    break;
                }
            }
            else {
                v[i+1] *= v[i];
            }
        }
        if (cnt<3){
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        for (int i=0 ; i<3;i++){
            cout << v2[i] << " ";
        }
        cout << endl;
    }


    return 0;
}
