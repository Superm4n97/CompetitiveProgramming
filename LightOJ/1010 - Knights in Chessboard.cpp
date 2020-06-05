#include <bits/stdc++.h>
#define ll long long int
#define pb          push_back
#define srt(v)      sort(v.begin(),v.end())
#define rsrt        sort(v.rbegin(),v.rend())
#define vii         vector < int >
#define input(v,n)  for (int i=0;i<n;i++){int a;cin >>a;v.pb(a);}
#define pii         pair<int,int>
#define pll         pair<ll,ll>

using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);
    //cin >> tc;
    for(int t=1;t<=tc;t++){
        int n,m;
        //cin >> n >> m;
        //cout << "Case "<<t<<": " <<max(max(n,m),(m*n+1)/2) << endl;
        scanf("%d %d",&n,&m);
        printf("Case %d: %d\n",t,max(max(n,m),(m*n+1)/2));
    }

    return 0;
}
