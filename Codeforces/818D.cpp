#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define maxn 100005

ll n , A[maxn],a , ans = 0;
map < ll , ll > mp , cheack;

int main()
{
    cin >> n >> a;
    for (int i=1;i<=n;i++){
        cin >> A[i];
    }

    cheack[a] = 1;

    for (int i=1;i<=n;i++){
        if (A[i]==a){
            mp[a]++;
        }
        else {
            mp[A[i]]++;
            if (mp[A[i]]<=mp[a])cheack[A[i]] = 1;
        }
    }
    for (int i=1;i<=n;i++){
        if (cheack[A[i]] == 0 && mp[A[i]] >= mp[a]){
            cout << A[i] << endl;
            return 0;
        }
    }
    cout << -1 << endl;


    return 0;
}
