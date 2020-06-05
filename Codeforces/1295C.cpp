#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll tc;
    cin >> tc;

    while(tc--){
        string s,t;
        cin >> s >> t;

        ll n = s.size();
        ll A[n+5][30];

        memset(A,-1,sizeof(A));

        for (int i=n-1;i>=0;i--){
            for (int j=0;j<26;j++)A[i][j] = A[i+1][j];
            A[i][(s[i]-'a')] = i+1;
        }

        ll cnt = 0 , temp = n+1;
        bool ans = true;

        //cout << t << endl;

        for (int i=0;i<t.size();i++){
            ll a = t[i]-'a';

            if (A[0][a] == -1){
                ans = false;
                break;
            }

            if (A[temp][a] == -1){
                temp = A[0][a];
                cnt++;
            }
            else {
                temp = A[temp][a];
            }
        }
        if (!ans)cout << -1 << endl;
        else cout << cnt << endl;
    }

    return 0;
}
