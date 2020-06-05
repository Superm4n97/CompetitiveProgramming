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
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair

using namespace std;

ll n,m;
priority_queue < pair < ll , ll > > vp;
map < ll , ll > mp,cost;
vll ans;

int main()
{
    cin >> n >> m;
    for (int i=0;i<n;i++){
        ll a;
        cin >> a;
        mp[i] = a;
    }
    for (int i=0;i<n;i++){
        ll c;
        cin >> c;
        cost[i]=c;
        vp.push(mk(c*-1,i*-1));
    }

    for (int i=0;i<m;i++){
        ll ii,pp,cst=0;
        cin >> ii >> pp;
        ii--;
        ll mn = min(pp,mp[ii]);
        mp[ii]-=mn;
        cst+=(mn)*cost[ii];
        pp-=mn;
        //cout << "mn " << mn << "    pp " << pp << endl;
            while(pp){
                if (vp.empty()){
                    cst = 0;
                    break;
                }
                ll c = vp.top().first*-1;
                ll iii = vp.top().second*-1;
                if (!mp[iii]){
                    vp.pop();
                    continue;
                }
                ll mnn = min(mp[iii],pp);
                mp[iii]-=mnn;
                pp-=mnn;
                cst+=mnn*c;
            }
        ans.pb(cst);
    }
    for (int i=0;i<ans.size();i++)cout << ans[i] << endl;

    return 0;
}
