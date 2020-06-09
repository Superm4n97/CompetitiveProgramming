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

#define maxn            100005

using namespace std;

int main()
{
    ll tc;
    cin >> tc;
    while(tc--){
        ll n;
        cin >> n;
        ll A[n+6] , B[n+7];
        memset(B,0,sizeof(B));

        map < ll , ll > mp;
        for (int i=1;i<=n;i++){
            cin >> A[i];
            mp[A[i]]++;
        }
        queue < ll > q;
        for (int i=1;i<=n;i++){
            if (mp[i]==0){
                q.push(i);
            }
        }
        B[1] = A[1];
        for (int i=2;i<=n;i++){
            if (A[i]==A[i-1] && q.front()<A[i]){
                B[i] = q.front();
                q.pop();
            }
            else {
                B[i] = A[i];
            }
        }
        if(!q.empty()){
            cout << -1 << endl;
        }
        else {
            for (int i=1;i<=n;i++){
                cout << B[i] << " ";
            }
            cout << endl;
        }

    }



    return 0;
}
