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
#define inf8            100000008

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--){
        ll n,k;
        scll(n,k);
        vll v;

        for (int i=0;i<n;i++){
            ll a;
            scl(a);
            v.pb(a);
        }
        srt(v);
        k++;
        ll ans = 1000000005 , ind = 0;
        for (int i=k-1;i<n;i++){
            ll e = v[i]  , b = v[i-k+1];
            //cout << "   " << e << "  " << b << endl;
            ll tut = e-b;
            ll temp = tut/2;
            if (temp*2!=tut)temp++;
            if (temp<ans){
                ans = temp;
                //cout << "    " << temp <<  endl;
                ind = b+temp;
            }
        }
        cout << ind << endl;
    }

    return 0;
}
