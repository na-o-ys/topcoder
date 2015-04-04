#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<int> H(n); loop (n, i) cin >> H[i];
    stack<int> s;
    loop (n, i) {
        cout << s.size() << endl;
        while (s.size() && s.top() < H[i]) s.pop();
        s.push(H[i]);
    }
    return 0;
}
