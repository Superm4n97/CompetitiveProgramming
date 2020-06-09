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
        int n,m;
        scdd(n,m);
        vector < int > v1 , v2;
        map < pii , int > mp;
        map < int , int > r , c;

        for (int i=0;i<n;i++){
            string s;
            cin >> s;

            for (int j=0;j<m;j++){
                if (s[j]=='*'){
                    v1.pb(i);
                    v2.pb(j);
                    mp[{i,j}] = 1;
                }
            }
        }
        if (v1.empty()){
            cout << m+n-1 << endl;
            continue;
        }
        srt(v1);
        srt(v2);
        int max_row = 1 , max_col = 1 , row = 1 , col = 1;
        r[v1[0]]++ , c[v2[0]]++;

        for (int i=1;i<v1.size();i++){
            r[v1[i]]++ , c[v2[i]]++;
            if (v1[i]==v1[i-1]){
                row++;
            }
            else row = 1;

            if (v2[i]==v2[i-1]){
                col++;
            }
            else col = 1;
                max_row = max(max_row,row);
                max_col = max(max_col,col);
        }
        int tut = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (r[i]==max_row && c[j] == max_col && mp[{i,j}]==0)tut = 1;
            }
        }
        cout << (n-max_row)+(m-max_col)-tut << endl;
    }

    return 0;
}
