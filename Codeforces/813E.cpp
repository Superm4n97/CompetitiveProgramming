#define show(x) cout << #x << " : " << x << endl
#define pb      push_back
#define ll      long long int
#define inf     10000000010
#define maxn    400005

#include<bits/stdc++.h>

using namespace std;

ll n,k,q , A[maxn];
map < ll , ll > mpSeg[maxn] , mpQuery[maxn];
ll segTree[maxn] , segTreeQuery[maxn];


void build(ll node, ll b, ll e)
{
    if (b==e){
        segTree[node] = 1;
        mpSeg[node][A[b]]++;

        return;
    }

    ll mid = (b+e)/2;
    build(node*2,b,mid);
    build(node*2+1,mid+1,e);

    if (mpSeg[node*2].size()>mpSeg[node*2+1].size()){
        mpSeg[node] = mpSeg[node*2];
        segTree[node] = segTree[node*2];

        map < ll , ll >::iterator it;
        for (it = mpSeg[node*2+1].begin(); it != mpSeg[node*2+1].end(); it++){
            /// tut = segTree[node]
            ///     a                       a          +            b                        k
        /// mpSeg[node][it->first] = min(mpSeg[node][it->first]+mpSeg[node*2+1][it->first] , k);
            segTree[node] += mpSeg[node*2+1][it->first];
            ll temp = mpSeg[node][it->first]+mpSeg[node*2+1][it->first];
            ll t1 = max(temp-k,0LL);
            segTree[node] -= t1;
            mpSeg[node][it->first] = min(mpSeg[node][it->first]+mpSeg[node*2+1][it->first] , k);
        }
    }
    else {
        mpSeg[node] = mpSeg[node*2+1];
        segTree[node] = segTree[node*2+1];

        map < ll , ll >::iterator it;
        for (it = mpSeg[node*2].begin(); it != mpSeg[node*2].end(); it++){
            segTree[node] += mpSeg[node*2][it->first];
            ll temp = mpSeg[node][it->first]+mpSeg[node*2][it->first];
            ll t1 = max(temp-k,0LL);
            segTree[node] -= t1;
            mpSeg[node][it->first] = min(mpSeg[node][it->first]+mpSeg[node*2][it->first] , k);
        }
    }

    return;
}

ll query(ll node, ll b, ll e, ll st, ll ed)
{
    mpQuery[node].clear();
    segTreeQuery[node] = 0;

    if (e<st || b>ed) return 0;

    if (st<=b && e<=ed){
        mpQuery[node] = mpSeg[node];
        segTreeQuery[node] = segTree[node];
        return segTreeQuery[node];
    }

    ll mid = (b+e)/2;
    query(node*2,b,mid,st,ed);
    query(node*2+1,mid+1,e,st,ed);

    if (mpQuery[node*2].size()>mpQuery[node*2+1].size()){
        mpQuery[node] = mpQuery[node*2];
        segTreeQuery[node] = segTreeQuery[node*2];

        map < ll , ll >::iterator it;
        for (it = mpQuery[node*2+1].begin(); it != mpQuery[node*2+1].end(); it++){
            segTreeQuery[node] += mpQuery[node*2+1][it->first];
            ll temp = mpQuery[node][it->first]+mpQuery[node*2+1][it->first];
            ll t1 = max(temp-k,0LL);
            segTreeQuery[node] -= t1;
            mpQuery[node][it->first] = min(mpQuery[node][it->first]+mpQuery[node*2+1][it->first] , k);
        }
    }
    else {
        mpQuery[node] = mpQuery[node*2+1];
        segTreeQuery[node] = segTreeQuery[node*2+1];

        map < ll , ll >::iterator it;
        for (it = mpQuery[node*2].begin(); it != mpQuery[node*2].end(); it++){
            segTreeQuery[node] += mpQuery[node*2][it->first];
            ll temp = mpQuery[node][it->first]+mpQuery[node*2][it->first];
            ll t1 = max(temp-k,0LL);
            segTreeQuery[node] -= t1;
            mpQuery[node][it->first] = min(mpQuery[node][it->first]+mpQuery[node*2][it->first] , k);
        }
    }

    return segTreeQuery[node];
}

int main()
{
    scanf("%I64d %I64d",&n,&k);
    for (int i=1;i<=n;i++)scanf("%I64d",&A[i]);
    build(1,1,n);

    scanf("%I64d",&q);
    ll last = 0;
    for (int i=0;i<q;i++){
        ll a,b;
        scanf("%I64d %I64d",&a,&b);
        a = ((a+last)%n)+1;
        b = ((b+last)%n)+1;
        if (a>b)swap(a,b);



        last = query(1,1,n,a,b);
        printf("%I64d\n",last);
    }


    return 0;
}
