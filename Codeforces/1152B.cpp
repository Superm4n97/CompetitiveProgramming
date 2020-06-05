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

vector < ll > v;

bool perfect(ll x)
{
    while(x){
        if (x%2==0)return false;
        x/=2;
    }
    return true;
}

int main()
{
    ll x;
    cin >> x;
    while(1){
            //cout << x << endl;
        if (perfect(x))break;

        ll tut = x , temp = 0 , k=1;
        while(tut){
            if (tut%2==0){
                temp = k;
            //cout << k << endl;
            }
            tut/=2;
            k++;
        }
        ll XOR = 1<<(temp) ;
        XOR--;
       // cout<< XOR << endl;
        v.pb(temp);
        x = x^XOR;
        if (perfect(x))break;
        else {
            x++;
            v.pb(-1);
        }
    }
    cout << v.size() << endl;
    for (int i=0;i<v.size();i++){
        if (v[i]!=-1)cout << v[i] << " ";
    }

    return 0;
}
