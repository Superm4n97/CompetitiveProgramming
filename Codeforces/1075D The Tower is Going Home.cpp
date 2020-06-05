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

vector < ll > bar;
map < ll , ll > mp;

ll binarySearch(ll a)
{

}

int main()
{
    ll n,m,paisi1=0, paisi2=0;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        ll a;
        cin >> a;
        if (a==1)paisi1=1;
        if (a==1000000000)paisi2=1;
        bar.pb(a);
    }
    if (!paisi1)bar.pb(1);
    if (!paisi2)bar.pb(1000000000);
    srt(bar);
    for (int i=0;i<m;i++){
        ll a,b,c;
        cin >> a >> b >> c;

        ll bb = 0, e = bar.size()-1,mid,temp1, temp2;
        while(bb<=e){
            mid = (bb+e)/2;
            if (bar[mid]>=a){
                e = mid-1;
                temp1=min(mid,temp1);
            }
            else bb=mid+1;
        }
        bb = 0, e = bar.size()-1;
        while(bb<=e){
            mid = (bb+e)/2;
            if (bar[mid]<=b){
                bb = mid+1;
                temp2=max(mid,temp2);
            }
            else e=mid-1;
        }

        mp[bar[temp1]]++;
        mp[bar[temp2]]--;
    }
    ll ans = 10000000000000;
    for (int i=1;i<bar.size();i++)mp[bar[i]]+= mp[bar[i-1]];
    for (int i=0;i<bar.size();i++){
        mp[bar[i]]+=i;
        ans=min(ans,mp[bar[i]]);
    }
    cout << ans << endl;


    return 0;
}
