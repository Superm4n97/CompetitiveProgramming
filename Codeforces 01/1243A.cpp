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
    ll n;
    cin >> n;
    if (n==1){
        cout << 1 << endl;
        return 0;
    }
    ll cnt = 0 , cnt2 = 0;
    ll a = n;
    while(a){
        cnt2+=(a%2);
        a/=2;
    }
    ll lim = sqrt(n)+1;
    for (int i=2;i<=lim;i++){
        if (n%i==0 && n/i>=i){
            if (n/i==i)cnt++;
            else cnt+=2;
        }
    }
    if (cnt==0)cout << n << endl;
    else if (cnt==1)cout << lim-1 << endl;
    else if (cnt2==1)cout << 2 << endl;
    else cout << 1 << endl;


    return 0;
}
