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
#define inputll(v,n)    for (ull i=0;i<n;i++){ull a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ull >
#define pii             pair < int , int >
#define mk              make_pair

using namespace std;

int main()
{
    ull n,m,k,index=0,mx=0,cnt=0,ans=0;
    cin >> n >> m >> k;
    vll v;
    inputll(v,n);
    srt(v);
    if (v[n-1]==v[n-2])ans = m*v[n-1];
    else {
        ull temp = m/(k+1) , tut = m%(k+1);
        ans+=(temp*k + tut)*v[n-1];
        ans+=(temp)*v[n-2];
    }
    cout << ans << endl;

    return 0;
}
