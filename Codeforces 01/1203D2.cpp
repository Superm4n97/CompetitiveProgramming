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

ll A[200005][30] , T[30];

bool cheack(ll ii , ll jj)
{
    bool ret = true;
    for (int i=0;i<26;i++){
        if (A[jj][i]-A[ii-1][i] < T[i])ret = false;
    }
    return ret;
}

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    for (int i=0;i<s1.size();i++){
        ll temp = s1[i] - 'a';
        for (int j=0;j<26;j++){
            if (j==temp)A[i+1][j] = A[i][j]+1;
            else A[i+1][j] = A[i][j];
        }
    }
    for (int i=0;i<s2.size();i++){
        ll temp = s2[i]-'a';
        T[temp]++;
    }
    ll ans = 0, i = 1 , j = 1;
    while(j<=s1.size()){
        while(cheack(i,j) && i<=j){
            ans = max(ans , max(i-1 , s1.size()-j));
            cout << "     " << ans << " " << i << " , " << j << endl;
            i++;
        }
        j++;
    }
    cout << ans << endl;


    return 0;
}
