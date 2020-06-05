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
#define printCaseAnsInt(caseVariable,ans)  printf("Case %d: %d\n",t,ans)
#define printCaseAnsLL(caseVariable,ans)  printf("Case %lld: %lld\n",t,ans)

using namespace std;

string s;
int dp[105][105];

void initialize()
{
    for (int i=0;i<105;i++){
        for (int j=0;j<105;j++)dp[i][j]=-1;
    }
}

int GeneratingPalindromes(int i, int j)
{
    if(dp[i][j] != -1)return dp[i][j];
    if(i>=j) return dp[i][j] = 0;

    if (s[i] == s[j])return GeneratingPalindromes(i+1,j-1);
    return dp[i][j] = min(GeneratingPalindromes(i,j-1),GeneratingPalindromes(i+1,j))+1;
}

int main()
{
    int tc;
    cin >> tc;

    for (int t=1;t<=tc;t++){
        cin >> s;
        initialize();
        printCaseAnsInt(t,GeneratingPalindromes(0,s.size()-1));
    }

    return 0;
}
