#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
      ofstream myfile;
      myfile.open ("example2.txt");
      //myfile << "Writing this to a file.\n";
      //cout << 99999 << endl;
      myfile << "99999 "<< "\n";
      for (int i=1;i<99999;i++){
        myfile << i*-1 << " " << i+1 << "\n";
      }
      myfile.close();
}
