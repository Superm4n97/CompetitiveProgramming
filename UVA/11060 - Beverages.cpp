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

int n,m,indegree[500];
string s,s2;
vector < int > graph[500],arr;

int main()
{
    int tc = 1;
    while(cin >> n){
        int counter = 1;
        map < int,string > mp;
        map < string,int > rev;
        for (int i=0;i<n;i++){
            cin >> s;
            mp[counter]=s;
            rev[s]=counter;
            counter++;
        }
        for (int i=1;i<=n;i++)indegree[i]=0;
        arr.clear();
        cin >> m;
        for (int i=0;i<m;i++){
            cin >> s >> s2;
            int a = rev[s] , b= rev[s2];
            graph[a].pb(b);
            indegree[b]++;
        }
        queue < int > q;
        for (int i=1;i<=n;i++){
            if (indegree[i]==0)q.push(i);
        }
        //for (int i=1;i<=n;i++)cout << "indegree " << indegree[i] << endl;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            arr.pb(u);
            for (int i=0;i<graph[u].size();i++){
                int v = graph[u][i];
          //  cout << "ok indegree of v " ;
                indegree[v]--;
        //        cout << indegree[v] << endl;
                if (indegree[v]==0){
                    q.push(v);
                }
            }
        }
        cout << "Case #"<<tc<<": Dilbert should drink beverages in this order:";
        tc++;
        for (int i=0;i<n;i++){
            cout << " " << mp[arr[i]] ;
        }
        cout <<"\n"<< endl;


        for (int i=0;i<300;i++)graph[i].clear();
    }

    return 0;
}
