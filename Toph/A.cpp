#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%lld",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%lld %lld",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair
#define inf8            100000008
#define maxn            2004
#define mod             1000000007

using namespace std;

vector < string > G;

int main()
{
    ll tc;
    scl(tc);
    for (int _t=1;_t<=tc;_t++){
        ll n;
        scl(n);
        for (int i=0;i<n;i++){
            string s;
            cin >> s;
            G.pb(s);
        }
        cout << "    sz  " << G[2][0] << G[2][1] << endl;

        ll mn = G[0].size();
        ll temp = mn;

        for (int i=1;i<(1 << temp);i++){
            ll onbit = 0;
            bool vari = true;

            for (int k = 0;i<n;k++){
                bool res = false;

                for (int j=0;j<temp;j++){
                    ll bit = 1<<j;
                    bit = bit&i;
                    if (G[k][j]=='Y' && bit)res==true;
            cout << "       k j  " << k << " " << j << "    G[j][k] " << G[k][j] << "  " <<  bit << " " << i <<  endl;
                }
                if (res==false)vari = false;

            }
            ll tut = 0 , x = i;
            while(x){
                tut+=(x%2);
                x/=2;
            }
            if (vari){
                cout << i << endl;
                mn = min(mn,tut);
            }
        }
        cout << "Case "<< _t <<": "<< mn << endl;
    }



    return 0;
}

