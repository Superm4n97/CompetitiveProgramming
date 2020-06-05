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

int main()
{
    ll n,k,mn=100000000000000000;
    cin >> n >> k;
    ll lm = sqrt(n)+2;
    for (int i=1;i<=lm;i++){
        if (n%i==0){
            ll a = n/i;
            ll b = i;
            if (mn>a*k+b && b<k){
                mn = min(a*k+b,mn);
                //cout << a << " " << b << endl;
            }
            swap(a,b);
            if (mn>a*k+b && b<k){
                mn = min(a*k+b,mn);
                //cout << a << " " << b << endl;
            }
        }
    }
    cout << mn  << endl;

    return 0;
}
