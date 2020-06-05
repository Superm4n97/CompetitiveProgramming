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

ll bit = 0;

ll simple(ll a)
{
    ll tut=1;
    for (int i=1;i<bit;i++){
        tut = tut<<1;
        tut++;
    }
    if (a==tut)return 0;
    return tut;
}

int main()
{
    //cout << (15^5);
    int q;
    cin >> q;
    while(q--){
        bit=0;
        ll b , a;
        cin >> a ;
        b=a;
        while(b){
            if (b%2)cout << 1 ;else cout << 0 ;///cmnt
            b/=2;
            bit++;
        }
        cout << endl;///cmnt
        if (simple(a)){
            cout << simple(a) << " 1"<< endl;///cmnt
            cout << endl;///cmnt
            continue;
        }
        if (bit%2)cout << 1 << " 2" << endl;
        else cout << a/3 << " 3" << endl;
        cout << endl;
    }

    return 0;
}
