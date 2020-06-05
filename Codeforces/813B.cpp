#include<bits/stdc++.h>
#define pb      push_back
#define ll      long long int

using namespace std;

ll x,y,l,r;
vector < ll >  A,B,v;

int main()
{
    cin >> x >> y >> l >> r;
    ll temp = 1;
    for (int i=0;;i++){
        if (temp>r)break;
        A.pb(temp);
        if (temp>1000000000000000008/x)break;
        temp*=x;
    }

    temp = 1;
    for (int i=0;;i++){
        if (temp>r)break;
        B.pb(temp);
        if (temp>1000000000000000008/y)break;
        temp*=y;
    }

    //cout << "A: " << A.size() << "   B: " << B.size() << endl;

    map < ll , ll > mp;

    for (int i=0;i<A.size();i++){
        for (int j=0;j<B.size();j++){
            temp = A[i]+B[j];
            mp[temp]++;

            if (mp[temp]==1)v.pb(temp);
        }
    }

    v.pb(1000000000000000018);
    v.pb(0LL);
    sort(v.begin(),v.end());

//    for (int i=0;i<v.size();i++)cout << v[i] << " " ;
//    cout << endl;

    ll ans = 0;
    for (int i=0;i<v.size()-1;i++){
        ll a = v[i] , b = v[i+1];
        temp = 0;
        if (l>a)temp++;
        if (r<b)temp++;

        ans = max(ans , max(0LL,min(b,r) - max(a,l)-1+temp));

    }
    cout << ans << endl;

    return 0;
}
