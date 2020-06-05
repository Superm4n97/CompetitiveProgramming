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
        ll n;
        cin >> n;
        vll A,B,C;
        inputll(A,n);

        ll temp = 0 , mark = 0;
        bool ans = true , ans2 = true;

        B = A;

        for (int i=0;i<n;i++){
            if (mark==0){
                if (A[i]>=temp){
                    A[i] = temp;
                    temp++;
                }
                else {
                    A[i] = min(A[i],temp-2);
                    if (A[i]<0)ans = false;
                    mark = 1;
                }
            }
            else {
                A[i] = min(A[i-1]-1,A[i]);
                if (A[i]<0)ans = false;
            }
        }

        mark = 0 , temp = 0;

        for (int i=n-1;i>=0;i--){
            if (mark==0){
                if (B[i]>=temp){
                    B[i] = temp;
                    temp++;
                }
                else {
                    //show(A[i]);
                    B[i] = min(B[i],temp-2);
                    if (B[i]<0)ans2 = false;
                    mark = 1;
                }
            }
            else {
                //show(i);
                B[i] = min(B[i+1]-1,B[i]);
                if (B[i]<0)ans2 = false;
            }
        }
        //show(ans2);

        cout << (ans|ans2?"Yes":"No") << endl;
    }


    return 0;
}
