#include <bits/stdc++.h>
#define pb(a)           push_back(a)
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%lld",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%lld %lld",&a,&b)
///4direction ->        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair
#define inf             1000000000

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for (int _t=1;_t<=tc;_t++){
        ll k;
        cin >> k;

        ll b = 0 , e = inf , ans = inf;
        while(b<=e){
            ll n = (b+e)/2 , tut = 5 , p=0;
            while(n/tut){
                p+=n/tut;
                tut*=5;
            }
            if (p>=k){
                if (p==k)ans=min(n,ans);
                e=n-1;
            }
            else {
                b = n+1;
            }
        }
        if (ans == inf){
            cout << "Case "<< _t <<": impossible" << endl;
        }
        else cout << "Case "<< _t<<": "<< ans << endl;
    }

    return 0;
}
