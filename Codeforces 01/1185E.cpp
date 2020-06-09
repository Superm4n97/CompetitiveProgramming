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
    int tc;
    scd(tc);

    while(tc--){
        vector < pll > v[30];
        int n,m;
        int DEG[30];
        for (int i=0;i<30;i++)DEG[i] = 0;
        vii mark;
        map < pii , int > mp;

        scdd(n,m);
        char G[n+2][m+2];
        for (int i=0;i<n;i++){
            string s;
            cin >> s;
            for (int j=0;j<m;j++){
                G[i][j] = s[j];
                if (G[i][j]!='.'){
                    int tut = G[i][j] - 'a';
                    if (v[tut].size()<2)v.pb({i,j});
                    else v[tut][1] = {i,j};
                }
            }
        }

        for (int i=0;i<26;i++){
            if (v[i].size()==1){
                mark.pb(i);
            }
            if (v[i].size()>1){
                int tut = 1;
                if (v[i][0].first == v[i][1].first)tut = 0;
                int start,endd , x = v[i][0].first , y = v[i][0].second;
                if (tut) start = v[i][0].first , endd = v[i][1].first;
                else start = v[i][0].second , endd = v[i][1].second;

                for (int i=start ; i<=endd ; i++){
                    int xx , yy;
                    if (tut)yy = v[i][0].second , xx = i;
                    else yy = i ; xx = v[i][0].first;

                    if (G[xx][yy] != G[x][y]){
                        int temp = G[xx][yy] - 'a';
                        DEG[i]++;
                        mp[{temp,i}] = 1;
                    }
                }
            }

            for (int i=0;i<26;i++){
                for (int j=0;j<26;j++){

                }
            }
        }
    }

    return 0;
}

