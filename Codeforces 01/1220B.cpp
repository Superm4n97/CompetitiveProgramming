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
#define mk              make_pair
#define inf8            100000008
#define maxn            1003

using namespace std;

ll n , g = -1 , ans;
ll A[maxn][maxn];


int main()
{
    scl(n);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            scl(A[i][j]);
        }
    }
    for (int i=2;i<=n;i++){
        if(g==-1)g = A[1][i];
        else g = __gcd(g,A[1][i]);
    }

    vll divisor;
    divisor.pb(1);
    divisor.pb(g);
    //cout << "   g=" << g << endl;
    ll lim = sqrt(g)+1 , temp = g;

    for (int i=2;i<=lim;i++){
        if (g%i==0){
            divisor.pb(i);
            divisor.pb(g/i);
        }
    }

    for (int i=0;i<divisor.size();i++){
        bool solution = true;

        for (int j=3;j<=n;j++){
            if (A[1][j]/divisor[i]*A[1][j-1]/divisor[i] != A[j-1][j])solution = false;
        }
        if (solution)ans = divisor[i];
    }
    cout << ans << " ";
    for (int i=2;i<=n;i++){
        cout << A[1][i]/ans << " ";
    }
    cout << endl;





    return 0;
}
