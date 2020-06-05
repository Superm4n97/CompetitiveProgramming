#include<bits/stdc++.h>

using namespace std;

int main()
{

    int i,j,k,m,nn;
    float x,r,mean;
    printf("\n Enter the values of Mean: ");
    scanf("%f",&mean);

    printf("\n Enter the values of parameter k: ");
    scanf("%d",&k);

    printf("\n Number of variants to be generated(nn)= ");
    scanf("%d",&nn);

    printf("\n mean=%6.2f  k=%d  nn=%d ",mean,k,nn);

    printf("\n Values of variate x: ");

    for(m=1; m<=nn; ++m)
    {
        float prod=1.0;
        for(i=1; i<=k; ++i)
        {
            r=rand()/32768.0;
            prod=prod*r;
        }
        x=mean*(-1./k)*log(prod);
        printf("%6.2f",x);
    }



}


