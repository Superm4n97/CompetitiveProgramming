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

char A[105][105];
int n;

bool cheack(int i, int j)
{
    if (A[i-1][j]=='#' && A[i+1][j]=='#' && A[i][j-1]=='#' && A[i][j+1]=='#' && A[i][j]=='#')return true;
    return false;
}

void fillit(int i, int j)
{
    A[i-1][j]='.' ;
    A[i+1][j]='.' ;
    A[i][j-1]='.' ;
    A[i][j+1]='.' ;
    A[i][j] = '.' ;
}

int main()
{
    cin >> n;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;

        for (int j=0;j<n;j++)A[i][j+1] = s[j];
    }
    for (int i=2;i<n;i++){
        for (int j=2;j<n;j++){
            if (cheack(i,j)){
                fillit(i,j);
            }
        }
    }
    bool ans = true;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)if (A[i][j]=='#')ans = false;
    }
//
//    cout << endl;
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=n;j++)cout << A[i][j];
//        cout << endl;
//    }

    cout << (ans?"YES":"NO") <<endl;

    return 0;
}
