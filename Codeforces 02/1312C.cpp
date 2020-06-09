#include<bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%lld",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%lld %lld",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair
#define inf8            10000000000000002
#define printCaseAnsInt(t,ans)  printf("Case %d: %d",t,ans)
#define printCaseAnsLL(t,ans)  printf("Case %lld: %lld",t,ans)
#define mod             1000000007
#define maxn            2000005;

using namespace std;

int main()
{
    ll tc;
    cin >> tc;
    while(tc--){
        ll n,k;
        scll(n,k);
        vll P;
        bool ans = true;

        ll temp = 1 , cnt[100];
        memset(cnt,0,sizeof(cnt));

        for (int i=0;temp<inf8;i++){
            P.pb(temp);
            temp*=k;
        }

        for (int i=0;i<n;i++){
            ll a;
            scl(a);
            if (!a)continue;

            for (int j = P.size()-1 ; j>=0 ; j--){
                if (a>=P[j]){
                    a-=P[j];
                    cnt[j]++;
                    if (cnt[j]>=2)ans = false;
                }
            }
        }
        if (ans)printf("YES\n");
        else printf("NO\n");
    }


    return 0;
}
