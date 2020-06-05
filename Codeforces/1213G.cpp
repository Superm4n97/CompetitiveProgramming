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
#define mk              make_pair
#define inf8            100000008
#define maxn            200005

using namespace std;

ll n,m;
vector < pair < ll , pair < ll ,ll > > > v;
vector < pll > vec;
ll SZ[maxn] , P[maxn];

ll findParent(ll a)
{
    if (P[a]==a)return a;
    return P[a] = findParent(P[a]);
}

void makeParent(ll a, ll b)
{
    a = findParent(a);
    b = findParent(b);
    if(a==b)return;
    P[a] = b;
    SZ[b]+=SZ[a];
}

int main()
{
    for (ll i=0;i<maxn;i++)SZ[i] = 1 , P[i] = i;

    scll(n,m);
    for (ll i=1;i<n;i++){
        ll a,b,c;
        scll(a,b);
        scl(c);

        v.pb({c,{a,b}});
    }
    srt(v);
    v.pb({-1 , { 1, 1}});

    for (ll i=0;i<n-1;i++){
        ll j= i;
        while(v[i].first == v[j].first){
            makeParent(v[j].second.first,v[j].second.second);
            j++;
        }

        j = i;

        map < ll , ll > mp;
        ll cnt = 0;
        while(v[i].first == v[j].first){
            ll a = v[j].second.first , b = v[j].second.second;
            a = findParent(a);
            if (!mp[a]){
                mp[a] = 1;
                ll temp = SZ[a];
                ll tut = temp*(temp-1)/2;
                cnt += tut;
            }
            j++;
        }
        vec.pb({v[i].first , cnt});
        i = j-1;
    }

    for (ll i=0;i<m;i++){
        ll a;
        scl(a);

        ll beg = 0 , ed = vec.size()-1 , index = 0;
        //cout << vec.size() << endl;
        if (vec.empty())ed = -1;
        while(beg <= ed){
            //cout << "   " << beg << " "<< ed << endl;
            ll mid = (beg+ed)/2;

            if (vec[mid].first <= a){
                index = max(index, vec[mid].second);
                beg = mid+1;
            }
            else ed = mid-1;
        }
        cout << index << " ";
    }


    return 0;
}

