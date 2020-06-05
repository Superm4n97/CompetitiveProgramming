#define ll long long int
#define maxn 200005
#include<bits/stdc++.h>

using namespace std;

vector < ll > G[maxn];
vector < pair < ll , pair <ll,ll> > > edges;
ll P[maxn] , sz[maxn] , Ans[maxn];

ll findParent(ll a)
{
    if (P[a]==a)return a;
    return P[a] = findParent(P[a]);
}

int main()
{
    ll n;
    cin >> n;
    for (int i=0;i<=n;i++){
        P[i] = i;
        sz[i] = 1;
    }
    for (int i=0;i<n-1;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        edges.push_back({c,{a,b}});
    }
    sort(edges.begin(),edges.end());

    for(int i=0;i<n-1;i++){
        int j= i;
        map < ll, ll > mark;
        vector < ll > v;
        while(edges[i].first == edges[j].first && j<n-1){
            ll a = edges[i].second.first , b = edges[i].second.second , c = edges[i].first;
            a = findParent(a);
            b = findParent(b);
            if (a!=b){

            }

            j++;
        }

    }

    return 0;
}
