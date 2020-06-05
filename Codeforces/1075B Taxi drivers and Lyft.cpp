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
///4direction ->        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair

using namespace std;

ll leftt[1000000],rightt[1000000],ans[1000000],mark[1000000],arr[1000000];

int main()
{
    ll mx=-10000000000000,n,m;
    scll(n,m);
    n+=m;
    for (int i=1;i<=n;i++)cin >> arr[i];
    for (int i=1;i<=n;i++)cin >> mark[i];
    arr[0]=mx,arr[n+1]=mx*-1,mark[0]=1,mark[n+1]=1;
    ll temp=arr[0];
    for (int i=0;i<=n;i++){
        if (mark[i]==1)temp=arr[i];
        else leftt[i]=arr[i]-temp;
    }
    for (int i=n;i>=1;i--){
        if (mark[i]==1)temp=arr[i];
        else rightt[i]=temp-arr[i];
    }
    for (int i=1;i<=n;i++){
        arr[i]=0;
        if (mark[i]==1){
            if (leftt[i]<=rightt[i])ans[i]=1;
            else ans[i]=-1;
        }
    }
    ll tut = 0;
    for (int i=1;i<=n;i++){
        if (ans[i]==-1)tut++;
        if (mark[i]==1){
            arr[i]+=tut;
            tut = 0;
        }
    }
    for (int i=1;i<=n;i++)cout << ans[i] << " ";
    cout << endl;

    tut = 0;
    for (int i=n;i>0;i--){
        if (ans[i]==1)tut++;
        if (mark[i]==1){
            arr[i]+=tut;
            tut = 0;
        }
    }
    for (int i=1;i<=n;i++){
        if (mark[i]==1)cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
