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

ll n,k;
vector < pair < pair < ll , ll > , ll > > vp;
priority_queue < pair < ll , ll > > pq;
vll ans;

ll A[maxn];

int main()
{
    scll(n,k);
    for (int i=1;i<=n;i++){
        ll a,b;
        scll(a,b);
        vp.pb({{a,b},i});
    }

    srt(vp);
    ll temp = 0;

    for (int i=1;i<maxn;i++){
        if (!pq.empty()){
            while(pq.top().first<i){
                pq.pop();
                if (pq.empty())break;
            }
        }

        while (temp<vp.size() && vp[temp].first.first == i){
            A[i]++;
            A[vp[temp].first.second+1]--;
            pq.push({vp[temp].first.second,vp[temp].second});
            temp++;
        }

        A[i]+=A[i-1];

        while(A[i]>k){
            ll r = pq.top().first , ii = pq.top().second;
            pq.pop();
            A[i]--;
            A[r+1]++;
            ans.pb(ii);
        }

    }
    srt(ans);
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;



    return 0;
}
