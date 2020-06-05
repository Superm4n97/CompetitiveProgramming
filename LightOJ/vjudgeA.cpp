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

int main()
{
    int tc;
    cin >> tc;
    while(tc--){
        int cnt=0;
        for (int i=0;i<4;i++){
            int a;
            cin >> a;
            if (a)cnt++;
        }
        if (cnt==0)cout << "Typically Otaku" << endl;
        else if (cnt==1)cout << "Eye-opener" << endl;
        else if (cnt==2)cout << "Young Traveller" << endl;
        else if (cnt==3)cout << "Excellent Traveller" << endl;
        else cout << "Contemporary Xu Xiake" << endl;
    }

    return 0;
}
