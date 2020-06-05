
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
///4direction ->        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair

using namespace std;

string s;
ll a[2e5+5],b[2e5+5],c[2e5+5],d[2e5+5];

int main()
{
    ll n;
    while(cin >> n){
        cin >> s;
        for (int i=0;i<n+4;i++){
            a[i]=0,b[i]=0,c[i]=0,d[i]=0;
        }
        int x=0,y=0;
        for (int i=0;i<n;i++){
            if (s[i]=='U')y++,a[i+1]=1;
            if (s[i]=='D')y--,b[i+1]=1;
            if (s[i]=='L')x--,c[i+1]=1;
            if (s[i]=='R')x++,d[i+1]=1;
        }

    }
    for (int i=1;i<=n;i++){
        a[i]+=a[i-1];
        b[i]+=b[i-1];
        c[i]+=c[i-1];
        d[i]+=d[i-1];
    }
    ll _x,_y;
    cin >> _x >> _y;
    if (abs(_x-x)%2 || abs(_y-y)%2){
        cout << -1 << endl;
        continue;
    }
    ll dx = x-_x , dy = y-_y,Begin=0,End=1;
    while(Begin<=n){

    }

    return 0;
}
