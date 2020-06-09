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
#define mk              make_pair
#define inf8            100000008

using namespace std;

int main()
{
    vector < int > v[5];
    for (int i=0;i<3;i++){
        string s;
        cin>> s;
        int a = s[0]-'0';
        if (s[1]=='s')v[0].pb(a);
        if (s[1]=='p')v[1].pb(a);
        if (s[1]=='m')v[2].pb(a);
    }
    for (int i=0;i<3;i++)srt(v[i]);

    int ans = 2;
    for (int i=0;i<3;i++){
        if (v[i].size()==3){
            if (v[i][0]==v[i][1] && v[i][1]==v[i][2])ans = min(ans,0);
            if (v[i][0]+1 == v[i][1] && v[i][1]+1==v[i][2])ans = min(ans,0);
            if (v[i][0]+1 == v[i][1] || v[i][1]+1==v[i][2] || v[i][0]+2 == v[i][1] || v[i][1]+2==v[i][2])ans = min(ans,1);
            if (v[i][0] == v[i][1] || v[i][1]==v[i][2])ans = min(ans,1);
        }
        if (v[i].size()==2){
            if (v[i][0]==v[i][1])ans = min(ans,1);
            if (v[i][0]+1==v[i][1] || v[i][0]+2 == v[i][1])ans = min(ans,1);
        }
    }
    cout << ans << endl;


    return 0;
}
