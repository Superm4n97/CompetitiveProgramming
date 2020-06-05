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

int n;

bool check(int i, int j){
    if (i-1 >=0 && i+1<n && j-1>=0 && j+1<n)return true;
    return false;
}

int main()
{
    cin >> n;
    char A[n+5][n+5];
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        for (int j=0;j<n;j++){
            A[i][j]=s[j];
        }
    }
    int cnt=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (check(i,j)){
                if (A[i][j]=='X' && A[i-1][j-1]=='X' && A[i-1][j+1]=='X' && A[i+1][j-1]=='X' && A[i+1][j+1]=='X'){
                    //cout << i << " " << j << endl;
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;

    return 0;
}

