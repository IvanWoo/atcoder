#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) (a + b - 1) / b
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

const string YES = "Yes";
const string NO = "No";

void solve(long long a, long long b)
{
    int val = b;
    int n = 0;
    while (b != 0)
    {
        b /= 10;
        n += 1;
    }
    val += a * pow(10, n);
    cout << (val == pow((int)sqrt(val), 2) ? YES : NO) << endl;
}

int main()
{
    long long a;
    scanf("%lld", &a);
    long long b;
    scanf("%lld", &b);
    solve(a, b);
    return 0;
}