#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll divisor[100005] , n;

void clean()
{
    for (int i = 2 ; i*i <= n ; i++)divisor[i] = 0;
}

ll cal(ll a)
{
      return a*(a+1)/2;
}

int main()
{
    ll tc;
    scanf("%lld",&tc);

    for (int _t = 1 ; _t<=tc ; _t++){
        scanf("%lld",&n);
        clean();

        ll i = 1, ans = 0;

        for (i=2 ; i*i <= n ; i++){
            divisor[i] = n/i;
            ans+=(divisor[i]-1)*i;

//        show(i);
//        show(ans);
//        show(divisor[i-1]);
//        show(divisor[i]);

            if (i>2){
                ans += (cal(divisor[i-1]) - cal(divisor[i]) ) * (i-2);
            }
        }


        i--;
        if (i>1)ans+=(cal(divisor[i]) - cal(i) ) * (i-1);

        printf("Case %d: %lld\n",_t , ans);
    }

    return 0;
}
