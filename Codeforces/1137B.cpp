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
    string s,t;
    cin >> s >> t;

    int temp = t.size();
    map < int , int > mp;
    for (int i=0;i<s.size();i++){
        mp[s[i]-'0']++;
    }
    for (int i=0;i<s.size();i++){
        int j = i%temp;
        int tut = t[j] - '0';

        if (mp[tut]){
            cout << tut ;
            mp[tut]--;
        }
        else if (mp[1-tut]){
            cout << 1-tut;
            mp[1-tut]--;
        }
        else break;
    }


    return 0;
}
