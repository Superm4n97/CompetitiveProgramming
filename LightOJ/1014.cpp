#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    int tc;
    scanf("%lld",&tc);

    for (int _t = 1 ; _t <= tc ; _t++){
        ll p,l;
        scanf("%lld %lld",&p , &l);
        ll n = p-l;

        vector < ll > A, B;

        if (1>l){
            A.push_back(1);
        }
        if (n>l){
            B.push_back(n);
        }

        for (int i=2 ; i*i<= n ; i++){
            if (n%i==0){
                ll j = n / i;
                if (i==j){
                    if (i>l){
                        A.push_back(i);
                    }
                }
                else {
                    if (i>l){
                        A.push_back(i);
                    }
                    if (j>l) {
                        B.push_back(j);
                    }
                }
            }
        }

        if (A.empty() && B.empty())printf("Case %d: impossible\n",_t);
        else {
            printf("Case %d:",_t);
            for (int i=0;i<A.size();i++)printf(" %lld",A[i]);
            for (int i=B.size()-1;i>=0;i--)printf(" %lld",B[i]);
            printf("\n");
        }
    }


    return 0;
}
