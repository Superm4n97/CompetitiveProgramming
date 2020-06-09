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
    int t;
    cin >> t;
    for (int ii=0;ii<t;ii++){
        double n;
        cin >> n;
        if (n==0){
            cout << "Y 0.000000 0.000000\n";
            continue;
        }
        double b= 0, e = n, mid;
        for (int i=0;i<64;i++){
            mid = (b+e)/2;
            double tut = n / mid;
            if (tut+mid<=n)b = mid;
            else e = mid;
        }
        int tut = (int) (min(n-mid,mid));
        if (tut==0){
            cout << "N" << endl;
            continue;
        }
        printf("Y %.10lf %.10lf\n",mid,n-mid);
    }

    return 0;
}
