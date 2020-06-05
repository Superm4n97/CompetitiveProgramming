#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,d;
    cin >> n >> d;
    ll arr[n+5];
    for (int i=0;i<n;i++)cin >> arr[i];
    ll b=0,cnt=0,e=0;
    while(1){
        if (b==e && b==n-1)break;
        if (b==e){
            e++;
            continue;
        }
        if (e-b<=d){
            cnt++;
            e++;
        }
        else b++;
    }
    cout << cnt << endl;

    return 0;
}
