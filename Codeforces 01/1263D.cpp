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

ll check[30] , n;
ll P[30];

ll findParent(ll a)
{
    if (P[a]==a)return a;
    return P[a] = findParent(P[a]);
}

void makeParent(ll a, ll b)
{
    a = findParent(a);
    b = findParent(b);
    if (a!=b){
        P[a] = b;
    }
}

ll ans = 0 ;

int main()
{
    for (int i=0;i<30;i++)P[i] = i;
    cin >> n;
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        for (int j=0;j<s.size();j++){
            ll a = s[j] - 'a';
            check[a] = 1;
        }
        for (int j = 1;j<s.size();j++){
            ll a = s[j]-'a';
            ll b = s[j-1] - 'a';
            makeParent(a,b);
        }
    }

    map < ll , ll > mp;

    for (int i=0;i<29;i++){
        if (check[i]==1){
            ll a = findParent(i);
            if (mp[a]==0){
                mp[a]++;
                ans++;
            }
        }
    }
    cout << ans << endl;



    return 0;
}
