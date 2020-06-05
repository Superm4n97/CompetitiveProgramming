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

ll calculation(ll n)
{
    if (n<0)return 0 ;
    return (n*(n+1))/2;
}

ll A[100005];

int main()
{
    ll k , n , tut = 0;
    cin >> k >> n;

    ll b = 0 , e = 10000000000;
    while(b<=e){
        ll mid = (b+e)/2;
        if (calculation(mid)-calculation(mid-n) <= k){
            tut = max(tut,mid);
            b = mid+1;
        }
        else e = mid-1;
    }

    ll temp = k - calculation(tut)+calculation(tut-n);
   // cout << "ok 1  " << temp << endl;

    for (int i=n;i>=1;i--){
        A[i] = tut;
        tut--;
    }
    for (int i=n;i>=2;i--){
        A[i] += min(A[i-1]-1 , temp);
        temp -= min(A[i-1]-1 , temp);
    }
    A[1]+=temp;


//    for (int i=1;i<=n;i++)cout << A[i] << " ";
//        cout << endl;

    bool ans = true;
    for (int i=2;i<=n;i++){
        if (A[i]<=A[i-1] || A[i]>2*A[i-1])ans = false;
    }

    if (!ans){
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for (int i=1;i<=n;i++)cout << A[i] << " ";
        cout << endl;
    }

    return 0;
}

