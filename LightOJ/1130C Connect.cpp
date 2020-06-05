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

int n;
vector < pair < int , int > > A,B;
char board[100][100];
int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};

bool check(int x, int y)
{
    if (x>=0 && x<n && y>=0 && y<n && board[x][y]=='0')return true;
    return false;
}

void DFSA(int a, int b)
{
    A.pb(mk(a,b));
    board[a][b]='*';

    for (int i=0;i<4;i++){
        int x = a+del_x[i] , y = b+del_y[i];
        if(check(x,y)){
           // cout << x << " " << y << board[x][y] << endl;
            DFSA(x,y);
        }
    }
}

void DFSB(int a, int b)
{
    B.pb(mk(a,b));
    board[a][b]='*';

    for (int i=0;i<4;i++){
        int x = a+del_x[i] , y = b+del_y[i];
        if(check(x,y)){
            DFSB(x,y);
        }
    }
}

int main()
{
    cin >> n;
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        for (int j=0;j<n;j++)board[i][j] = s[j];
    }
    DFSA(a-1,b-1);
    if (board[c-1][d-1]=='*'){
        cout << 0 << endl;
        return 0;
    }
    DFSB(c-1,d-1);
    int ans = 100000000;

    ///***************
//    for (int i=0;i<n;i++){
//        for (int j=0;j<n;j++)cout << board[i][j];
//        cout << endl;
//    }
//    for (int i=0;i<B.size();i++)cout << B[i].first << " " << B[i].second << endl;

    ///***************

    for (int i=0;i<A.size();i++){
        for (int j=0;j<B.size();j++){
            int temp = (A[i].first-B[j].first)*(A[i].first-B[j].first) + (A[i].second-B[j].second)*(A[i].second-B[j].second);

//            if (ans>temp){
//                cout << ans << " ok  " << A[i].first <<  "  " << B[j].first << "  " << A[i].second << "  " <<B[j].second << endl;
//            }

            ans = min(ans,temp);
        }
    }
    cout << ans << endl;

    return 0;
}
