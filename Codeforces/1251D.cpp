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

int main()
{
    ll tc;
    scl(tc);
    while(tc--){
        ll n,s , ans = 0;
        scll(n,s);
        vector < pair < ll , ll > > vp;
        for (int i=0;i<n;i++){
            ll a,b;
            scll(a,b);
            vp.pb({a,b});
        }

        ll b = 0 , e  = s;
        while(b<=e){
            ll mid = (b+e)/2;
            ll cost = 0;
            bool sol = true;

            vector < pair < ll , ll > > v;
            //vll v;
            ll sum1 = 0 , sum2 = 0;
            ll cnt1= 0 , cnt2 = 0;

           // show(mid);

            for (int i=0;i<n;i++){
                if (vp[i].second>=mid){
                    sum2+=max(vp[i].first , mid);
                    v.pb({vp[i].first,max(vp[i].first,mid)});
                    cnt2++;
                }
                else {
                    sum1+=vp[i].first;
                    cnt1++;
                }
            }
            srt(v);
            for (int i=0;i<n/2-cnt1;i++){
                sum1+=v[i].first;
                sum2-=v[i].second;
            }
           // show(sum1);
           // show(sum2);

            if (cnt1>n/2 || sum1+sum2>s){
                e = mid-1;
            }
            else{
                b = mid+1;
                ans = max(ans , mid);
            }
        }
        cout << ans << endl;
    }



    return 0;
}
