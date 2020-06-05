#define show(x) cout << #x << " : " << x << endl
#define pb      push_back
#define ll      long long int
#define inf     10000000010
#define maxn    100005
#define pll pair<ll , ll>
#include<bits/stdc++.h>
using namespace std;

/*
same Lazy
small Congrats
big HaHa
*/

const double eps = 1e-9;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        if(a1 == 0 && a2 == 0){
            cout << "Lazy" << endl;
            continue;
        }
        if(a1 == 0){
            cout << "Congrats" << endl;
            continue;
        }
        if(a2 == 0){
            cout << "HaHa" << endl;
            continue;
        }

        double x = (double)b1 * log(a1);
        double y = (double)b2 * log(a2);
        //cout << x <<  " "<< y << endl;
        if(abs(x - y) < eps){
            cout << "Lazy" << endl;
        }
        else if( x > y){
            cout << "HaHa" << endl;
        }
        else{
            cout << "Congrats" << endl;
        }

    }


    return 0;
}

