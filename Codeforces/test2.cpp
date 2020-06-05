#include <bits/stdc++.h>
#define pb(a)           push_back(a)
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%lld",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%lld %lld",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define mk              make_pair
#define inf8            100000008
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

ll n;
map < string , ll > mp;
string s1,s2,s;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    scl(n);
    for (ll t=0;t<n;t++){

        cin >> s1 >> s2;

        if (s1=="add"){
            s="";
            for (ll i=0;i<s2.size();i++){
                s+=s2[i];
                mp[s]++;
            }
        }
        else {
            printf("%lld\n",mp[s2]);
        }
    }

    return 0;
}
