#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n,i,x,k,m,nn,nt;
    float p,y;
    printf("\n The parameter n(number of trials) nt= ");
    scanf("%d",&nt);

    printf("\n Enter the value of p(<1.0) the probability of success= ");
    scanf("%f",&p);

    printf("\n Number of variants to be generated(nn)= ");
    scanf("%d",&nn);

    printf("\n Number of trials =%d\n Probability of Success= %4.2f ",nt,p);

    printf("\n Number of variants =%d \n ",nn);

    printf("\n Values of variate x: ");

    for(m=1; m<=nn; ++m)
    {
        x=0;
        n=nt;
        for(i=1; i<=n; ++i)
        {
            y=rand()/32768.0;
            if(y<p)
            {
                x=x+1;
            }
        }
        printf("%d ",x);
    }



}
