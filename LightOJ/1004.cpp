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

int n,m;
int A[500][500];

int monkey(int i, int j)
{
    if (i<=n){
        if (i==0)return 0;
        if (j-1<1)return A[i-1][j];
        if (j==i)return A[i-1][j-1];

        return max(A[i-1][j],A[i-1][j-1]);
    }
    else return max(A[i-1][j],A[i-1][j+1]);
}

int main()
{
    int tc;
    //cin >> tc;
    scd(tc);
    for (int t=1;t<=tc;t++){
        //cin >> n;
        scd(n);
        for (int i=1;i<=2*n-1;i++){
            for (int j=1;j<=min(i,2*n-i);j++){
                //cin >> A[i][j];
                scd(A[i][j]);
                A[i][j]+=monkey(i,j);
            }
        }
        //cout << "Case "<<t<<": "<< A[2*n-1][1] << endl;
        printf("Case %d: %d\n",t,A[2*n-1][1]);
    }

    return 0;
}
