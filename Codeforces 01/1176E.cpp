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

vii G[200005];

int main()
{
    int tc;
    scd(tc);
    while(tc--){
        int n,m;
        scdd(n,m);
        for (int i=0;i<m;i++){
            int a,b;
            scdd(a,b);
            G[a].pb(b);
            G[b].pb(a);
        }
        int A[200005];
        map < int , int > mp;
        vii ans;

        for (int i=0;i<n+2;i++)A[i]= 0;

        queue < int > q;
        q.push(1);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if (mp[u]==0){
                mp[u] = 2;
                ans.pb(u);
            }

            for (int i=0;i<G[u].size();i++){
                int v = G[u][i];
                if (mp[v]==0){
                    q.push(v);
                    if (mp[u]==2)mp[v]=1;
                }
            }
        }

        if (ans.size()>n/2){
            vii ann;
            for (int i=1;i<=n;i++)if (mp[i]==1)ann.pb(i);
            ans = ann;
        }

        int tut = n/2;
        int temp = tut - ans.size();

        map < int , int > mmpp;
        for (int i=0;i<ans.size();i++){
            mmpp[ans[i]]++;
        }
        int j = 1;
        while(temp){
            if (mmpp[j]==0){
                ans.pb(j);
                temp--;
            }
            j++;
        }
        cout << ans.size() << endl;
        for (int i=0;i<ans.size();i++)cout << ans[i] << " ";
        cout << endl;

        for (int i=0;i<=n;i++)G[i].clear();
    }

    return 0;
}
