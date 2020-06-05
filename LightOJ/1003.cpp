#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define show(x) cout << #x << " : " x << endl
#define inf 100000000000000
#define maxn 10004

using namespace std;

int main()
{
    ll tc;
    scanf("%lld",&tc);

    for (int _t = 1 ; _t<=tc ; _t++){

        ll n , indexing = 0 , IN[maxn];
        map < string , ll > mp;
        vector < ll > G[maxn];

        scanf("%lld",&n);

        memset(IN,0,sizeof(IN));

        for (int i=0;i<n;i++){
            string a,b;
            cin >> a >> b;

            if (!mp[a])mp[a] = ++indexing;
            if (!mp[b])mp[b] = ++indexing;

            ll aa = mp[a] , bb = mp[b];
            G[aa].pb(bb);
            IN[bb]++;
        }

        //show(indexing);
        //cout << " : " << indexing << endl;

        queue < ll > q;
        for (int i=1;i<=indexing;i++){
            if (IN[i]==0)q.push(i);
        }

        ll cnt = 0;

        while(!q.empty()){
            ll u = q.front();
            q.pop();

            cnt++;

            for (int i=0;i<G[u].size();i++){
                ll v = G[u][i];

                IN[v]--;
                if (IN[v]==0)q.push(v);
            }
        }

        if (cnt==indexing)cout << "Case "<< _t << ": Yes" << endl;
        else cout << "Case "<< _t << ": No" << endl;

    }


    return 0;
}
