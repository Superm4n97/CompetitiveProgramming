#include <bits/stdc++.h>
#define pb(a)           push_back(a)
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
#define mk              make_pair
#define mod             1e9+7

using namespace std;

int main()
{
    ll n,l,r;
    cin >> n >> l >> r;
    ll len = r-l+1;
    ll three  = r/3 - (l-1)/3 , rem  = len - three,one = rem/2,two = rem/2;
    if (rem%2!=0){
        if (l%3==1 || r%3==1)one++;
        else two++;
    }
    ll th=1,tw=1,on=1;
    for (int i=0;i<n;i++){
        th*=three;
        th%=mod;
    }
    for (int i=0;i<len/2;i++){
        tw*=two;
        on*=one;
        tw%=mod;
        on%=mod;
    }


    return 0;
}
