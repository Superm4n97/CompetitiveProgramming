#include <bits/stdc++.h>
#define pb(a)           push_back(a)
#define ll              long long int
#define ull             unsigned long long
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
    ull n,b,lim,m,mn=1e19+2;
    cin >> n >> b;
    lim = sqrt(b)+2;
    m = n;

    for (int i=2;i<=lim;i++){
        if (b%i==0){
            ull  times=0,temp=0,tut=i;
            while(b%i==0){
                b/=i;
                times++;
            }
            while(m/tut){
                temp+=(m/tut);
                tut*=i;
            }
            //cout << temp << " " << times << " " << i << endl;

            temp/=times;
            mn = min(mn,temp);
        }
    }
    if (b>1){
        ull temp=0,tut=b;
        while(m/tut){
            temp+=(m/tut);
            tut*=b;
        }
        mn = min(mn,temp);
    }
    cout << mn << endl;

    return 0;
}
