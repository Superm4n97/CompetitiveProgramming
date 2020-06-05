#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int cal(int n, int d)
{
	if(n == 1) return 1;
	if(n % 2 == 1)
	{
		return cal(n - 1, d) + (n - 1) * d;
	}
	else
	{
		return cal(n - 1, d) - (n - 1) * d;
	}
}

int main()
{
      ll n,d;
      cin >> n >> d;
      ll sum = 0;
      for (int i=1 ; i<=n;i++){
            sum+=cal(i,d);
      }
      cout << sum << endl;


      return 0;
}

