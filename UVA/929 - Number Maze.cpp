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

int n,m,board[1005][1005],weight[1005][1005];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

bool check(int x, int y)
{
    if (x>=0 && x<n && y>=0 && y<m)return true;
    return false;
}

int dijkstra()
{
    priority_queue < pair < int , pair < int , int > > > pq;
    pq.push(mk(board[0][0]*-1,mk(0,0)));
    weight[0][0] = board[0][0];
    while(!pq.empty()){
        int cost = pq.top().first *-1 , x = pq.top().second.first , y = pq.top().second.second;
        pq.pop();
        if (x==n-1 && y==m-1)return cost;
        for (int i=0;i<4;i++){
        //cout << "ok" << endl;
            if (check(x+dx[i],y+dy[i]) && weight[x+dx[i]][y+dy[i]]>cost+board[x+dx[i]][y+dy[i]]){
                weight[x+dx[i]][y+dy[i]]=cost + board[x+dx[i]][y+dy[i]];
                pq.push(mk(weight[x+dx[i]][y+dy[i]]*-1,mk(x+dx[i],y+dy[i])));
            }
        }
    }
}

int main()
{
    int tc;
    while(cin >> tc){
        while(tc--){
            cin >> n >> m;
            for (int i=0;i<n+4;i++){
                for (int j=0;j<m+4;j++)weight[i][j]=10000000;
            }
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++)cin >> board[i][j];
            }
            cout << dijkstra() << endl;
        }

    }

    return 0;
}
