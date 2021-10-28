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

const long long INF = 1LL << 60;

void solve(long long N, long long W, std::vector<long long> w, std::vector<long long> v)
{
    const LL sum_v = std::accumulate(v.begin(), v.end(), 0LL);
    VLL dp(sum_v + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = sum_v; j >= v[i]; j--)
        {
            dp[j] = min(dp[j], w[i] + dp[j - v[i]]);
        }
    }

    for (int j = sum_v; j >= 0; j--)
    {
        if (dp[j] <= W)
        {
            cout << j << endl;
            return;
        }
    }
}

int main()
{
    long long N;
    std::scanf("%lld", &N);
    long long W;
    std::scanf("%lld", &W);
    std::vector<long long> w(N);
    std::vector<long long> v(N);
    for (int i = 0; i < N; i++)
    {
        std::scanf("%lld", &w[i]);
        std::scanf("%lld", &v[i]);
    }
    solve(N, W, std::move(w), std::move(v));
    return 0;
}
