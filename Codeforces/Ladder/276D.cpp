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

int main()
{
    ll l,r;
    cin >> l >> r;
    if (l>r)swap(l,r);
    if (l==r){
        cout << 0 << endl;
        return 0;
    }

    ll cnt1 = 0 , cnt2 = 0 , a = l , b = r;
    while(a || b){
        if (a)cnt1++;
        if (b)cnt2++;

        a/=2 , b/=2;
    }
    //cout << cnt1 << " " << cnt2 << endl;
    //cout << (1<<cnt2) << endl;
    if (cnt2>cnt1){
        ll temp=1;
        for (ll i=0;i<cnt2;i++)temp*=2;
        cout << temp-1 << endl;
        return 0;
    }
    for (ll i=cnt1;i>=0;i--){
        ll temp = 1;
        for (ll j=0;j<i;j++)temp*=2;
        //cout << "   " << temp << " " << (l&temp) << " " <<  (r&temp) << endl;
        if ((l&temp) != (r&temp)){
            //cout << "        " << temp << endl;
            temp= temp*2;
            temp--;
            cout << temp << endl;
            return 0;
        }
    }

    return 0;
}
