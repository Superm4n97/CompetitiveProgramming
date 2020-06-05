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
#define inf             10000000000000016

#define maxn            300005

using namespace std;

priority_queue < pair < ll , ll > > pq;
vector < pair < ll ,ll > > v;
vector < ll > B,A;
map < ll , ll > mp;

int main()
{
    ll n;
    cin >> n;

    for (int i=0;i<n;i++){
        ll a;
        cin >> a;
        A.pb(a);
        mp[a]++;
    }
    for (int i=0;i<n;i++){
        ll a;
        cin >> a;
        v.pb({A[i],a*-1});
    }
    srt(v);
    srt(A);

    ll temp = -1;

    for (int i=0;i<n;i++){
        for (int j=0;j<mp[A[i]];j++){
            B.pb(max(temp,A[i]));
            temp = max(temp,A[i])+1;
        }
        mp[A[i]] = 0;
    }
    srt(B);

    ll ans = 0 ,currentIndex = 0;

    for (int i=0;i<n;i++){
        while(v[currentIndex].first<=B[i]){
            if (currentIndex==n)break;
            pq.push({v[currentIndex].second*-1 , v[currentIndex].first});
            currentIndex++;
        }
//        show(i);
//        show(B[i]);
//        show(pq.top().first);
//        show(pq.top().second);
//        cout << endl;

        ans += pq.top().first*(B[i] - pq.top().second);
        pq.pop();
    }
    cout << ans << endl;


    return 0;
}
