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

ll n, A[maxn] , B[maxn];
ll pos = 0, neg = 0;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> A[i];
        B[i] = A[i]/2;
        if (B[i]>0)pos+=B[i];
        else neg+=(B[i]*-1);
    }
    for (int i=0;i<n;i++){
        if (pos==neg)break;
        if (A[i]%2 != 0){
            if (pos<neg && A[i]>0){
                B[i]++;
                pos++;
            }
            if (neg<pos && A[i]<0){
                B[i]--;
                neg++;
            }
        }
    }
    for (int i=0;i<n;i++){
        cout << B[i] << endl;
    }



    return 0;
}
