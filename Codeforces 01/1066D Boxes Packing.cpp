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

ll arr[200004];

int main()
{
    ll n,m,k;
    scll(n,m),scl(k);
    for (int i=0;i<n;i++)scl(arr[i]);
    ll temp = 0 , cnt = 1 , item = 0;
    for (int i=n-1;i>=0;i--){
        if (temp+arr[i]>k){
            cnt++;
            temp=0;
        }
        if (cnt>m){
            printf("%I64d \n",n-i-1);
            return 0;
        }
        temp+=arr[i];
        item++;
    }
    printf("%I64d\n",n);

    return 0;
}
