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

string s = "rffrcfc";
ll a, b, c;

ll F(int n)
{
    ll d = a, e = b, f = c , temp=0;
    for (int i=n;;i++){
        i%=7;
        if (s[i]=='f'){
            if (d==0)return temp;
            else d--,temp++;
        }
        else if (s[i]=='r'){
            if (e==0)return temp;
            else e--,temp++;
        }
        else{
            if (f==0)return temp;
            else f--,temp++;
        }
    }
}

int main()
{
    cin >> a >> b >> c;
    ll week = min(a/3,min(b/2,c/2)) , mx = 0;
    a-=week*3 , b -= week*2 , c -= week*2;

    for (int i=0;i<7;i++)mx = max(F(i),mx);
    cout << week*7+mx << endl;

    return 0;
}
