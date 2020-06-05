#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define show(x) cout << #x << " : " << x << endl

using namespace std;

vector < ll > G[5005] ;
vector < pair < ll , pair < ll , ll > > > v;

//map < pair < ll ,ll > , ll > index;
ll index[5005][5005];

bool ans = true;
ll P[5005] , val[5005];

ll dfs(ll s, ll p , ll d , ll cost)
{
    if (s==d)return 1;

    ll lim = G[s].size();
    for (int i=0;i<lim;i++){
        ll u = G[s][i];
        if (u==p)continue;

        P[u] = s;
        ll var = dfs(u,s,d,cost);

        if (var>0){
            if (val[index[s][u]] == -1 || val[index[s][u]]==cost) val[index[s][u]] = cost , var++;
            return var;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(val,-1,sizeof(val));

    ll n;
    //cin >> n;
    scanf("%lld",&n);

    for (int i=1;i<n;i++){
        ll a, b;
        //cin >> a >> b;
        scanf("%lld %lld",&a,&b);

        if (a>b)swap(a,b);

        G[a].pb(b);
        G[b].pb(a);
        index[a][b] = i;
        index[b][a] = i;
    }
    ll q;
    //cin >> q;
    scanf("%lld",&q);
    for (int i=0;i<q;i++){
        ll a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        if (a>b)swap(a,b);
        v.pb({c,{a,b}});
    }
    sort(v.rbegin(),v.rend());

    for (int i=0;i<q;i++){

        if (i>0 && v[i]==v[i-1])continue;

//        cout << v[i-1].first << " " << v[i-1].second.first << " " << v[i-1].second.second << endl;
//        cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << endl;
//        show(i);

        //for (int j=0;j<=n+1;j++)P[j] = j;

        ll s = v[i].second.first , d = v[i].second.second , cost = v[i].first;

        ll temp = dfs(s,0,d,cost);

        if (temp<2){
            printf("-1\n");
            return 0;
        }

        /*ll temp = d , tut , cnt = 0;

        while(temp!=s){
            tut = P[temp];
            ll ind = index[{temp,tut}];

            if (val[ind]==-1)val[ind] = cost , cnt++;
            else {
                if (val[ind] > cost){
                    //ans = false;

                    //show(cost);
                    //show(ind);
                    //show(val[ind]);
                }
                else val[ind] = cost , cnt++;
            }
            temp = tut;
        }
        if (cnt==0){
            ans = false;
            printf("-1\n");

            return 0;
        }*/
    }

    for (int i = 1 ; i<n;i++){
        if (val[i]==-1)val[i] = 1;
        //cout << val[i] << " ";
        printf("%lld ",val[i]);
    }
    printf("\n");

    return 0;
}
