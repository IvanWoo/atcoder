#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
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
using LD = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VLD = vector<LD>;
using VVLD = vector<VLD>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

void solve(long long N, std::vector<long double> p)
{
    // dp[i][j] := 最初の i 枚のコインを投げたときに、表が j 枚となる確率
    VVLD dp(N + 1, VLD(N + 1, 0.0));
    dp[0][0] = 1.0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i + 1][j + 1] += dp[i][j] * p[i];
            dp[i + 1][j] += dp[i][j] * (1.0 - p[i]);
        }
    }

    double res = 0.0;
    for (int j = N / 2 + 1; j <= N; j++)
        res += dp[N][j];
    cout << fixed << setprecision(10) << res << endl;
}

int main()
{
    long long N;
    std::scanf("%lld", &N);
    std::vector<long double> p(N);
    for (int i = 0; i < N; i++)
    {
        std::scanf("%Lf", &p[i]);
    }
    solve(N, std::move(p));
    return 0;
}
