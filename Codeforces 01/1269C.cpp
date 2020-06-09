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
#define inf8            100000000009

#define maxn            100005

using namespace std;

ll n,k;
string A , B;

void fix()
{
    ll ind = k-1;
    for (int i=ind ; i>=0;i--){
        if (B[i]=='9'){
            for (int j=i;j<n;j+=k)B[j] = '0';
        }
        else{
            for (int j=i;j<n;j+=k)B[j]++;
            return;
        }
    }
}

int main()
{
    cin >> n >> k;
    cin >> A;
    B =A;
    for (int i=0;i<k;i++){
        for (int j=i;j<n;j+=k)B[j] = A[i];
    }
    if (B<A)fix();

    cout << n << endl;
    for (int i=0;i<n;i++)cout << B[i];
    cout << endl;

    return 0;
}
