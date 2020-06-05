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
    vector < pii > v,ans;
    map < pii, int > mp;
    for (int i=0;i<3;i++){
        int a,b;
        cin >> a >> b;
        v.pb(mk(a,b));
        ans.pb(mk(a,b));
        mp[mk(a,b)]++;
    }
    srt(v);
    for (int i=v[0].first;i<=v[1].first;i++){
        int a = v[0].second;
        if (!mp[mk(i,a)]){
            mp[mk(i,a)]++;
            ans.pb(mk(i,a));
        }
    }
    int a = v[0].second, b= v[1].second,t = v[1].first;
    for (int i=min(a,b);i<=max(a,b);i++){
        if (!mp[mk(t,i)]){
            mp[mk(t,i)]++;
            ans.pb(mk(t,i));
        }
    }
    for (int i=v[2].first ; i>=t;i--){
        int p = v[2].second;
        if (!mp[mk(i,p)]){
            mp[mk(i,p)]++;
            ans.pb(mk(i,p));
        }
    }
    a = v[1].second,b= v[2].second;

    //cout << "ok 1" << endl;
    for  (int i=min(a,b);i<=max(a,b);i++){
        if (!mp[mk(t,i)]){
            mp[mk(t,i)]++;
            ans.pb(mk(t,i));
        }
    }

//    if (!mp[mk(t,v[2].second)]){
//            mp[mk(t,v[2].second)]++;
//            ans.pb(mk(t,v[2].second));
//    }
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++)cout << ans[i].first << " " <<ans[i].second << endl;

    return 0;
}
