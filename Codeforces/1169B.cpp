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

int n,m ,  A[300005] , B[300005];

bool fun(int i , int tut , int a, int b)
{
    if (i==n)return true;
    bool ans = false;
    if (tut==0){
        ans|=fun(i+1 , 1,A[i],-1);
        ans|=fun(i+1 , 1,B[i],-1);
        return ans;
    }
    if (A[i]==a || A[i]==b || B[i]==a || B[i]==b)return fun(i+1,tut,a,b);
    if (tut==2)return false;
    ans|=fun(i+1,tut+1,a,A[i]);
    ans|=fun(i+1,tut+1,a,B[i]);
    return ans;
}

int main()
{
    cin >> m >> n;
    for (int i=0;i<n;i++)scdd(A[i],B[i]);
    cout << (fun(0,0,-1,-1)?"YES":"NO") << endl;

    return 0;
}
