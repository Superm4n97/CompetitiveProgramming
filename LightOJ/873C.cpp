#include<bits/stdc++.h>
#define ll long long int
#define maxn 105
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll A[maxn][maxn] , CSUM[maxn][maxn] , n , m , k;
ll ans = 0 , deleted = 0;

int main()
{
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++){
        for (int j = 1 ; j<=m;j++)cin >> A[i][j];
    }

    for (int j = 1 ; j<=m ; j++){
        for (int i = 1 ; i<=n ; i++)CSUM[i][j] = CSUM[i-1][j]+A[i][j];
    }

    for (int j = 1 ; j<=m; j++){
        ll columnMax = 0 , columnDeleted = 0;
        for (int i = 1 ; i<=n ; i++){
            if (A[i][j]==1 && columnMax<CSUM[min(i+k-1,n)][j]-CSUM[i-1][j]){
                columnMax = CSUM[min(i+k-1,n)][j]-CSUM[i-1][j];
                columnDeleted = CSUM[i-1][j];
            }
        }
        ans+=columnMax;
        deleted+=columnDeleted;
    }
    cout << ans << " " << deleted << endl;


    return 0;
}
