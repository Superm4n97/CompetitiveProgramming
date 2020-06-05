#include<bits/stdc++.h>
#define ll long long int
#define pll pair < ll , ll >

using namespace std;

ll area(pll a, pll b, pll c)
{
    ll ax = a.first , ay = a.second , bx = b.first , by = b.second , cx = c.first , cy = c.second;
    ll temp = (ax*by + bx*cy + cx*ay);
    temp -= (bx*ay + cx*by + ax*cy);

    if (temp<0)temp = -1;
    if (temp>0)temp = 1;

    return temp;
}

int main()
{
    ll tc;
    cin >> tc;
    for (int _t = 1 ; _t<=tc ; _t++){
        ll n;
        cin >> n;
        ll X[n+5] , Y[n+5];
        vector < pair < ll , ll > > v;

        for (int i=0;i<n;i++){
            cin >> X[i] >> Y[i];
            v.push_back({X[i],Y[i]});
        }

        ll q;
        cin >> q;

        cout << "Case "<< _t << ":" << endl;


        while(q--){
            pair < ll , ll > p1 , p2;
            cin >> p1.first >> p1.second;
            p2.first = 1e9+7 , p2.second = 1e9+97;

            ll cut = 0;
            bool inside = false;

            for (int i=1;i<n;i++){

                //cout << "cut : " << cut << " ";
                if (area(p1,p2,v[i-1]) != area(p1,p2,v[i]) && area(v[i-1],v[i],p1) != area(v[i-1],v[i],p2))cut++;
                //cout << cut << "  i: " << i << endl;
                if (area(p1,p2,v[i-1]) * area(p1,p2,v[i]) == 0 && area(v[i-1],v[i],p1) != area(v[i-1],v[i],p2))inside = true;
                if (area(p1,p2,v[i-1]) != area(p1,p2,v[i]) && area(v[i-1],v[i],p1)*area(v[i-1],v[i],p2) == 0)inside = true;

            }

            if (area(p1,p2,v[n-1]) != area(p1,p2,v[0]) && area(v[n-1],v[0],p1) != area(v[n-1],v[0],p2))cut++;
            if (area(p1,p2,v[n-1]) * area(p1,p2,v[0]) == 0 && area(v[n-1],v[0],p1) != area(v[n-1],v[0],p2))inside = true;
            if (area(p1,p2,v[n-1]) != area(p1,p2,v[0]) && area(v[n-1],v[0],p1)*area(v[n-1],v[0],p2) == 0)inside = true;

            //cout << "cut : " << cut << endl;
            if (cut%2 || inside)cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}
