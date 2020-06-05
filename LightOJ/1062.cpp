#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll tc;
    cin >> tc;

    for (int _t=1 ; _t<=tc;_t++){
        double x,y,h,d;
        cin >> x >> y >> h;

        double b = 0 , e = min(x,y) , ans = 0;

        for (int i=0;i<100;i++){
            d = (b+e)/2.0;
            //cout << "   " << d << endl;
            double h1 = sqrt(x*x - d*d) , h2 = sqrt(y*y - d*d);

            double hh = h1*h2 / (h1+h2);

            if (hh >= h){
                b = d;
            }
            else {
                e = d;
            }
        }

        printf("Case %d: %.8f\n",_t ,d);
    }

    return 0;
}
