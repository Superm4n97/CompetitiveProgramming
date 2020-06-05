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

int n;
map < int , int > mp , pp;
int A[300005];
vector < pii > vp;

void ssss(int a, int b)
{
            vp.pb(mk(a,b));
            swap(A[a],A[b]);
            mp[A[a]] = a;
            pp[a] = A[a];
            mp[A[b]] = b;
            pp[b] = A[b];
}

int main()
{
    scd(n);
    for (int i=1;i<=n;i++){
        scd(A[i]);
        mp[A[i]] = i;
        pp[i] = A[i];
    }
    for (int i=1;i<=n;i++){
        if (i==mp[i])continue;

        int t = mp[i];

        if (abs(i-t)*2>=n){
            ssss(i,t);
        }
        else if (i*2<=n){
            if (t*2<=n){
                ssss(t,n);
                ssss(i,n);
            }
            else {
                ssss(1,t);
                ssss(1,n);
                ssss(i,n);
                ssss(1,t);
            }
        }
        else {
            ssss(1,t);
            ssss(1,i);
            ssss(1,t);
        }
    }

    n = vp.size();
    cout << n << endl;
    for (int i=0;i<n;i++)cout << vp[i].first << " " << vp[i].second << endl;

    return 0;
}
