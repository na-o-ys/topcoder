#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)
#define repeat(n) for(int i__=0;i__<n;i__++)
#define each(itr, c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define r_each(itr, c) for(__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); itr++)

using namespace std;

int main(int argc, char const* argv[])
{
    int a, b; cin >> a >> b;
    double PA[2501] = {};
    double PB[2501] = {};

    loop(b, j) PA[j+1] = 1.0/b;

    loop_from_to(2, a, i) {
        double tmp[2501] = {};
        loop_from_to(i, b*i, j) {
            loop(b, k) tmp[j] += PA[j-k-1] / b;
        }
        loop(2501, j) PA[j] = tmp[j];
    }

    loop_from_to(a, a*b, i) {
        cout << "i: " << i << ", " << PA[i] << endl;
    }
    return 0;
}
