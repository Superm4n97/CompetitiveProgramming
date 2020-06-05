#include<bits/stdc++.h>
#define ll long long int
#define maxn 200005

using namespace std;

ll n,m,q;
vector < pair < ll , pair < ll , ll > > > query;
ll A[maxn];
ll mark[105];

int main()
{
    cin >> n >> q >> m;
    for (int i=1;i<=n;i++)cin >> A[i];
    for (int j=0;j<q;j++){
        ll t , l,r;
        cin >> t >> l >> r;
        query.push_back({t,{l,r}});
    }
    for (int i=1;i<=m;i++)cin >> mark[i];

    for (int i=q-1;i>=0;i--){
        ll t = query[i].first , l = query[i].second.first , r = query[i].second.second;

        if (t==1){
            for (int j=1;j<=m;j++){
                if (mark[j]>=l && mark[j]<=r){
                    mark[j]--;
                    if (mark[j]<l)mark[j] = r;
                }
            }
        }
        else {
//            for (int j=1;j<=m;j++)cout << mark[j] << " ";
//            cout << endl;

            for (int j=1;j<=m;j++){
                if (mark[j]>=l && mark[j]<=r){
                    mark[j] = r+l-mark[j];
                }
            }
        }
    }
    for (int i=1;i<=m;i++)cout << A[mark[i]] << " ";
    cout << endl;


    return 0;
}
