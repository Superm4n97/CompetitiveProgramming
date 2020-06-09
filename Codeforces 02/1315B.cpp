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
    ll tc;
    cin >> tc;
    while(tc--){
        ll a,b,p;
        cin >> a >> b >> p;
        string s;
        cin >> s;
        ll n = s.size();

        /*ll currentIndex = 1,A[n+5];
        A[1] = s[0] - 'A';
        for (int i=1;i<n-1;i++){
            if (s[i]!=s[i-1]){
                currentIndex++;
                A[currentIndex] = s[i] - 'A';
            }
        }*/

        ll A[n+10] , ans = n-1;
        memset(A,0,sizeof(A));

        for (int i = n-2;i>=0;i--){
            if (i==0){
                if (s[i]=='A')A[i] = A[i+1]+a;
                else A[i] = A[i+1]+b;
                if (A[i]<=p)ans = i;
            }
            else {
                if (s[i]!=s[i-1]){
                    if (s[i]=='A')A[i] = A[i+1]+a;
                    else A[i] = A[i+1]+b;
                    if (A[i]<=p)ans = i;
                }
                else {
                    A[i] = A[i+1];
                    //if (A[i]<=p)ans = i;
                }
            }
            //show(A[i]);
        }
        cout << ans+1 << endl;

    }


    return 0;
}

