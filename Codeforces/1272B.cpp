#include <bits/stdc++.h>
#define pb              push_back
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
#define pll             pair < ll , ll >
#define show(x) cout << #x << " : " << x << endl
#define mk              make_pair
#define inf8            100000008

#define maxn            100005

using namespace std;

int main()
{
    ll tc;
    cin >> tc;
    while(tc--){
        string s;
        cin >> s;
        ll n = s.size();
        ll a=0,b=0,u=0,d=0,l=0,r=0;
        for (int i=0;i<n;i++){
            if (s[i]=='U')u++;
            if (s[i]=='L')l++;
            if (s[i]=='D')d++;
            if (s[i]=='R')r++;
        }
        a = min(l,r) , b =  min(u,d);
        if (a==0 && b==0){
            cout << 0 << endl;
            continue;
        }
        if (a==0){
            cout << 2 << endl;
            cout << "UD" << endl;
        }
        else if (b==0){
            cout << 2 << endl;
            cout << "LR" << endl;
        }
        else {
            cout << (a+b)*2 << endl;
            for (int i=0;i<a;i++)cout << 'L' ;
            for (int i=0;i<b;i++)cout << 'U' ;
            for (int i=0;i<a;i++)cout << 'R' ;
            for (int i=0;i<b;i++)cout << 'D' ;
            cout << endl;
        }
    }


    return 0;
}
