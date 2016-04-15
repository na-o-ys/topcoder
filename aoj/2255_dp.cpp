#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

string line;
int len;
set<int> dp[201][201];

void num(int s, int t) {
    int v = 0;
    for (int i = s; i < t; i++) {
        if (line[i] < '0') return;
        v *= 10;
        v += line[i] - '0';
    }
    dp[s][t].insert(v);
}

void brace(int s, int t) {
    if (line[s] == '(' && line[t - 1] == ')') dp[s][t] = dp[s + 1][t - 1];
}

int isOpr(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int apply(char opr, int a, int b, int& ret) {
    if (!b && opr == '/') return 0;
    if (opr == '+') ret = a + b;
    if (opr == '-') ret = a - b;
    if (opr == '*') ret = a * b;
    if (opr == '/') ret = a / b;
    return 1;
}

int main()
{
    while (1) {
        cin >> line;
        if (line == "#") break;
        len = line.length();
        loop (len + 1, i) loop (len + 1, j) dp[i][j].clear();
        loop (len, d) loop (len, s) {
            int t = s + d + 1;
            if (t > len) continue;
            num(s, t);
            brace(s, t);
            for (int u = s + 1; u < t; u++) {
                if (!isOpr(line[u])) continue;
                for (int a : dp[s][u]) for (int b : dp[u + 1][t]) {
                    int ret;
                    if (apply(line[u], a, b, ret)) dp[s][t].insert(ret);
                }
            }
        }
        cout << dp[0][len].size() << endl;
    }
    return 0;
}
