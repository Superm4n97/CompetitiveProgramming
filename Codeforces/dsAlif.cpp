#define pb push_back
#define ff first
#define ss second
#define ll long long
#define maxn 505
#define INF 1e18
#define mod 10000007
#include <bits/stdc++.h>
using namespace std;

double dist(double x1, double y1, double x2, double y2){
     double res = sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
     return res;
}

double area(double Ax, double Ay, double Bx, double By, double Cx, double Cy){
    double a, b, c, s, res;
    a = dist(Ax, Ay, Bx, By);
    b = dist(Bx, By, Cx, Cy);
    c = dist(Ax, Ay, Cx, Cy);
    s = (a + b + c) / 2.0;
    res = sqrt( s * (s - a) * (s - b) * (s - c)  );
    return res;
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
        Dx = (Bx + Cx) / 2.0;
        Dy = (By + Cy) / 2.0;
        Hx = (3.0 * Jx) - (2.0 * Dx);
        Hy = (3.0 * Jy) - (2.0 * Dy);
        double res = 2.0 * area(Cx, Cy, Bx, By, Hx, Hy);
        printf("%.10lf\n", res);
        cout << res << endl;

    }
    return 0;
}

