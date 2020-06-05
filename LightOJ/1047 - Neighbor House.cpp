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

int A[22][4] , DP[22][4] , n;

void initialize()
{
    for (int i=0;i<22;i++){
        for (int j=0;j<4;j++)A[i][j]=0 , DP[i][j] = -1;
    }
}

int color(int row , int column)
{
    if (DP[row][column] != -1)return DP[row][column];
    if (row==n-1) return DP[row][column] = A[row][column];

    int a = column-1 , b = column-2;
    if (a<0)a+=3;
    if (b<0)b+=3;

    return DP[row][column] = A[row][column] + min(color(row+1,a) , color(row+1 ,b));
}

int ann[200];

int main()
{
    int tc;
    cin >>  tc;
    for (int _t=1;_t<=tc;_t++){
        int n;
        cin >> n;
        initialize();
        for (int i=0;i<n;i++){
            for (int j=0;j<3;j++)cin >> A[i][j];
        }

        int ans = 10000000;
        for (int i=0;i<3;i++){
            ans = min(color(0,i),ans);
        }
       // printf("Case %d: %d\n",_t,ans);
//        cout << "Case " << _t << ": " << ans;
//        if (_t != tc)cout << endl;
        ann[_t]=ans;
    }

    for (int i=1;i<=tc;i++)cout << "Case " << i << ": " << ann[i] << endl;
    //cout << endl;

    return 0;
}
