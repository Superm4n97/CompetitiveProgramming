#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define maxn 100005

int main()
{
    int tc;
    scanf("%d",&tc);

    while(tc--){
        ll n;
        scanf("%lld",&n);

        ll b =  0 , e = n , ans = 0;
        //ans = n-1;

        while(b <= e){
            ll mid = (b+e)/2;
            ll temp = n- mid;
            ll tut = temp ;
            temp = temp*(temp-1)/2;
            if (mid>= tut){
                ans = max(ans,mid+min(temp,mid));
                b = mid+1;
            }
            else {
                e = mid-1;
            }
            cout << " mid : " << mid <<endl;
        }
        cout << ans << endl;
    }

    return 0;
}
