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

int main()
{
    ll x,y,n,_x=0,_y=0,u=0,l=0,r=0,d=0;
    string s;
    scl(n);
    cin >> s;
    scll(x,y);
    for (int i=0;i<n;i++){
        if (s[i]=='R')_x++;
        else if (s[i]=='L')_x--;
        else if (s[i]=='U')_y++;
        else if (s[i]=='D')_y--;
    }
    if ((abs(x-_x)+abs(y-_y))>n || (abs(x-_x)+abs(y-_y))%2){
        printf("-1\n");
        return 0;
    }
    ll dx = x-_x;
    ll dy = y-_y;

    return 0;
}
