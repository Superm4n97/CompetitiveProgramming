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
#define inf             10000000000000016

#define maxn            200005

using namespace std;

ll A[maxn] , mark[30];

int main()
{
    memset(A,-1,sizeof(A));
    memset(mark,-1,sizeof(mark));

    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll ans = -1;

    for (int i=0;i<n;i++){
        ll cross = 0 , mx = -1;

        ll tut = s[i] - 'a';

        for (int j = tut+1 ;j<26;j++){
            if (mark[j]!=-1){
                cross++;
                mx = max(mark[j],mx);
            }
        }
        A[i] = mx+1;
        mark[tut] = max(mark[tut] , A[i]);
        ans = max(ans,A[i]);
    }

    cout << ans+1 << endl;
    for (int i=0;i<n;i++)cout << A[i]+1 << " ";
    cout << endl;


    return 0;
}

