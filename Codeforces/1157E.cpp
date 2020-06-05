#include <bits/stdc++.h>
#define pb              push_back
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
#define pll             pair < ll , ll >
#define mk              make_pair
#define inf8            100000008

using namespace std;

vll A,B;
ll n;

int main()
{
    scl(n);
    for (int i=0;i<n;i++){
        ll a;
        scl(a);
        A.pb(a);
    }
    for (int i=0;i<n;i++){
        ll a;
        scl(a);
        B.pb(a);
    }

    srt(B);
    for (int i=0;i<n;i++){
        ll tut = (n-A[i]);

        ll b = 0 , e = B.size()-1 , temp = -1;
        while(b<=e){
            ll mid = (b+e)/2;
            if (B[mid]<tut){
                temp = max(temp,mid);
                b = mid+1;
            }
            else {
                e = mid-1;
            }
        }
       // cout << "     temp " << temp << "    i " << i << endl;
        temp++;
        if (temp == B.size())temp = 0;
        //cout << (A[i]+B[temp])%n << " " ;
        printf("%I64d ",(A[i]+B[temp])%n);
        B.erase(B.begin()+temp);
      //  cout << "     temp " << temp << "    B[temp] " << B[temp] << endl;
      //  cout << "       " << i << endl;
    }

    return 0;
}
