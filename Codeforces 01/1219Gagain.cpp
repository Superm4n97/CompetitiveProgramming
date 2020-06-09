#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb      push_back
#define rsrt(a)         sort(a.rbegin(),a.rend())
int main()
{
    int  n,m;
    scanf("%d %d",&n,&m);
    ll arr[n+10][m+10];
    ll row[n+10],col[m+10];
    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    for(int i = 1;i <= n;i++){
        ll sum = 0;
        for(int j = 1;j <= m;j++){
            scanf("%lld",&arr[i][j]);
            sum += arr[i][j];
            col[j] += arr[i][j];
        }
        row[i] = sum;
    }
//
//    for(ll i = 1;i <= n;i++) cout << row[i] <<endl;
//    for(ll i = 1;i <= m;i++) cout << col[i] <<" ";
//    cout << endl;

    ll ans = 0 , M1 = 0 , M2 = 0;
    vector < ll > v1 , v2;
    for (int i=1;i<=n;i++){
        v1.pb(row[i]);
        //cout << "    " << row[i] << " in " << i << endl;
    }
    for (int i=1;i<=m;i++)v2.pb(col[i]);
    rsrt(v1);
    rsrt(v2);
    for (int i=0;i<4 && i<v1.size();i++)M1+=v1[i];
    for (int i=0;i<4 && i<v2.size();i++)M2+=v2[i];

    for(int i = 1;i <= 4;i++){
        ll keep = 0,x = 1;
        ll peek = 0,y = 1;
        for(int j = 1;j <= n;j++){
            if(keep < row[j]){
                keep = row[j];
                x = j;
            }
        }
        for(int j = 1;j <= m;j++){
            if(peek < col[j]){
                peek = col[j];
                y = j;
            }
        }
        if(keep > peek){
            ans += keep;
            row[x] = 0;
            for(ll j = 1;j <= m;j++) col[j] -= arr[x][j];
        }
        else{
            ans += peek;
            col[y] = 0;
            for(ll j = 1;j <= n;j++) row[j] -= arr[j][y];
        }
    }
    //cout << ans << "-" << M1 << "-" << M2 << endl;
    printf("%lld\n",max(ans,max(M1,M2)));
    return 0;
}
