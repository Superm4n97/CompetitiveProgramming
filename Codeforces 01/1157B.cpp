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
    int n;
    string s;
    cin >> n ;
    cin >> s;
    int A[15];
    for (int i=1;i<=9;i++)cin >> A[i];
    for (int i=0;i<n;i++){
        int ind = s[i]-'0';
        if (A[ind] > ind){
            while(A[ind] >= ind && i<n){
               // cout << i << " " << A[i] << endl;
                char ch = '0'+A[ind];
                s[i] = ch;
                i++;
                ind = s[i]-'0';
            }
            break;
        }
    }
    cout << s << endl;

    return 0;
}

