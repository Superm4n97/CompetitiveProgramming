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

using namespace std;

ll A[200005],mark[200005];

int main()
{
    ll n,k,ind,mn=1e16;
    map < pair < ll , ll > , int > mp;
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> A[i];
        if (A[i]<mn){
            mn = A[i];
            ind = i;
        }
    }

    for (int i=0;i<k;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        mp[mk(a,b)]=c;
        mp[mk(b,a)]=c;


    }
    ll cnt=0;
    for (int i=1;i<=n;i++){
        if (i==ind)continue;
        if (A[i]+A[ind] > mp[mk(i,ind)] &&  mp[mk(i,ind)]!=0)cnt+=mp[mk(i,ind)];
        else cnt+=A[i]+A[ind];
    }
    cout << cnt << endl;


    return 0;
}

