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

int A[22][5],n;

int main()
{
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++){
       cin >>n;
       int ans = inf8;
       for (int i=1;i<=n;i++){
            for (int j=1;j<=3;j++){
                cin >>A[i][j];
                int x = j+1 , y = j+2;
                if (x>3)x-=3;
                if (y>3)y-=3;
                if (i>1)A[i][j] += min(A[i-1][x] , A[i-1][y]);
                if(i==n)ans = min(ans,A[i][j]);
            }
       }
       cout << "Case "<<t<<": "<< ans << endl;
    }
    return 0;
}
