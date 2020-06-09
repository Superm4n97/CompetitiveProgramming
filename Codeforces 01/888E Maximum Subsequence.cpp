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

vll v1,v2,cum1,cum2;

int main()
{
    ll n,m,ans=0;
    cin >> n >> m;
    inputll(v1,n/2);
    inputll(v2,(n+1)/2);
    ll n1 = v1.size(),n2= v2.size();
    for (int i=0;i<60;i++)v1.pb(0),v2.pb(0);
    for (int i=0;i<(1 << n1) ;i++){
        ll tut = i,sum1=0;
        for (int _i=0;_i<=18;_i++){
            if (tut%2){
                sum1+=v1[_i];
            }
            tut/=2;
        }
        cum1.pb(sum1%m);
    }
    for (int i=0;i<(1 << n2) ;i++){
        ll tut = i,sum1=0;
        for (int _i=0;_i<=18;_i++){
            if (tut%2){
                sum1+=v2[_i];
            }
            tut/=2;
        }
        cum2.pb(sum1%m);
    }
    srt(cum1);

    for (int i=0;i<cum1.size();i++)cout << cum1[i]<< " ";cout << endl;
    for (int i=0;i<cum2.size();i++)cout << cum2[i]<< " ";cout << endl;

    for (ll i=0;i<cum2.size();i++){
        ll tut =  m-cum2[i];
        ll b=0,e=cum1.size()-1,mid,temp=0,ii = e;
        while(b<e){
            mid = (b+e)/2;
            if (cum1[mid]<=tut){
                if (cum1[mid]!=tut)
                    temp = max(mid,temp);
                b=mid+1;
            }
            else e = mid-1;
        }
        ans = max(ans,max(cum2[i]+cum1[temp] , (cum2[i]+cum1[ii])%m));
    }
    cout << ans << endl;


    return 0;
}
