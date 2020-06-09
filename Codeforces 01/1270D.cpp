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

#define maxn            100005

using namespace std;

ll A[505];
map < ll , ll > mp , ind;
ll mx = -1;

int main() {
    ll n,m;
    cin >> n >> m ;
    ll p = m+1;

    for (int t = 1;t<=p;t++) {
        cout << "? ";
        for (int i=1;i<=p;i++){
            if (i==t)continue;
            cout << i << " ";
        }
        fflush(stdout);
//
//        char response[3];
//        scanf("%s", response);


        ll b;
        cin >> A[t] >> b;
        ind[b] = A[t];
        mp[b]++;
        mx = max(b , mx);

    }
    cout << "! " << mp[mx] << endl;
}
