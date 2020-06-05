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

#define maxn            400005

using namespace std;

int main()
{
    ll tc;
    scl(tc);

    while(tc--){
        ll n,k;
        scll(n,k);
        ll A[n+5];

        for (int i=1;i<=n;i++)scl(A[i]);

        ll ans = 0 , b = 1 , e = 100000000000012;
        while(b<=e){
            ll mid = (b+e)/2;
            ll prev = 0 , row = 0;

            for (int i=1;i<=n;i++){
                ll a = A[i];
                ll temp = mid - prev;
                if (a>=temp){
                    a-=temp;
                    row++;
                    prev = 0;
                }
                row+=(a/mid);
                prev = a%mid;
//                show(A[i]);
//                show(row);
//                show(prev);
            }

            //cout << "for mid : "<< mid << "   row : " << row << endl;

            if (row>=k){
                ans = max(mid,ans);
                b = mid+1;
            }
            else e = mid-1;
        }
        printf("%I64d\n",ans*k);

    }



    return 0;
}
