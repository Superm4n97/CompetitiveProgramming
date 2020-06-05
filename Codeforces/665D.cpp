#include<bits/stdc++.h>
#define ll long long int
#define pb      psh_back
#define maxn       2000005
using namespace std;

bool prime[maxn+1];
ll A[maxn];

int main()
{
    for (ll i=2;i<maxn;i++){
        if (!prime[i]){
                //cout << i << " " ;
            for (ll j= i*i ; j<maxn ; j+=i)prime[j] = true;
        }
    }
    ll n , one = 0 , two = 0;
    ll singleSolution  = 0;
    //cin >> n;
    scanf("%I64d",&n);
    for (ll i=0;i<n;i++){
        scanf("%I64d",&A[i]);
        if (A[i]==1)one++;
        else if(!prime[A[i]+1]){
            two = 1;
            singleSolution = A[i];
        }
    }

    if (one+two>=2){
        //cout << one+two << endl;
        printf("%I64d\n",one+two);
        for (int i=0;i<one;i++)printf("1 ");
        //cout << singleSolution << endl;
        if (two)
            printf("%I64d\n",singleSolution);
        return 0;
    }

    ll prm = 0;

    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (!prime[A[i]+A[j]]){
                //cout << 2 << endl;
                printf("2\n");
                printf("%I64d %I64d\n",A[i],A[j]);
                        //cout << A[i] << " " << A[j];
                return 0;
            }
        }
        if (!prime[A[i]])prm = A[i];
    }

    printf("1\n%I64d\n",A[0]);


    return 0;
}
