#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;
const int INF = 1<<29;

int main(int argc, char const* argv[])
{
    string s, p; cin >> s >> p;
    int S = s.length(), P = p.length();
    vector<int> dp(P, -1);
    vector<int> ers(P, INF);
    int cnt = 0;
    int pos = 0;
    vector<int> M;
    loop (S, i) {
        //cout << i << ", " << pos << endl;
        char c = s[i];
        if (c == p[pos]) {
            if (pos == P-1) {
                int j = i-1;
                pos--;
                for (; pos >= 0; j--) {
                    if (s[j] == p[pos]) pos--;
                }
                M.push_back(i-j-P);
                pos = 0;
            } else {
                pos++;
            }
        }
    }
    //for (int m : M) cout << m << endl;
    int found = M.size();
    sort(M.begin(), M.end());
    loop ((int)M.size()-1, i) M[i+1] += M[i];
    vector<int> ans(S+1);
    for (int m : M) ans[m]++;
    loop (found, i) ans[S-P*(i+1)+1]--;
    loop (S, i) ans[i+1] += ans[i];
    for (int a : ans) cout << a << " ";
    cout << endl;
    return 0;
}
