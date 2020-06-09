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

int G[100][100];

int main()
{
    for (int i=0;i<100;i++){
        for (int j=0;j<100;j++)G[i][j] = 10000000;
    }

    int nodes  , edge;
    cout << "Input The Number of nodes and edge: ";
    cin >> nodes >> edge;

    cout << "Input connecting nodes and weight "<< endl;
    for (int i=0;i<edge;i++){
        int a, b , w;
        cin >> a >> b >> w;
        G[a][b] = w;
        G[b][a] = w;
    }

    for (int k = 0; k <= nodes; k++)
    {
        for (int i = 0; i <= nodes; i++)
        {
            for (int j = 0; j <= nodes; j++)
            {
                if (G[i][k] + G[k][j] < G[i][j])
                    G[i][j] = G[i][k] + G[k][j];
            }
        }
    }
    for (int i=1;i<=nodes;i++){
        for (int j=1;j<=nodes;j++){
            cout << G[i][j] << "  ";
        }
        cout << endl;

    }

    return 0;
}
