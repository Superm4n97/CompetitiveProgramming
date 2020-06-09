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

ll A[2000006];

int main()
{
    ll n,val ,times=0;
    cin >> n;
    map < ll , ll > mp;

    for (int i=1;i<=n;i++){
        scl(A[i]);
        mp[A[i]]++;
        if (times<mp[A[i]]){
            times = mp[A[i]];
            val = A[i];
        }
    }
    vector < ll > aa,bb,cc;

    for (int i=1;i<n;i++){
        if (A[i]==val || A[i+1]==val){
            if (A[i]==A[i+1])continue;
            ll x = i , y = i+1;
            if(A[i] == val)swap(x,y);
            if (A[x] < val)aa.pb(1);
            else aa.pb(2);
            bb.pb(x),cc.pb(y);
            A[x] = val;
            A[y] = val;
        }
    }

    for (int i=n;i>1;i--){
        if (A[i]==val || A[i-1]==val){
            if (A[i]==A[i-1])continue;
            ll x = i-1 , y = i;
            if(A[x] == val)swap(x,y);
            if (A[x] < val)aa.pb(1);
            else aa.pb(2);
            bb.pb(x) , cc.pb(y);
            A[x] = val;
            A[y]=val;
        }
    }
    cout << aa.size() << endl;
    for (int i=0;i<aa.size();i++)cout << aa[i] << " "<< bb[i] << " " << cc[i] << endl;

    return 0;
}
