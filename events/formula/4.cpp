#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;

double memo[100][100];
double calc(int m, int n) {
    if (memo[m][n] != -1) return memo[m][n];
    if (m == 0) return memo[m][n] = 0;
    double ret = 0;
    ret += 1.0/n * calc(m-1, n-1);
    ret += 1.0*(m-1)/n * (2.0 + calc(m-1, n-1));
    if (n != m) ret += 1.0*(n-m)/n * (2.0 + calc(m, n-1));
    return memo[m][n] = ret;
}

int main(int argc, char const* argv[])
{
    string S, K; cin >> S >> K;
    int n = 36-K.length();
    int m = 0;
    loop (S.length(), i) {
        char c = S[i];
        if (K.find(c) == string::npos
                && S.substr(0, i).find(c) == string::npos) m++;
    }
    fill(memo[0], memo[99]+100, -1);
    cout << setiosflags(ios::fixed) << setprecision(10);
    cout << S.length() + calc(m, n) << endl;
    return 0;
}
