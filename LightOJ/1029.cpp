#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 104

using namespace std;

vector < ll > G[maxn] , W[maxn];
vector < pair < ll , pair < ll , ll > > > vp;
ll P[maxn];

void clean()
{
    for (int i=0;i<103;i++){
        G[i].clear();
        W[i].clear();
        P[i] = i;
    }
    vp.clear();
}

ll findParent(ll a)
{
    if (P[a]==a)return a;
    return P[a] = findParent(P[a]);
}

int main()
{
    int tc;
    scanf("%d",&tc);

    for (int _t = 1 ; _t<=tc ; _t++){
        clean();
        ll n;
        scanf("%lld",&n);

        while(1){
            ll a, b, c;
            scanf("%lld %lld %lld",&a,&b,&c);
            if (!a && !b && !c)break;
            vp.push_back({c,{a,b}});
        }

        ll minimumCost = 0 , maximumCost = 0;

        sort(vp.begin(),vp.end());
        for (int i=0;i<vp.size();i++){
            ll c = vp[i].first , a = vp[i].second.first , b = vp[i].second.second;

            a = findParent(a);
            b = findParent(b);

            if (a!=b){
                P[a] = b;
                minimumCost+=c;
            }
        }
        ///.show(minimumCost);

        for (int i=0;i<=n ; i++)P[i] = i;

        sort(vp.rbegin(),vp.rend());
        for (int i=0 ; i<vp.size() ; i++){
            ll c = vp[i].first , a = findParent(vp[i].second.first) , b = findParent(vp[i].second.second);
            if (a!=b){
                P[a] = b;
                maximumCost+=c;
            }
        }
        ll ans = minimumCost+maximumCost;

        if (ans%2)printf("Case %d: %lld/2\n",_t,ans);
        else printf("Case %d: %lld\n",_t,ans/2);
    }


    return 0;
}
