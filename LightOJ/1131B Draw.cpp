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

int x[10005],y[10005];

int main()
{
    int n,cnt=0;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> x[i] >> y[i];

        int mn = max(x[i-1],y[i-1]) , mx = min(x[i],y[i]);
        if (mx==0)continue;
        mx = mx-mn+1;
        if (mx<0)continue;
        cnt+=mx;
        //cout << cnt << endl;
    }
    if (cnt==0)cnt++;
    cout << cnt << endl;


    return 0;
}
