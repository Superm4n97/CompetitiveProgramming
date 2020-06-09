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
#define mk              make_pair
#define inf8            100000008

using namespace std;

vll v;

int main()
{
    ll n;
    scl(n);

    for (int i=0;i<n;i++){
        ll a;
        scl(a);

        if (a>=0)a = a*-1 - 1;
        v.pb(a);
    }
    if (v.size()==1 && v[0]==-1)cout << 0 << endl;
    else {
        vll v2 = v;
        rsrt(v2);
        ll value = v2[0];
        bool temp = true;
        if (v.size()%2){
            temp = false;
            for (int i=0;i<n;i++){
                if (v2[i]!=-1){
                    value = v2[i];
                    break;
                }
            }
            value = v2[n-1];
        }
        for (int i=0;i<n;i++){
            if (v[i]==value && !temp){
                cout << v[i]*-1 -1 << " ";
                temp = true;
            }
            else {
                cout << v[i] << " ";
            }
        }
        cout << endl;
    }


    return 0;
}

