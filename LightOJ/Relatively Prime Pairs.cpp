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
    ll a,b;
    cin >> a >>b;
    if (a>b)swap(a,b);
    cout << "YES" << endl;
    for (ll i=a;i<=b;i+=2){
        cout << i << " " << i+1 << endl;
    }

    return 0;
}
