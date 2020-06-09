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

ll A[100][100] , B[100][100] , n,m;

int main()
{
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++)cin>>A[i][j];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++)cin>>B[i][j];
    }
    for (int i=1;i<=m;i++)A[n+1][i] = inf8,B[n+1][i] = inf8;
    for (int i=1;i<=n;i++)A[i][m+1] = inf8,B[i][m+1] = inf8;

    bool ans = true;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (A[i][j]>B[i][j])swap(A[i][j],B[i][j]);
            if (A[i][j]<=A[i][j-1] || B[i][j] <= B[i][j-1] || A[i][j]<=A[i-1][j] || B[i][j]<=B[i-1][j])ans=false;
        }
    }

//    cout << endl;
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=m;j++)cout << A[i][j]<< " ";
//       cout << endl;
//    }
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=m;j++)cout << B[i][j]<< " ";
//        cout << endl;
//    }


//
//    for (int i=n;i>=1;i--){
//        for (int j=m;j>=1;j--){
//            if (A[i][j]>=A[i][j+1] || B[i][j] >= B[i][j+1] || A[i][j]>=A[i+1][j] || B[i][j]>=B[i+1][j] || A[i][j]<=A[i][j-1] || B[i][j] <= B[i][j-1] || A[i][j]<=A[i-1][j] || B[i][j]<=B[i-1][j])swap(A[i][j],B[i][j]);
//            if (A[i][j]>=A[i][j+1] || B[i][j] >= B[i][j+1] || A[i][j]>=A[i+1][j] || B[i][j]>=B[i+1][j] || A[i][j]<=A[i][j-1] || B[i][j] <= B[i][j-1] || A[i][j]<=A[i-1][j] || B[i][j]<=B[i-1][j])ans = false;
////            if (ans==false)cout << "      " << i << " " << j << endl;
////            if (ans==false)cout << "      " << A[i][j+1] << " " << A[i+1][j] << endl;
////            if (ans==false)cout << "      " << B[i][j+1] << " " << B[i+1][j] << endl;
//        }
//    }
    cout << (ans?"Possible":"Impossible") << endl;

    return 0;
}
