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

#define maxn            500005

using namespace std;

vector < pll > v;
ll n;
ll P[maxn] , MX[4*maxn] , MN[4*maxn];

void build(ll node, ll b, ll e)
{
    if (b==e){
        //S[node] = v[b].second;
        MX[node] = v[b].second;
        MN[node] = v[b].second;
        return;
    }

    ll mid = (b+e)/2;
    build(node*2 , b , mid);
    build(node*2+1 , mid+1 , e);

    MX[node] = max(MX[node*2] , MX[node*2+1]);
    MN[node] = min(MN[node*2] , MN[node*2+1]);
}

ll findParent(ll a)
{
    if (P[a]==a)return a;
    return P[a] = findParent(P[a]);
}

void makeParent(ll a, ll b)
{
    a = findParent(a);
    b = findParent(b);
    if (a!=b)P[a] = b;
}

ll query(ll node , ll b, ll e , ll val , ll x, ll y,ll parent)
{
    if (e<x || b>y)return 0;

    if (b>=x && e<=y){
        if (MX[node]<val)return 0;
        if (MN[node]>val){
            //show(b);
            for (int i=b;i<=e;i++)makeParent(i,parent);
            return e-b+1;
        }
        ll mid = (b+e)/2;
        return query(node*2,b,mid,val,x,y,parent)+query(node*2+1,mid+1,e,val,x,y,parent);
    }

    ll mid = (b+e)/2;
    return query(node*2,b,mid,val,x,y,parent)+query(node*2+1,mid+1,e,val,x,y,parent);
}

ll BS(ll a)
{
    ll val = v[a].second;
    ll b = a , e = n-1 , ind = -1;

    while(b<=e){
        ll mid = (b+e)/2;
        if (v[mid].first<val){
            ind = max(ind,mid);
            b = mid+1;
        }
        else e = mid-1;
    }
    return ind;
}

bool query2(ll node , ll b, ll e, ll val , ll x, ll y)
{
    if (e<x || b>y)return false;
    if (b>=x && e<=y){
        if (MN[node]<val)return true;
        return false;
    }
    ll mid = (b+e)/2;
    return query2(node*2,b,mid,val,x,y) | query2(node*2+1,mid+1,e,val,x,y);
}

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        ll l, r;
        cin >> l >> r;
        v.pb({l,r});
    }

    for (int i=1;i<=n;i++)P[i] = i;

    if (n==1){
        cout << "YES" << endl;
        return 0;
    }

    srt(v);

    build(1,0,n-1);

    ll edge = 0;

    for (int i=0 ; i<n;i++){
        ll ind = BS(i);

        if (ind==i){
            if (i==0){
//                show("  1");
                cout << "NO" << endl;
                return 0;
            }
            if (!query2(1,0,n-1,v[i].second,0,i-1)){
//                show("  2");
                cout << "NO" << endl;
                return 0;
            }

        }
        else {
            ll temp = query(1,0,n-1,v[i].second,i+1,ind,i);

//            show(i);
//            show(ind);
//            show(temp);
//            cout << endl;

            edge+=temp;
        }
        if (edge>=n){
//            show("  3");
//            show(edge);
            cout << "NO" << endl;
            return 0;
        }
    }

    ll cnt = 0 , pr;
    for (int i=0;i<n;i++){
        ll a = findParent(i);
        if (cnt==0)cnt++ , pr = a;
        else if (cnt==1 && a!=pr){
            cout << "NO" << endl;
            return 0;
        }

    }

    if (edge==n-1)cout << "YES" << endl;
    else cout << "NO"<< endl;


    return 0;
}
