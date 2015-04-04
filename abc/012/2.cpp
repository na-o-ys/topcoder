#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int N; cin >> N;
    int s = N % 60;
    N /= 60;
    int m = N % 60;
    N /= 60;
    cout << setfill('0') << setw(2) << N;
    cout << ":";
    cout << setfill('0') << setw(2) << m;
    cout << ":";
    cout << setfill('0') << setw(2) << s;
    cout << endl;

    return 0;
}
