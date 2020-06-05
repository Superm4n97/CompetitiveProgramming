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
#define show(x) cout << #x << " : " << x << endl
#define mk              make_pair
#define inf8            100000008

#define maxn            200005

using namespace std;

ll n, A[maxn] , MX[maxn];
map < ll , ll > mp;
priority_queue < pll > pq;
vector < pll > edge;

int main()
{
    cin >> n;
    for (int i=1;i<n;i++){
        cin >> A[i];
        mp[A[i]]++;
    }
    for (int i=1;i<=n;i++){
        if (mp[i]==0){
            pq.push({i*-1,i});
            MX[i] = i;
        }
    }
    for (int i=n-1;i>=1;i--){
        ll prio = pq.top().first*-1 , node = pq.top().second;
        pq.pop();
        if (prio!=MX[node]){
            i++;
            continue;
        }
        ll newPrio = max(prio,A[i]);
        edge.pb({node,A[i]});
        if (A[i]!=A[1]){
            pq.push({newPrio*-1,A[i]});
            MX[A[i]] = max(MX[A[i]] , newPrio);
        }
    }

    cout << A[1] << endl;

    for (int i=edge.size()-1;i>=0;i--){
        cout << edge[i].first << " " << edge[i].second << endl;
    }


    return 0;
}
