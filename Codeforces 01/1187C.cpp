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

vector < pll > vrt1 , vrt2 ,vurt1 , vurt2;
ll A[1003] , n , m;

int main()
{
    cin >> n >> m;
    for (int j=1;j<=m;j++){
        ll c,a,b;
        cin >> c >> a >> b;
        if (c==1)vrt1.pb({a,b});
        else vurt1.pb({a,b});
    }
    srt(vrt1) , srt(vurt1);
    ll x,y;
    if (vrt1.size())x = vrt1[0].first , y = vrt1[0].second;
    for (int i=1;i<vrt1.size();i++){
        if (vrt1[i].first<=y){
            y = max(y,vrt1[i].second);
        }
        else {
            vrt2.pb({x,y});
            x = vrt1[i].first , y = vrt1[i].second;
        }
    }
    if (vrt1.size())vrt2.pb({x,y});
    for (int j=0;j<vrt2.size();j++){
        ll temp = 1;
        for (int i = vrt2[j].first;i<=vrt2[j].second;i++){
            A[i] = temp;
            temp++;

           // cout << "   " << temp << "   " << A[i] << endl;
        }
    }
    int tut = 0;
    for (int i=n;i>0;i--){
        if (i==n && A[i]==0){
            A[i] = 1;
            continue;
        }
        if (A[i] && !tut){
            A[i] = max(A[i+1]+1 , A[i]);
            tut = 1;
        }
        if (A[i]==0){
            A[i] = A[i+1]+1;
            tut = 0;
        }
    }
    bool ans = true;

 //   for (int i=1;i<=n;i++)cout << A[i] << " ";
  //      cout << endl;


    for (int j=0;j<vurt1.size();j++){
        bool sorted = true;
        for (int i=vurt1[j].first+1 ;i<=vurt1[j].second; i++){
            if (A[i]==A[i-1]){
                A[i-1]++;
                sorted = false;
            }
            if (A[i] <A[i-1]){
                sorted = false;
            }
        }
        if (sorted)ans = false;
    }
    if (!ans)cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i=1;i<=n;i++)cout << A[i] << " ";
        cout << endl;
    }

    return 0;
}

