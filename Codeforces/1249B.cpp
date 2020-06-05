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

ll P[maxn];
ll chk[maxn];

ll recur(ll pos, ll temp)
{
    //cout << "pos : " << pos << endl;
    if (chk[P[pos]]==-1)return chk[pos] = temp;
    return chk[pos] = recur(P[pos],temp+1);
}

int main()
{
    ll tc;
    scl(tc);
    while(tc--){
        ll n;
        scl(n);
        for (int i=1;i<=n;i++){
            scl(P[i]);
            chk[i] = 0;
        }

        for (int i=1;i<=n;i++){
            if (chk[i]==0){
               // cout << " i: " << i << endl;
                chk[i] = -1;
                recur(i,1);
            }
        }
        for (int i=1;i<=n;i++){
            printf("%I64d ",chk[i]);
        }
            printf("\n");
    }



    return 0;
}
