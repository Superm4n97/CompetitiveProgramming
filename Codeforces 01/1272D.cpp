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

ll A[maxn];
ll L[maxn] , R[maxn];
ll n;

int main()
{
    cin >> n;
    for (int i=1;i<=n;i++)cin >> A[i];

    A[0] = -1;
    L[1] = 1;
    R[n] = 1;
    A[n+1] = inf8;

    for (int i=2;i<=n;i++){
        if (A[i-1]<A[i])L[i] = L[i-1]+1;
        else L[i] = 1;
    }
    for (int i=n-1;i>=1;i--){
        if (A[i]<A[i+1]) R[i] = R[i+1]+1;
        else R[i] = 1;
    }

//    for (int i=1;i<=n;i++)cout << L[i];
//    cout << endl;
//    for (int i=1;i<=n;i++)cout << R[i];
//    cout << endl;

    ll ans = 0;

    for (int i=1;i<=n;i++){
        if (A[i-1]<A[i+1]){
//            show(i);
            ll temp = R[i+1]+L[i-1];
            if (A[i]>A[i-1] && A[i]<A[i+1])temp++;
            ans = max(ans,temp);
        }
        ans = max(ans , max(L[i] , R[i]));
    }
    cout << ans << endl;


    return 0;
}

