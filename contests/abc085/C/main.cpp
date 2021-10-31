#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(LL i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto const &it: a) cout << it << ' ';
#define DEBUGVV(a) for(auto const &it: a) { DEBUGV(it); cout << endl; };
#define CEIL(a, b) (a + b - 1) / b
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// clang-format on

using LL = long long;
using VI = vector<LL>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<LL, LL>;
using PLL = pair<LL, LL>;

void solve(LL N, LL Y)
{
    forn(i, 0, N + 1)
    {
        forn(j, 0, N + 1)
        {
            if (i + j > N)
                continue;
            LL val = 10000 * i + 5000 * j + (N - i - j) * 1000;
            if (val == Y)
            {
                cout << i << " " << j << " " << (N - i - j) << endl;
                return;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
}

int main()
{
    LL N;
    LL Y;
    cin >> N >> Y;
    solve(N, Y);
    return 0;
}
