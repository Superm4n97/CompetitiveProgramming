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

ll arr[200005];

int main()
{
    ll n,m,k;
    scll(n,m),scl(k);
    for (int i=0;i<n;i++)scl(arr[i]);
    ll b = 0 , e= n-1 , index=200005;
    while(b<=e){
        ll mid = (b+e)/2 , cnt =1 , temp = 0;
        for (int i=mid ; i<n;i++){
            if (temp+arr[i]>k){
                temp = 0;
                cnt++;
            }
            temp+=arr[i];
        }
        if (cnt>m)b=mid+1;
        else {
            e = mid-1;
            index=min(index,mid);
        }
    }
    if (index==200005){
        printf("%I64d\n",n);
        return 0;
    }
    printf("%I64d\n",n-index);

    return 0;
}
