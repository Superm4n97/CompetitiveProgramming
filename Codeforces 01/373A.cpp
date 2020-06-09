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

int main()
{
    int k;
    cin >> k;
    k*=2;
    int mx = 0;
    map < char , int > mp;
    bool ans = true;
    for (int i=0;i<4;i++){
        string s;
        cin >> s;
        for (int j=0;j<4;j++){
            if (s[j]!='.'){
                mp[s[j]]++;
                mx = max(mp[s[j]],mx);
            }
        }
    }
    if (mx>k)ans = false;
    cout << (ans?"YES":"NO") << endl;

    return 0;
}

