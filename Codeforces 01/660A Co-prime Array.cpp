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
///4direction ->        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair

using namespace std;

ll a[1003],mark[1003];

bool prime(ll b, ll c)
{
    if (__gcd(b,c)>1)return true;
    return false;
}

int main()
{
    for (int i=0;i<1003;i++)mark[i]==0;
    ll n,cnt=0;
    cin >> n;
    for (int i=0;i<n;i++)cin >> a[i];
    for (int i=0;i<n-1;i++){
        if (prime(a[i],a[i+1]))mark[i]=1,cnt++;
    }
    cout << cnt << endl;
    for (int i=0;i<n;i++){
        cout << a[i] << " " ;
        if (mark[i])cout << 1 << " ";
    }

    return 0;
}
