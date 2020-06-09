#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    for (int i=1;i<n;i++){
        if (s[i]==s[i-1]){
            s[i]++;
            if (s[i]>'z')s[i] = 'a';
            if (s[i]==s[i+1])s[i]++;
            if (s[i]>'z')s[i] = 'a';
        }
    }
    cout << s << endl;


    return 0;
}
