#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    vector<int> vs;
    for (char c : s) {
        int v = c - '0';
        if (v <= 1) continue;
        if (v == 4) for (int w : {2, 2, 3}) vs.push_back(w);
        else if (v == 6) for (int w : {3, 5}) vs.push_back(w);
        else if (v == 8) for (int w : {2, 2, 2, 7}) vs.push_back(w);
        else if (v == 9) for (int w : {2, 3, 3, 7}) vs.push_back(w);
        else vs.push_back(v);
    }
    sort(all(vs), greater<int>());
    for (int v : vs) cout << v;
    cout << endl;
    return 0;
}
