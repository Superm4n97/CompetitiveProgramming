#include<bits/stdc++.h>

#define ll long long int
#define maxn 100005
#define scd(a) scanf("%lld",&a)

using namespace std;

ll S[4*maxn+3] , lazy[4*maxn+3];
string s;
ll n,q;

void refresh(ll node)
{
    lazy[node*2] += lazy[node];
    lazy[node*2+1] += lazy[node];
    lazy[node*2] %= 2;
    lazy[node*2+1] %= 2;
    lazy[node] = 0;

    return;
}

void build(ll node, ll b, ll e)
{
    if (b==e){
        S[node] = s[b] - '0';
        return;
    }
    ll mid = (b+e)/2;

    build(node*2,b,mid);
    build(node*2+1,mid+1,e);
}

void update(ll node, ll b, ll e , ll x, ll y)
{
   // cout << "  " << node << " " << b << " " << e << endl;
    if (b>y || e<x)return;

    if (b>=x && e<=y){
        lazy[node]++;
        lazy[node] %= 2;
        return;
    }

    ll mid = (b+e)/2;
    refresh(node);
    update(node*2,b,mid,x,y);
    update(node*2+1,mid+1,e,x,y);

    return;
}

ll query(ll node, ll b, ll e, ll index)
{
    if (b==e){
        if (b==index){
            S[node] = (S[node]+lazy[node])%2;
            lazy[node] = 0;
            return S[node];
        }
        return 0;
    }
    if (b>index || e<index)return 0;
    ll mid = (b+e)/2;

    refresh(node);

    return query(node*2,b,mid,index) | query(node*2+1 , mid+1,e,index);
}

int main()
{
    ll tc;
    scd(tc);
    for (int _t=1;_t<=tc;_t++){
        printf("Case %d:\n",_t);
        cin >> s;
        n = s.size()-1;
        for (int i=0;i<4*n+1;i++)lazy[i] = 0;
        //memset(lazy,0,sizeof(lazy));

        build(1,0,n);

        scd(q);
        while(q--){
            char ch;
            cin >> ch;
            if (ch=='I'){
                ll a, b;
                scd(a);
                scd(b);
                a-- , b--;
                update(1,0,n,a,b);
            }
            else {
                ll a;
                scd(a);
                printf("%lld\n",query(1,0,n,a-1));
            }
        }

    }


    return 0;
}
