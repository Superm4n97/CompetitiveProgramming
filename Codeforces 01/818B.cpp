#include<bits/stdc++.h>

#define ll long long int

using namespace std;

ll n,m,A[106] , v[106];

bool ans = true;

int main()
{
    cin >> n >> m;
    for (int i=1;i<=m;i++)cin >> A[i];

    for (int i=1;i<n;i++){
        ll a = A[i] - A[i+1];
        if (a<=0)a += n;


    }


    return 0;
}
