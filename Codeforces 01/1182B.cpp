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

ll n,m,ans=0;
char C[505][505];
bool abool = true;

bool check(int x , int y)
{
    if (C[x+1][y]=='*' && C[x-1][y]=='*' && C[x][y+1]=='*' && C[x][y-1]=='*' && C[x][y]=='*')return true;
    return false;
}

void fix(int x, int y)
{
    C[x][y] = '.';
    for (int i=x+1;i<=n;i++){
        if (C[i][y]=='.')break;
        C[i][y]='.';
        //cout << "     " << i << " " << y << endl;
    }
    for (int i=y+1;i<=m;i++){
        if (C[x][i]=='.')break;
        C[x][i]='.';
        //cout << "     " << x << " " << i << endl;
    }

    for (int i=x-1;i>=1;i--){
        if (C[i][y]=='.')break;
        C[i][y]='.';
        //cout << "     " << i << " " << y << endl;
    }
    for (int i=y-1;i>=1;i--){
        if (C[x][i]=='.')break;
        C[x][i]='.';
        //cout << "     " << x << " " << i << endl;
    }
}

int main()
{
    scll(n,m);
    for (int i=0;i<=n+3;i++){
        for (int j=0;j<=n+3;j++)C[i][j] = '#';
    }

    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        for (int j=0;j<m;j++)C[i][j+1] = s[j];
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (check(i,j)){
                fix(i,j);
                ans++;
            }
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (C[i][j]=='*')abool = false;
            //cout << C[i][j];
        }
      //  cout << endl;
    }

    //cout << ans << "   " << abool << endl;
    if (ans==1 && abool)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
