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
#define inf             10000000000000016

#define maxn            1000006

using namespace std;

ll mp[400] , A[400] , B[400];

int main()
{
    ll tc;
    cin >> tc;
    while(tc--){
        ll n;
        cin >> n;

        bool ans = true;

        memset(mp,0,sizeof(mp));
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));

        for (int i=1;i<=n;i++){
            cin >> B[i];
            mp[B[i]]++;
            if (mp[B[i]]>=2)ans = false;
        }
        priority_queue < ll > pq;
        for (int i=1;i<=2*n;i++){
            if (!mp[i]){
                pq.push(i*-1);
            }
        }

        for (int i=1 ; i<=n;i++){
            A[2*i-1] = B[i];

            vector < ll > v;
            while(!pq.empty()){
                if (pq.top()*-1>B[i]){
                    A[2*i] = pq.top()*-1;
                    pq.pop();
                    break;
                }
                else {
                    v.pb(pq.top());
                    pq.pop();
                }
            }
            for (int i=0;i<v.size();i++){
                pq.push(v[i]);
            }
            if (A[2*i]==0)ans = false;
        }
        if (!ans)cout << -1 << endl;
        else{
            for (int i=1;i<=2*n;i++)cout << A[i] << " ";
            cout << endl;
        }

    }



    return 0;
}
