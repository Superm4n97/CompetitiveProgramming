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

ll A[100005],n;
vector < ll > v,ans;

ll binarySearch(ll length)
{
    ll temp = length , f= 0,l=n-1,found = 0;

    while(f<=l){
        ll mid = (f+l)/2;
        if(v[mid] <= length){
            found = max(found,mid);
            f = mid+1;
        }
        else l = mid-1;
    }
    return temp+=A[found]+(n-1-found)*length;
}

int main()
{
    cin >> n;
    inputll(v,n);
    srt(v);
    //for (int i=0;i<=n;i++)A[i]=0;
    for (int i=n-1;i>=1;i--){
        v[i]-=v[i-1];
    }
    v[0] = 0;
    srt(v);
    ll q;
    cin >> q;
    for (int i=1;i<n;i++){
        A[i] = v[i]+A[i-1];
    }

    //for (int i=0;i<n;i++)cout << v[i] << "    " << A[i] << endl;

    for (int i=0;i<q;i++){
        ll a, b;
        cin >> a >> b;
        ans.pb(binarySearch(b-a+1));
    }
    for (int i=0;i<ans.size();i++)cout << ans[i] << " ";
    cout << endl;

    return 0;
}
