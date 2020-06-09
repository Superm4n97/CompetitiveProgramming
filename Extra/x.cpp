#include <bits/stdc++.h>
#define pb           push_back
#define ll              long long int
#define mod              30000000


using namespace std;

vector<int> v, l, r;
int f[30000002];

int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);

    for(int i=1;i<=m;i++){
        int x;
        scanf("%d", &x);
        v.pb(x);
    }
    for(int i=m;i<n;i++){
        int x = (v[i-m]%mod + v[i-m+1]%mod)%mod;
        v.pb(x);
    }
    for(int i=0;i<n;i++){
        f[v[i]]++;
    }
    v.clear();
    for(int i=0;i<30000000;i++){
        while(f[i]){
            v.pb(i);
            f[i] --;
        }
    }
    for(int i=1;i<=q;i++){
        int x;
        scanf("%d", &x);
        printf("%d\n", v[x-1]);
    }





    return 0;
}
