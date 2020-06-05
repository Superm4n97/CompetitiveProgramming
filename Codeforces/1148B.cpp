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

ll A[200006], B[200006];

int main()
{
    ll n,m,ta,tb,k;
    cin >> n >> m >> ta >> tb >> k;
    for (int i=0;i<n;i++)scl(A[i]);
    for (int i=0;i<m;i++)scl(B[i]);

    bool ans = true;
    ll ptr = 0 , tut=B[k]+tb;

    if (m<=k || n<=k)ans = false;

    while(B[ptr]<A[0]+ta){
            ptr++;
        }
        tut=B[ptr]+tb;

    for (int i=1;i<n;i++){
        ll temp = A[i]+ta;
        if (k==0)break;
        k--;

        while(B[ptr]<temp){
            ptr++;
        }
        if (ptr+k>=m){
            ans = false;
        }
        else {
            tut = max(tut,B[ptr+k]+tb);
        }
        //cout << "   " << k << " " << ptr << "  " << i << endl;
    }
    if (!ans)cout << -1 << endl;
    else cout << tut << endl;

    return 0;
}
