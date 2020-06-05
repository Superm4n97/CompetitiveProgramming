#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define show(x) cout << #x << " : " << x << endl
#define inf 100000000000000
#define maxn 20004

using namespace std;

int main()
{
    ll tc;
    scanf("%lld",&tc);

    for (int _t = 1;_t<=tc;_t++){
        ll n,m;
        scanf("%lld %lld",&n,&m);

        vector < ll > G[maxn];
        ll IN[maxn] , P[maxn] , parent = 0 , VIS[maxn] , inDegree[maxn] , outDegree[maxn] , A[maxn];
        ll in = 0, out = 0;

        memset(A,0,sizeof(A));
        memset(IN,0,sizeof(IN));
        memset(VIS,0,sizeof(VIS));
        memset(outDegree,0,sizeof(outDegree));

        for (int i=0;i<m;i++){
            ll a,b;
            scanf("%lld %lld",&a,&b);

            G[a].pb(b);
            IN[b]++;
        }

        for (int i=1;i<=n;i++){
            if (!VIS[i]){

                queue < ll > q;

                P[i] = ++parent;
                if (IN[i]==0)
                q.push(i);
                VIS[i] = 1;
                A[P[i]] = 1;

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

                        if (VIS[v] && P[v]!=P[i]){
                            inDegree[P[v]]++;
                            outDegree[P[i]]++;
                        }

                    }
                }
            }
        }



        for (int i=1;i<=parent;i++){
            if (!inDegree[i])in++;
            if (!outDegree[i])out++;
        }

        show(in);
        show(out);

        cout << "Case "<< _t << ": " << max(in,out) << endl;
    }


    return 0;
}
