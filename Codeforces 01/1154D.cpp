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

int A[200005];

int main()
{
    int n , b,a,aa,bb , temp=0;
        cin >> n >> bb >> aa;
        a = aa , b = bb;
        for (int i=0;i<n;i++){
            cin >> A[i];
            if (aa==a){
                a--;
                temp++;
                continue;
            }
            if (A[i]==1 && b){
                a++;
                temp++;
                b--;
                continue;
            }
            if (a){
                a--;
                temp++;
                continue;
            }
            if (b){
                b--;
                temp++;
                continue;
            }
            break;

        }
        cout << temp;

        return 0;
    }
