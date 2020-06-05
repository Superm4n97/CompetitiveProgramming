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
    unsigned ll n,b;
    map < unsigned ll , unsigned ll > times;
    cin >> n >> b;
    vector < unsigned ll > v;
    unsigned ll lim = sqrt(b)+3 , k = b,cnt=1e19;
    for (ll i=2;i<=lim;i++){
        if (k%i==0){
            v.pb(i);
            while(k%i==0){
                times[i]++;
                k/=i;
            }
        }
    }
    if (k!=1)times[k]=1,v.pb(k);
    //cout << "ok " << mark << endl;
    for (int i=0;i<v.size();i++){
        unsigned ll mark = v[i],m=mark,cn=0;

        while(n/mark){
            cn+=(n/mark);
            mark*=m;
        }
        cnt = min(cnt,(cn/times[m]));
    }

    cout << cnt << endl;

    return 0;
}
