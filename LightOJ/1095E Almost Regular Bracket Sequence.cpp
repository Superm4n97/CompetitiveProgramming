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

using namespace std;

string s;
int A[1000004],B[1000004];

bool fun(int i)
{
    if (s[i]=='(')return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    cin >> s;
    int o, c;
    for (int i=0;i<n;i++){
        if (fun(i))o++;
        else c++;
    }
    for (int i=0;i<=n+1;i++)A[i]=0,B[i]=0;
    for (int i=1;i<=n;i++){
        if (fun(i-1)){
            A[i]+=A[i-1]+1;
        }
        else {
            int tut = A[i-1];
            tut--;
            if (tut<0)tut=0;
            A[i] = tut;
        }
    }
    for (int i=n;i>=1;i--){
        if (!fun(i-1)){
            B[i]+=B[i+1]+1;
        }
        else {
            int tut = B[i+1];
            tut--;
            if (tut<0)tut=0;
            B[i]=tut;
        }
    }
    for (int i=1;i<=n;i++)cout << A[i] << " ";
    cout << endl;
    for (int i=1;i<=n;i++)cout << B[i] << " ";
    cout << endl;

    int cnt=0;
    for (int i=1;i<=n;i++){
        if (fun(i-1)){
            int closing = B[i+1]+1;
            int opening = A[i-1];
            if (opening==closing /*&& opening+closing==n*/)cnt++;//cout << " " << i << endl;
        }
        else {
            int opening = A[i-1]+1;
            int closing = B[i+1];

            if (opening==closing /*&& opening+closing==n*/)cnt++;//cout << " " << i << endl;
        }
    }
    cout << cnt << endl;

    return 0;
}
