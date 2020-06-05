#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define show(x) cout << #x << " : " x << endl;
#define inf 100000000000000
#define maxn 10004

using namespace std;

int main()
{
    ll tc;
    scanf("%lld",&tc);
    for (int _t=1;_t<=tc;_t++){
        ll n,m;
        scanf("%lld %lld",&n,&m);

        ll VIS[maxn] , IN[maxn] , inDegree[maxn] , A[maxn], cnt = 0 , P[maxn] , Parent = 1;
        vector < ll > G[maxn] , H[maxn];
        vector < pair < ll , ll > > E;
        map < pair < ll, ll > , ll > mp_check;
        map < ll , ll > mp;

        memset(VIS,0,sizeof(VIS));
        memset(IN,0,sizeof(IN));
        memset(A,0,sizeof(A));
        memset(inDegree,0,sizeof(inDegree));
        for (int i=0;i<n+2;i++)P[i] = i;

        for (int i=0;i<m;i++){
            ll a, b;
            scanf("%lld %lld",&a,&b);
            G[a].pb(b);
            inDegree[b]++;
        }

        for (int i=1;i<=n;i++){

            if (!VIS[i]){

                queue < ll > q;
                q.push(i);
                VIS[i] = 1;
                P[i] = Parent;
                Parent++;

                if (!inDegree[i]){
                    A[P[i]] = 1;
                }

                while(!q.empty()){
                    ll u = q.front();
                    q.pop();

                    for (int j=0;j<G[u].size();j++){
                        ll v = G[u][j];

                        if (!VIS[v]){
                            VIS[v] = 1;
                            q.push(v);
                            P[v] = P[i];
                        }

                        if (VIS[v] && P[v]!=P[i] && !A[P[v]]){
                            E.pb({P[i],P[v]});
                            IN[P[v]]++;
                        }
                    }
                }
            }
        }

        for (int i=1;i<Parent;i++){
            if (IN[i]==0)cnt++;
        }


        printf("Case %d: %lld\n",_t,cnt);
    }



    return 0;
}
