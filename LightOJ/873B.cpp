#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl;
#define maxn 100005

using namespace std;

string s;
ll n;
map < ll , ll > mp;

int main()
{
    cin>> n;
    cin >> s;
    ll ans = 0 , temp = 0;

    for (int i=0;i<n;i++){
        if (s[i]=='1')temp++;
        else temp--;

        if (!temp)ans = i+1;
        else {
            ll rem = temp*-1;
            if (mp[temp]==0)mp[temp] = i+1;
            else {
                ans = max(ans,i-mp[temp]+1);
            }
        }
    }
    cout << ans << endl;


    return 0;
}
