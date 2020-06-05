#include<bits/stdc++.h>
#define maxn    300005
#define ll      long long int

using namespace std;

ll A[maxn] , B[maxn] , n , k;

int main()
{
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;i++){
        scanf("%d",&A[i]);
        if (A[i]==0)B[i] = B[i-1]+1;
        else B[i] = B[i-1];
    }

    int b = 0 , e = 1 , mx = 0 , index = 0;
    while(e<=n){
        while(B[e] - B[b]>k)b++;
        //cout << " b-" << b << "   e-" << e << endl;
        if (e-b>mx){
            mx = e-b;
            index = b+1;
        }
        e++;
    }
    cout << mx << endl;
    for (int i=1;i<=n;i++){
        if (i>=index && i-index<mx)cout << 1 << " ";
        else cout << A[i] << " ";

    }



    return 0;
}
