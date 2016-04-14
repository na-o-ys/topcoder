#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

set<int> ans;
string line; 
int len;

int apply(char opr, int a, int b) {
    if (opr == '+') return a + b;
    if (opr == '-') return a - b;
    if (opr == '*') return a * b;
    if (opr == '/') return a / b;
}

int reduce(stack<int>& N, stack<char>& O) {
    char opr = O.top(); O.pop();
    int v = N.top(); N.pop();
    int w = N.top(); N.pop();
    if (opr == '/' && !v) return 0;
    N.push(apply(opr, w, v));
    return 1;
}

void read(int i, stack<int> N, stack<char> O) {
    if (i == len) {
        while (O.size()) if (!reduce(N, O)) return;
        ans.insert(N.top());
        return;
    }
    if (line[i] >= '0') {
        int v = 0;
        while (i < len && line[i] >= '0') v *= 10, v += line[i++] - '0';

        N.push(v);
        read(i, N, O);
        while (!O.empty() && O.top() != '(' && reduce(N, O)) read(i, N, O);
        return;
    }
    if (line[i] == ')') {
        while (O.top() != '(') if (!reduce(N, O)) return;
        O.pop();
        read(i+1, N, O);
        while (!O.empty() && O.top() != '(' && reduce(N, O)) read(i+1, N, O);
        return;
    }
    O.push(line[i]);
    read(i+1, N, O);
    return;
}

int main()
{
    while (1) {
        ans.clear();
        cin >> line;
        len = line.length();
        if (line == "#") break;
        read(0, stack<int>(), stack<char>());
        cout << ans.size() << endl;
    }
    return 0;
}
