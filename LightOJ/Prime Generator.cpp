#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%lld",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%lld %lld",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair
#define inf8            100000008
#define printCaseAnsInt(t,ans)  printf("Case %d: %d",t,ans)
#define printCaseAnsLL(t,ans)  printf("Case %lld: %lld",t,ans)

using namespace std;

int main()
{
    int tc;
    scd(tc);
    while(tc--){
        ll a , b;
        scll(a,b);
        if (b<a)swap(a,b);
        ll lim = sqrt(b)+1;
        map < ll , bool > mp;
        mp[1] = true;
        for (ll i=2;i<=lim;i++){
            ll j  = i;
            ll temp = a/i;
            j = max(temp*i,i);
            if (j==i && !mp[j])j+=i;
            for (;j<=b;j+=i){
                mp[j] = true;
            }
        }
        for (ll i=a;i<=b;i++){
            if (!mp[i])cout << i << endl;
        }
        cout << endl;

    }



    return 0;
}

