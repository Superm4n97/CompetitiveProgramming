#include<bits/stdc++.h>

using namespace std;

int main()
{

    int i,j,m,nn;
    float t,sum,x,mue,sigma;
    printf("\n Enter the values of MUE: ");
    scanf("%f",&mue);

    printf("\n Enter the values of SIGMA: ");
    scanf("%f",&sigma);

    printf("\n Number of variants to be generated(nn)= ");
    scanf("%d",&nn);

    printf("\n mue=%4.2f  sigma=%4.2f  nn=%4d ",mue,sigma,nn);

    printf("\n Values of variate x: ");

    for(m=1; m<=nn; ++m)
    {
        sum=0;
        for(i=1; i<=12; ++i)
        {
            sum+=rand()/32768.0;
        }
        cout << mue+sigma*(sum-6) << endl;
    }
    cout << endl;
}
