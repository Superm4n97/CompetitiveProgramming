#include<bits/stdc++.h>

using namespace std;

int main()
{

    int x,j,nn,m,s,k;
    float p,r;

    printf("\n Enter the value of p(<1.0)= ");
    scanf("%f",&p);

    printf("\nEnter the value of k(>=1.0)= ");
    scanf("%d",&k);

    printf("\nThe value of parameter k= %d\n",k);

    printf("\nProbability of Success= %4.2f\n",p);

    printf("\nNumber of variants generated= ");
    scanf("%d",&nn);

    printf("\nValues of variate x: ");

    for(j=1; j<=nn; ++j)
    {
        x=0;
        s=0;
        while(s<k)
        {
            r=rand()/32768.0;
            if(r<=p)s++;
            x++;
        }
        cout << x << " ";
    }
    cout << endl;
}
