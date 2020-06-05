#include <bits/stdc++.h>
#define pb              push_back
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
#define pll             pair < ll , ll >
#define show(x) cout << #x << " : " << x << endl
#define mk              make_pair
#define inf8            100000008

#define maxn            200005

using namespace std;

ll A[maxn],mark[maxn];

int main()
{
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> A[i];
        mark[A[i]] = 1;
    }

    queue < ll > q;
    for (int i=n;i>=1;i--){
        if (mark[i]==0){
            q.push(i);
        }
    }

    ll pre = -1;
    for (int i=1;i<=n;i++){
        if (A[i]==0){
            if (q.front()==i){
                if (q.size()==1){
                    ll a = q.front() , b = A[pre];
                    q.pop();
                    A[pre] = a;
                    A[i] = b;
                }
                else{
                    q.push(q.front());
                    q.pop();
                    i--;
                }

            }
            else {
                A[i] = q.front();
                pre = i;
                q.pop();
            }
        }
    }

    for (int i=1;i<=n;i++)cout << A[i] << " ";
    cout << endl;


    return 0;
}
