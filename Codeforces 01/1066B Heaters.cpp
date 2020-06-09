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

int main()
{
    int arr[1004],mark[1004];
    int n,r,cnt=0;
    cin >> n >> r;
    for (int i=1;i<=n;i++)mark[i]=0;
    for (int i=1;i<=n;i++){
        cin >> arr[i];
        if (arr[i]==1){
            cnt++;
            for (int j=i;j>0 && (i-j)<r;j--)mark[j]++;
            for (int j=i+1;j<=n && (j-i)<r;j++)mark[j]++;
        }
    }
    if (mark[1]>1){
        int current;
        for (int i=1;i<=r;i++){
            if (arr[i]==1)current=i;
        }
        //cout << current << endl;
        for (int i=1;i<=r;i++){
            if (i==current)continue;
            if (arr[i]==1){
                cnt--;
                arr[i]=0;
                for (int j=max(1,(i-r+1));j<=min(n,(i+r-1));j++){
                    mark[j]--;
                }
            }
        }
    }

    for (int i=1;i<=n;i++){
        if (mark[i]==0){
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i=1;i<=n;i++){
        if (arr[i]==1){
            bool tut = true;
            for (int j=max(1,(i-r+1));j<=min(n,(i+r-1));j++){
                if (mark[j]<2)tut=false;
            }
            if (tut){
                cnt--;
                //cout << i << endl;
                arr[i]=0;
                for (int j=max(1,(i-r+1));j<=min(n,(i+r-1));j++){
                    mark[j]--;
                }
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
