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

#define maxn            100005

using namespace std;

string s;
ll n , A[maxn][30] , ans = 0;
vector < ll > V[30];

int main()
{
    cin >> s;
    n = s.size();

    for (int i=0;i<n;i++){
        ll temp = s[i]-'a';
        V[temp].pb(i);
    }
    for (int i = n-1 ; i>=0 ; i--){
        for (int j=0;j<27;j++){
            A[i][j] = A[i+1][j];
        }
        ll temp = s[i]-'a';
        A[i][temp]++;
    }
    for (int i=0;i<26;i++)ans = max(ans,(ll)V[i].size());

    for (int i=0;i<26;i++){
        for (int j=0;j<26;j++){

            ll tut = 0;
            for (int k = 0 ; k<V[i].size(); k++){
                ll ind = V[i][k];
                tut+=(A[ind+1][j]);
            }
            ans = max(ans,tut);
        }
    }
    cout << ans << endl;



    return 0;
}
