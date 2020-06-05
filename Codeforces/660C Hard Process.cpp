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

int a[400000],mark[400000];

int main()
{
    int n,k;
    cin >> n >> k;
    for (int i=1;i<=n;i++)cin >> a[i];
    int cnt=0,b=1, e=0,mx=0,index=1;
    while(e<=n){
        if (a[e]==0)cnt++;
        if (cnt>k){
            while(1){
                b++;
                if (a[b-1]==0){
                    cnt--;
                    break;
                }
            }
        }
        if (e-b+1>mx){
            mx = e-b+1;
            index = b;
        }
        if (b>e)e=b;
        else e++;
    }
    for (int i=0;i<mx;i++){
        a[i+index] = 1;
    }
    cout << mx << endl;
    for (int i=1;i<=n;i++)cout << a[i] << " ";
    cout << endl;

    return 0;
}
