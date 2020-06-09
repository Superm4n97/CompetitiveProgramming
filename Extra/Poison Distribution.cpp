#include<bits/stdc++.h>

using namespace std;

int main()
{

    int k,j,x,nn;
    float lamda,cumprob,fact,prob,y,mean;

    printf("\nThe value of mean(lambda)= ");
    scanf("%f",&lamda);

    printf("\nNumber of variants to be generated(nn)= ");
    scanf("%d",&nn);

    printf("\nValues of variate x: \n");

    mean=lamda;

    for(j=1; j<=nn; ++j)
    {
        fact=1;
        x=1;
        cumprob=0;
        y=rand()/32768.0;

        while(y>cumprob)
        {
            cumprob+=pow(2.718282,-mean)*pow(mean,x)/fact;
            fact*=x;
            x++;
        }
        cout << x << " ";

    }
    printf("\n");
}
