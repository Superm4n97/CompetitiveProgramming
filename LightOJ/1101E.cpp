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
    ll n;
    //cin >> n;
    scl(n);
    ll xx=0,yy=0;
    for (int i=0;i<n;i++){
        char ch;
        //cin >> ch;
        getchar();
        scanf("%c",&ch);
        ll a,b;
        scll(a,b);
        //cin >> a >> b;
        if (a>b)swap(a,b);
        if (ch=='+'){
            xx=max(xx,a);
            yy=max(yy,b);
        }
        else {
           // cout << xx << " "  << yy << endl;
            if (a>=xx && b>=yy)printf("YES\n");//cout << "YES" << endl;
            else printf("NO\n");//cout << "NO" << endl;
        }
    }

    return 0;
}
