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

#define maxn            100005

using namespace std;

ll ans;

int main()
{
    ll tc;
    cin >> tc;
    while(tc--){
        ans = 0;

        ll n, p,k;
        cin >> n >> p >> k;
        vll A;
        for (int i=1;i<=n;i++){
            ll a;
            cin >> a;
            A.pb(a);
        }
        srt(A);

        ll b = 1 , e = n , temp = 0;

        while(b<=e){
            ll mid = (b+e)/2;
            ll sum = 0;

            //show(mid);
            if (k*mid>n){
                e = mid-1;
                continue;
            }
            //show(mid);

            for (int i=mid*k-1;i>=0;i-=k){
                sum+=A[i];
            }

            if (sum<=p){
                temp = max(temp,mid);
                b = mid+1;
            }
            else e = mid-1;
        }

        ll csum = 0;
        ans = temp*k;

        //show(temp);

        for (int i=0;i<k-1;i++){
            csum += A[i];
            ll sum = csum;

            if (i+k*temp>=n)break;

            for (int j= i+k;j<=i+k*temp;j+=k){
                sum+=A[j];
            }
            //show(sum);
            if (sum<=p){
                ans = i+k*temp+1;
            }
        }

        cout << ans << endl;
    }


    return 0;
}
