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
ll A[100005][12];

int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i=1;i<=n;i++){
        ll a;
        scl(a);
        for (int j=1;j<=10;j++)A[i][j] = A[i-1][j];
        A[i][a]++;
        set < ll > st;
        map < ll , ll > mp;
        ll aa=-1,bb=-1;
        for (int j=1;j<=10;j++){
            //cout << "      " << A[i][j];
            if (A[i][j]){
                st.insert(A[i][j]);
                mp[A[i][j]]++;
                if (aa==-1)aa = A[i][j];
                if (aa!=-1 && A[i][j]!=aa)bb= A[i][j];
            }
        }
        //cout << endl;
        if (aa>bb && bb!=-1)swap(aa,bb);
        //cout << aa << " " << bb << endl;
        if(st.size()==1 && (aa==1 || mp[aa]==1))ans = i;
        if (st.size()==2){
            if (aa==1 & mp[aa]==1)ans = i;
            if (bb==aa+1 && mp[bb]==1)ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}

