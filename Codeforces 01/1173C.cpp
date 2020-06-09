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
#define inf8            100000008

using namespace std;

int A[200005] , B[200005];

int main()
{
    int n , mx = 0;
    cin >> n;

    for (int i=1;i<=n;i++)scd(A[i]);
    for (int i=1;i<=n;i++)scd(B[i]);

    bool ans = true;
    for (int i=1;i<=n;i++){
        if (B[i]!=i)ans = false;
    }
    if (ans){
        cout << 0 << endl;
        return 0;
    }


    bool zero = false;
    for (int i=1;i<n;i++){
        if (B[i]==0){
            zero = true;
            continue;
        }

        int temp = i-B[i]+1;
        if (temp<0)temp=0;

        mx = max(temp,mx);
    }

    if (B[n]==1){
        if (mx==0 && zero)mx = 0;
        else mx = n;
    }
    else {
        int temp = n-B[n]+1;
        if (temp<0)temp=0;

        mx = max(temp,mx);
    }


    return 0;
}
