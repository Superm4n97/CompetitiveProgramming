#include <bits/stdc++.h>
#define pb(a)           push_back(a)
#define ll              long long int
#define ull             unsigned long long
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
#define mk              make_pair

using namespace std;

int main()
{
    ll n,index=0,mx=0,ans=0;
    cin >> n;
    vll v;
    for (int i=0;i<n;i++){
        ll a;
        cin >> a;
        v.pb(a);
        mx = max(mx,a);
    }

    for (int i=0;i<n;i++){
        if (v[i]==mx){
            ll tut = 1;
            for (int j=i+1;j<n;j++){
              //  cout << i << j << endl;
                if (v[j]==v[i])tut++;
                else {
                    i = j;
                    break;
                }
                if (j==n-1){
                    i=n;
                    break;
                }
            }
            ans = max(ans,tut);
        }
    }

    cout << ans << endl;

    return 0;
}
