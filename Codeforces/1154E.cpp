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

priority_queue < pii > pq;
int A[2000006],R[2000006],L[2000006],T[2000006];
int n,k;

int main()
{
    scdd(n,k);
    for (int i=0;i<=n+2;i++)L[i] = i-1,R[i] = i+1 , T[i]=0;
    for (int i=1;i<=n;i++){
        scd(A[i]);
        pq.push(mk(A[i],i));
    }
    int x=0;
    while(!pq.empty()){
        int index = pq.top().second;
        pq.pop();

        if (T[index]!=0)continue;
        int team = x+1;
        x = 1-x;
        T[index] = team;

        int mx = R[index],mn = L[index],temp=1;
        for (int i=R[index] ; temp<=k ; i=R[i]){
            if(i>=n+1)break;
            temp++;
            T[i] = team;
            mx = i;
        }
        temp = 1;
        for (int i=L[index] ; temp<=k ; i=L[i]){
            if (i<=0)break;
            temp++;
            T[i] = team;
            mn = i;
        }
        mx = R[mx] , mn = L[mn];
        L[mx] = mn;
        R[mn] = mx;

        cout << index << " "<< mx  << " " << mn << "    ";
        for (int i=1;i<=n;i++)cout << T[i];
        cout << endl;
    }
    for (int i=1;i<=n;i++)cout << T[i];

    return 0;
}
