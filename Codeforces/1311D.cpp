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
#define show(x) cout << #x << " : " << x << endl
#define mk              make_pair
#define inf             10000000000000016

#define maxn            1000006

using namespace std;

int main()
{
    ll tc;
    cin >> tc;
    while(tc--){
        ll a, b, c;
        cin >> a >> b >> c;

        ll mx = inf  , A , B , C;

        for (int i=1;i<=c;i++){
           // show(i);
            ll temp = i , cnt = 0;

            ll t1 = b / temp;
            if (t1*temp ==b)t1--;
            if (t1==0)t1++;
            ll temp2 = t1*temp;
            ll temp3 = temp2+temp;

            ll t2 = c / temp2;
            if (t2*temp2 ==c)t2--;
            if (t2==0)t2++;
            ll temp4 = t2*temp2;
            ll temp5 = (t2+1)*temp2;

            ll t3 = c/temp3;
            if (t3*temp3 ==c)t3--;
            if (t3==0)t3++;
            ll temp6 = t3*temp3;
            ll temp7 = (t3+1)*temp3;

            cnt = abs(temp-a)+abs(temp2-b)+abs(temp4-c);
            if (cnt<mx){
                mx = cnt;
                A = temp, B = temp2 , C = temp4;
            }
           // show(i);
//           if (temp==6){
//            show(temp2);
//            show(temp3);
//           }

            cnt = abs(temp-a)+abs(temp2-b)+abs(temp5-c);
            if (cnt<mx){
                mx = cnt;
                A = temp, B = temp2 , C = temp5;
            }

            cnt = abs(temp-a)+abs(temp3-b)+abs(temp6-c);
            if (cnt<mx){
                mx = cnt;
                A = temp, B = temp3 , C = temp6;
            }

            cnt = abs(temp-a)+abs(temp3-b)+abs(temp7-c);
            if (cnt<mx){
                mx = cnt;
                A = temp, B = temp3 , C = temp7;
            }
        }
        cout << mx << endl;
        cout << A << " " << B << " " << C <<endl;
    }



    return 0;
}
