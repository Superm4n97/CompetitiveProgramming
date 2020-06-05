#include <bits/stdc++.h>
#define pb(a)           push_back(a)
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%lld",&w)
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

int A[16][16] , DP[16][16][65537] , n;

int MarCere(int x,int y, int mask)
{
    int tut = 1<<y;
    if (mask & tut)return 0;
    mask|=tut;

    if(DP[x][y][mask]!=-1)return DP[x][y][mask];
    if (x==n-1)return DP[x][y][mask] = A[x][y];

    int mx = 0;
    for (int i=0;i<n;i++){
        mx = max(mx,MarCere(x+1,i,mask));
    }

    return DP[x][y][mask] = mx+A[x][y];

}

int main()
{
    int tc;
    cin >> tc;
    for (int t = 1;t<=tc;t++){
        cin >> n;

        for (int i=0;i<=n;i++){
            for (int j=0;j<=n;j++){
                for (int k=0;k<=65540;k++)DP[i][j][k] = -1;
            }
        }

        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++)cin >> A[i][j];
        }


        int maxx  = 0;
        for (int i=0;i<n;i++){
            maxx = max(maxx,MarCere(0,i,0));
        }
        cout << "Case " << t <<": " << maxx << endl;
    }

    return 0;
}

