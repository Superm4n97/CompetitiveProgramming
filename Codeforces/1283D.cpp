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

#define maxn            200005

using namespace std;

ll n,m,A[maxn];
map < ll , ll > mp;
queue < pll > q;

void pushIt(ll a, ll c)
{
    if (mp[a+1]==0){
        q.push({c+1,a+1});
        mp[a+1] = 1;
    }
    if (mp[a-1]==0){
        q.push({c+1,a-1});
        mp[a-1] = 1;
    }

    return;
}

ll ans =  0, B[maxn];

int main()
{
    cin >> n >> m;
    for (int i=0;i<n;i++){
        ll a;
        cin >> a;
        mp[a] = 1;
        A[i] = a;
    }
    for (int i=0;i<n;i++){
        pushIt(A[i],0);
    }

    for (int i=0;i<m;i++){
        ll a = q.front().second , c = q.front().first;
        q.pop();

//        show(a);
//        show(c);
//        cout << endl;

        ans+=c;
        B[i] = a;
        pushIt(a,c);
    }

    cout << ans << endl;
    for (int i=0;i<m;i++)cout << B[i] << " ";
    cout << endl;


    return 0;
}
