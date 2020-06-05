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

string s="";

int main()
{
    ll n;
    cin>> n;
    ll A[n+10];
    for (ll i=0;i<n;i++) scl(A[i]);
    ll temp = -1;
    ll b= 0 , e = n-1;
    while(b<=e){
       // cout << temp << endl;
        if (A[b] < A[e]){
            if (A[b]>temp){
                s+="L";
                temp = A[b];
                b++;
            }
            else if (A[e]>temp){
                s+="R";
                temp = A[e];
                e--;
            }
            else break;
        }
        else if(A[e] < A[b]) {
            if (A[e] >temp){
                s+="R";
                temp = A[e];
                e--;
            }
            else if (A[b]>temp){
                s+="L";
                temp = A[b];
                b++;
            }
            else break;
        }
        else {
            if (A[b]<=temp)break;
            ll l =0 , r =0;
            for (int ii=b+1;ii<n;ii++){
                if (A[ii]>A[ii-1])l++;
                else break;
            }
            for (int ii=e-1;ii>0;ii--){
                if (A[ii]>A[ii+1])r++;
                else break;
            }
            if (l>r){
                s+="L";
                temp = A[b];
                b++;
            }
            else {
                s+="R";
                temp = A[e];
                e--;
            }
        }
    }
    cout << s.size() << endl;
    cout << s << endl;

    return 0;
}

