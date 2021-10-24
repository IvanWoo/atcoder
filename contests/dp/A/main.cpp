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

void solve(long long N, std::vector<long long> h)
{
    VLL dp(N, 0);
    for (int i = 1; i < N; i++)
    {
        if (i == 1)
        {
            dp[i] = abs(h[i] - h[i - 1]);
        }
        else
        {
            dp[i] = min(dp[i - 1] + abs(h[i - 1] - h[i]), dp[i - 2] + abs(h[i - 2] - h[i]));
        }
    }
    printf("%lld\n", dp[N - 1]);
}

int main()
{
    long long N;
    std::scanf("%lld", &N);
    std::vector<long long> h(N);
    for (int i = 0; i < N; i++)
    {
        std::scanf("%lld", &h[i]);
    }
    solve(N, std::move(h));
    return 0;
}
