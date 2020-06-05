#include <bits/stdc++.h>
#define pb(a)           push_back(a)
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
#define mk              make_pair

using namespace std;

int X[1005],Y[1005],A[1005],B[1005];

map < pii, int > mp;

int main()
{
    int n;
    cin >> n;
    for (int i=0;i<n;i++)cin >> X[i] >> Y[i];
    for (int i=0;i<n;i++)cin >> A[i] >> B[i];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            int a = X[i]+A[j] , b=Y[i]+B[j];
            mp[mk(a,b)]++;
            if (mp[mk(a,b)]==n){
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }

    return 0;
}
