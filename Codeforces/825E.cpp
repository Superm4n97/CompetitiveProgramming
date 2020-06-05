#include<bits/stdc++.h>

#define ll long long int

using namespace std;

ll n,m,cnt = 1;
vector < ll > G[100005];
vector < ll > DG[100005];
ll indegree[100005] , label[100005] , mark[100005];
priority_queue < ll > P;

void solve(ll a)
{
    priority_queue < ll > pq;
    queue < ll > q;
    q.push(a);
    mark[a] = 1;

    while(!q.empty()){
        ll u = q.front();
        q.pop();

        if (indegree[u] == 0)pq.push(u*-1);

        for (int i=0 ; i<G[u].size(); i++){
            ll v = G[u][i];
            if (mark[v] == 0){
                q.push(v);
                mark[v] = 1;
            }
        }
    }

    while(!pq.empty()){
        ll u = pq.top()*-1;
        pq.pop();

        label[u] = cnt;
        cnt++;

        for (int i=0;i<DG[u].size();i++){
            ll v = DG[u][i];
            indegree[v]--;
            if (indegree[v]==0)pq.push(v*-1);
        }
    }
}

void solve2(ll u)
{
    sort(DG[u].begin() , DG[u].end());
    for (int i=0 ; i<DG[u].size() ; i++){
        ll v = DG[u][i];
        if (label[v] == 0){
            solve2(v);
        }
    }
    label[u] = cnt;
    cnt++;
}

int main()
{
    cin >> n >> m;
    for (int i=0;i<m;i++){
        ll a, b;
        cin >> a >> b;
//        DG[a].push_back(b);
        DG[b].push_back(a);
//        G[a].push_back(b);
//        G[b].push_back(a);
        indegree[a]++;
    }
    cnt = n;
    /*for (int i=1;i<=n;i++){
        //if (mark[i]==0)solve(i);
        if (label[i] == 0) solve2(i);
    }*/

    for (int i=1;i<=n;i++){
        if (indegree[i]==0)P.push(i);
    }
    while(!P.empty()){
        label[P.top()] = cnt;
        cnt--;
        ll u = P.top();
        P.pop();

        for (int i = 0;i<DG[u].size() ; i++){
            ll v = DG[u][i];
            indegree[v]--;
            if (indegree[v]==0)P.push(v);
        }

    }

    for (int i=1;i<=n;i++){
        cout << label[i] << " " ;
    }
    cout << endl;

    return 0;
}
