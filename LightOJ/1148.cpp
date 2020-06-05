#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl;

using namespace std;

ll A[60] ;
map < ll , ll > CNT;
vector < ll > v;

void Clean()
{
    memset(A,0,sizeof(A));
    CNT.clear();
    v.clear();
}

int main()
{
    ll tc;
    scanf("%lld",&tc);
    for (int _t = 1 ; _t<=tc; _t++){
        Clean();

        ll n , ans = 0;
        scanf("%lld",&n);
        for (int i=1;i<=n;i++){
            scanf("%lld",&A[i]);
            CNT[A[i]]++;
            if (CNT[A[i]]==1){
                v.push_back(A[i]);
            }
        }
        for (int i=0;i<v.size();i++){
            ll temp = ((CNT[v[i]]+v[i]) / (v[i]+1))*(v[i]+1);
            //show(temp);

            ans+=temp;
        }
        printf("Case %d: %lld\n",_t,ans);
    }


    return 0;
}
