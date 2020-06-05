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
///4direction ->        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair

using namespace std;

vector < int > graph[106];

int main()
{
    int n,m;
    while(cin >> n >> m){
        if (n==0 && m==0)break;
        int indegree[106];
        for (int i=0;i<n+5;i++)indegree[i]=0;
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            graph[a].pb(b);
            indegree[b]++;
        }
        queue < int > q;
        vector < int > ans;
        for (int i=1;i<=n;i++)
            if (indegree[i]==0)q.push(i);
        while(!q.empty()){
            int u = q.front();
            //cout << "   " << u << endl;
            q.pop();
            ans.pb(u);
            for (int i=0;i<graph[u].size();i++){
                int v = graph[u][i];
                indegree[v]--;
              //  cout << "        " << v << "  in " << indegree[v] << endl;
                if (indegree[v]==0)q.push(v);
            }
        }
        for (int i=0;i<ans.size();i++){
            cout << ans[i];
            if (i!=n-1)cout << " ";
        }
        cout << endl;
        for (int i=0;i<106;i++)graph[i].clear();
    }

    return 0;
}
