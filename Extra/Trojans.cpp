#define pb push_back
#define ff first
#define ss second
#define ll long long
#define maxn 505
#define INF 1e18
#define mod 10000007
#include <bits/stdc++.h>
using namespace std;



double area(double Ax, double Ay, double Bx, double By, double Cx, double Cy){
    double res = (Ax * By) + (Bx * Cy) + (Cx * Ay) - (Bx * Ay) - (Cx * By) - (Ax * Cy);
    return abs(res);
}


int main(){
    int TC;
    scanf("%d", &TC);
    while(TC--){
        double Ax, Ay, Bx, By, Cx, Cy, Ix, Iy, Jx, Jy, Hx, Hy, Dx, Dy;
        scanf("%lf%lf", &Ax, &Ay);
        scanf("%lf%lf", &Bx, &By);
        scanf("%lf%lf", &Cx, &Cy);
        scanf("%lf%lf", &Ix, &Iy);
        scanf("%lf%lf", &Jx, &Jy);
        Dx = (Ax + Cx) / 2.0;
        Dy = (Ay + Cy) / 2.0;
        Hx = (3.0 * Ix) - (2.0 * Dx);
        Hy = (3.0 * Iy) - (2.0 * Dy);
        double res = area(Ax, Ay, Bx, By, Hx, Hy);
        printf("%.10lf\n", res);
        //cout << res << endl;

    }
    return 0;
}

