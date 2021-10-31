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
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

void solve(long long N, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c)
{
    VLL dp(3);
    dp[0] = a[0];
    dp[1] = b[0];
    dp[2] = c[0];
    for (int i = 1; i < N; i++)
    {
        VLL temp_dp(3);
        // copy dp to temp_dp
        for (int j = 0; j < 3; j++)
        {
            temp_dp[j] = dp[j];
        }
        dp[0] = a[i] + max(temp_dp[1], temp_dp[2]);
        dp[1] = b[i] + max(temp_dp[0], temp_dp[2]);
        dp[2] = c[i] + max(temp_dp[0], temp_dp[1]);
    }

    LL ans = 0;
    for (int j = 0; j < 3; j++)
    {
        ans = max(ans, dp[j]);
    }

    printf("%lld\n", ans);
}

int main()
{
    long long N;
    std::scanf("%lld", &N);
    std::vector<long long> a(N);
    std::vector<long long> b(N);
    std::vector<long long> c(N);
    for (int i = 0; i < N; i++)
    {
        std::scanf("%lld", &a[i]);
        std::scanf("%lld", &b[i]);
        std::scanf("%lld", &c[i]);
    }
    solve(N, std::move(a), std::move(b), std::move(c));
    return 0;
}
