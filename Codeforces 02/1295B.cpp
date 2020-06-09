#include<bits/stdc++.h>
#define ll long long int

using namespace std;

bool calculate(ll a, ll b)
{
    if (b==0)return true;
    if (a>0 && b>0) {
        if (b%a==0)return true;
    }
    if (a<0 && b<0) {
        a*=-1 , b*=-1;
        if (b%a==0)return true;
    }

    return false;
}

ll A[100005];

int main()
{
    ll tc;
    cin >> tc;

    while(tc--){
        ll n,x;
        cin >> n >> x;
        string s;
        cin >> s;

        for (int i=0;i<=n;i++)A[i] = 0;
        if (s[0]=='0')A[0] = 1;
        else A[0] = -1;

        for (int i=1;i<n;i++){
            if (s[i]=='1')A[i] = A[i-1]-1;
            else A[i] = A[i-1]+1;
        }
        ll cnt = 0;

        if (x==0)cnt++;

        for (int i=0;i<n;i++){
            ll temp = x - A[i];
            if (A[n-1]==0){
                if (A[i]==x)cnt++;
            }
            else {
                if (calculate(A[n-1],temp)){
                    cnt++;
                }
            }
        }
        if (A[n-1]==0){
            if (cnt==0)cout << 0 << endl;
            else cout << -1 << endl;
        }
        else cout << cnt << endl;
    }

    return 0;
}
