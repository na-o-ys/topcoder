#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;
using ld = long double;

int fact(int n) {
    if (!n) return 1;
    return fact(n-1)*n;
}

int main(int argc, char const* argv[])
{
    string a, b; cin >> a >> b;
    int n = a.length();

    int plus = 0, minus = 0;
    int bp = 0, bm = 0, bq = 0;
    for (char c : a) if (c == '+') plus++; else minus++;
    for (char c : b) if (c == '+') bp++; else if (c == '-') bm++; else bq++;
    if (plus < bp || minus < bm) {
        cout << 0 << endl;
        return 0;
    }
    ld pat = fact(bq)/(fact(plus-bp)*fact(minus-bm));
    cout << setprecision(11) << pat/(1<<bq) << endl;
    return 0;
}
