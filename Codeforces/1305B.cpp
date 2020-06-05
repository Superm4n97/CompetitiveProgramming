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

int main()
{
    string s;
    cin >> s;

    ll n = s.size();

    vll A,B;

    for (ll i=0;i<n;i++){
        if (s[i]=='(')A.pb(i);
    }
    for (ll i = n-1 ; i>=0;i--){
        if (s[i]==')')B.pb(i);
    }

    vll ans;

    for (int i=0;i<min(A.size() , B.size()) ; i++){
        if (A[i]<B[i]){
            ans.pb(A[i]);
            ans.pb(B[i]);
        }
    }
    if (!ans.empty())srt(ans);

    if (ans.empty()){
        cout << 0 << endl;
    }
    else {
        cout << 1 << endl;
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++)cout << ans[i]+1 << " ";
    cout << endl;
    }



    return 0;
}
