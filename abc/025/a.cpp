#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;

int main()
{
    string s; cin >> s;
    int n; cin >> n; n--;
    cout << s[n/5] << s[n%5] << endl;
    return 0;
}
