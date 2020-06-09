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
#define mk              make_pair
#define inf8            100000008

using namespace std;

int main()
{
    int tc;
    scd(tc);
    while(tc--){
        ll n ,k;
    cin >> n >> k;
    if (n==0){
        cout << "Bob" << endl;
        continue;
    }
    bool ans = true;

    if (n%3==0){

    }
    if ((n-(n/k))%k==0 || (n-(n/k))%k==0 || (n-(n/k))%k==0){
        cout << "Bob" << endl;
        continue;
    }
    if ((n+(n/k))%3==0){
        cout << "Bob" << endl;
        continue;
    }
    cout << "Alice" << endl;
    }

    return 0;
}
