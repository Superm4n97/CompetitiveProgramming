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
    ll n;
    cin >> n;
    for (int i=1;i<=15;i++){
        ll h = 1;
        for (int j=1;j<=i;j++)h*=10;
        ll l = h/10;
        h--;
        ll temp = h-l+1;
        temp*=i;

        //cout << temp << " " << n << endl;
        if (temp==n){
            cout << 9 << endl;
            return 0;
        }
        if (temp<n)n-=temp;
        else {
            ll a = n/i;
            a--;
            ll b = n%i;
//            if (b==0){
//                cout << a%10 << endl;
//                return 0;
//            }
            //cout << b << endl;
            if(1) {
                if (b!=0)
                a++;

                a+=l;
                stringstream ss ;
                ss<<a;
                string s = ss.str();
                //cout << s << " s" << endl;
                if (b==0)b=s.size();
                cout << s[b-1] << endl;
                return 0;
            }
        }
    }

    return 0;
}

