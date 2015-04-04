#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)
#define repeat(n) for(int i__=0;i__<n;i__++)
#define multi_cin(n, array) loop(n,i){cin>>array[i];}
#define assign_if_smaller(var, val) if(var>val)var=val;
#define assign_if_larger(var, val) if(var<val)var=val;
#define each(itr, c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define r_each(itr, c) for(__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); itr++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull toInt8(string str) {
  ull ans = 0;
  loop(str.length(), i) {
    ans *= 8;
    int d = str[i] - '0';
    if (d == 9) {
      ans += 7;
      repeat(str.length() - i - 1) {
        ans *= 8;
        ans += 7;
      } 
      break;
    }
    if (d == 4) {
      ans += 3;
      repeat(str.length() - i - 1) {
        ans *= 8;
        ans += 7;
      }
      break;
    }

    if (d >= 4) d--;
    ans += d;
  }

  return ans;
}

ull toInt(string str) {
  ull ans = 0;
  each(c, str) {
    ans *= 10;
    ans += *c - '0';
  }
  return ans;
}

int main(int argc, char const* argv[])
{
  string a, b; cin >> a >> b;

  ull count8 = 0;

  ull a10 = toInt(a);
  stringstream ss;
  ss << a10 - 1;
  ull a8 = toInt8(ss.str());
  ull b8 = toInt8(b);
  count8 = b8 - a8;
  cout << toInt(b) - toInt(a) + 1 - count8 << endl;
  return 0;
}
