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
#define maxn            7005
#define show(x) cout << #x << " : " << x << endl
using namespace std;

ll A[maxn] , B[maxn] , bit[maxn];
ll n,m;
map < ll , ll > mp;
vector < ll > v;

int main()
{
    scl(n);

    for (int i=0;i<n;i++){
        scl(A[i]);
        ll t = A[i] , temp = 0;
        while(t>0){
            if (t%2){
                temp++ ;
            }
            t/=2;
        }
        bit[i] = temp;
        show(bit[i]);
        if (!mp[temp]){
            mp[temp] = 1;
            v.pb(temp);
        }
    }
    for (int i=0;i<n;i++)scl(B[i]);
    ll mx = 0;
    for (int i=0;i<v.size();i++){
        ll tmes = v[i] , occurence = 0 , sum = 0;
        show(tmes);
        for (int j=0;j<n;j++){
            if (bit[j]==tmes){
                sum+=B[j];
                occurence++;
            }
        }
        if (occurence>1)mx = max(mx,sum);
    }
    cout << mx << endl;



    return 0;
}
