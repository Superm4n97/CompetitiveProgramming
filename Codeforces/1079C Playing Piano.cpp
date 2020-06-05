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

int a[200000+5],b[200000+5],neg[200000+5],pos[200000+5],n;

int main()
{
    cin >> n;
    int cnt =0 ;
    bool ans = false;
    for (int i=1;i<=n;i++)cin >> a[i];
    for (int i=2;i<=n;i++){
        if (a[i]>a[i-1])cnt++;
        else cnt=0;
        if (cnt==1)cnt++;
        if (cnt>5)ans=true;
    }
    cnt=0;
    for (int i=n-1;i>0;i--){
        if (a[i]>a[i+1])cnt++;
        else cnt=0;
        if (cnt==1)cnt++;
        if (cnt>5)ans=true;
    }
    if (ans){
        cout << -1 << endl;
        return 0;
    }
    int temp = 2;
    for (int i=2;i<=n;i++){
        if (a[i]>a[i-1]){
            if (temp==2){
                pos[i-1]=1;
                pos[i]=temp;
            }
            else pos[i]=temp;
            temp++;
            if (temp>5)temp=2;
        }
        else {
            pos[i]=0;
            temp=2;
        }
    }
    ///neg
    temp = -2;
    for (int i=n-1;i>0;i--){
        if (a[i]>a[i+1]){
            if (temp==-2){
                neg[i+1]=-1;
                neg[i]=temp;
            }
            else neg[i]=temp;
            temp--;
            if (temp<-5)temp=-2;
        }
        else {
            neg[i]=0;
            temp=-2;
        }
    }
    for (int i=1;i<=n;i++)
        b[i]=max(pos[i],neg[i]*-1);
    for (int i=1;i<=n;i++){
        if (b[i]==0){
            int cnt = 1;
            if (b[i-1]==cnt)cnt++;
            if (b[i+1]==cnt)cnt++;
            if (b[i-1]==cnt)cnt++;
            if (b[i+1]==cnt)cnt++;
            b[i]=cnt;
        }
    }
    for (int i=2;i<=n;i++){
        if (b[i]==b[i-1] && b[i]==5)ans=true;
        else b[i]
    }
    if (ans){
        cout << -1 << endl;
        return 0;
    }
    for (int i=1;i<=n;i++)cout << b[i] << " ";
    cout << endl;

    return 0;
}
