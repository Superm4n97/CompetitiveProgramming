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
ll n,tc,X[300005] , Y[300005] , mx = -1 , index;
queue < ll > q;

int main()
{
    scll(n,tc);
    ll temp ;
    for (int i=0;i<n;i++){
        ll a;
        scl(a);

        if (i==0)mx = a , index = i;
        else {
            X[i] = mx;
            Y[i] = a;
            if (a>mx) swap(mx,a);
            q.push(a);
        }
    }
    while(!q.empty()){
        v.pb(q.front());
        q.pop();
    }
//    for (int i=0;i<v.size();i++)cout << v[i] << " ";
//    cout << endl;

    while(tc--){
        ll a;
        scl(a);

        if (a<n)cout << X[a] << " " << Y[a] << endl;
        else {
            ll temp = a%(n-1);
            if (temp==0)temp = n-1;
            cout << mx << " " << v[temp-1] << endl;
        }
    }

    return 0;
}
