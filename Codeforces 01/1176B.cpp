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
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        map < int , int > mp;

        for (int i=0;i<n;i++){
            int a;
            cin >> a;
            int temp = a%3;
            mp[temp]++;
        }
        int cnt = mp[0];
        int mn = min(mp[1],mp[2]);
        mp[1] -= mn  , mp[2]-=mn;
        cnt+=mn;
        cnt+=mp[1]/3 ;
        cnt+=mp[2]/3;
        cout << cnt << endl;
    }

    return 0;
}
