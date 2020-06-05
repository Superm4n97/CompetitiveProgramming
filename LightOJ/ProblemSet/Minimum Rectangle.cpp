#include <bits/stdc++.h>
#define ll long long int
#define pb          push_back
#define srt(v)      sort(v.begin(),v.end())
#define rsrt        sort(v.rbegin(),v.rend())
#define vii         vector < int >
#define input(v,n)  for (int i=0;i<n;i++){int a;cin >>a;v.pb(a);}
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define scd(a)      scanf("%d",&a)
#define scl(a)      scanf("%lld",&a)
#define mk          make_pair

using namespace std;

int main()
{
    int n;
    scd(n);
    ll up = -1e16 , down = 1e16 , left = 1e16 , right = -1e16;
    //cout << up << " " << down << " " << left  << " " << right << endl;
    for (int i=0;i<n;i++){
        ll a,b;
        scl(a);
        scl(b);
        if (a>right)right = a;
        if (a<left)left = a;
        if (b>up)up = b;
        if (b<down) down = b;
    }
    printf("%lld %lld\n",left,up);
    printf("%lld %lld\n",right,up);
    printf("%lld %lld\n",right,down);
    printf("%lld %lld\n",left,down);

    return 0;
}
