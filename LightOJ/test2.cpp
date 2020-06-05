#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n=3 ,r ,c;
    for (r=1;r<=n;r++){
        for(c = 1; c<=n-r;c++)printf(" ");
        for (c=1;c<=2*r-1;c++)printf("*");
        printf("\n");
    }
    for (r=n-1;r>=1;r--){
        for (c=1;c<=n-r;c++)printf(" ");
        for (c=1;c<=2*r-1;c++)printf("*");
        printf("\n");
    }
}
