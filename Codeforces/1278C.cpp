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

int main()
{
    ll tc;
    cin >> tc;
    while(tc--){
//        show(tc);
        ll n , mx = 0;
        cin >> n;
        ll A[2*n+5];
        map < ll , ll > dis;
        for (int i=1;i<=2*n;i++)cin >> A[i];

        ll one = 0 , two = 0;

        for (int i=2*n ; i>n ; i--){
            if (A[i]==1)one++;
            else two++;

            dis[one-two] = 2*n+1 - i;
        }
        one = 0 , two = 0;
        mx =dis[0];
        for (int i=1;i<=n;i++){
            if (A[i]==1)one++;
            else two++;

            if ((one-two) != 0 && dis[(one-two)*-1]==0)continue;

            mx = max(mx,dis[(one-two)*-1]+i);
        }
        cout << 2*n - mx << endl;
    }


    return 0;
}
