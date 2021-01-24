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

LL my_ceil(LL x, LL y)
{
    return (x + y - 1) / y;
}

void solve(long long N, long long H, std::vector<long long> a, std::vector<long long> b)
{
    LL ans = 0;
    LL max_a = *max_element(all(a));
    sort(all(b), greater());
    forn(i, 0, N)
    {
        if (H <= 0)
        {
            break;
        }
        if (b.at(i) > max_a)
        {
            ans += 1;
            H -= b.at(i);
        }
    }
    if (H > 0)
    {
        ans += my_ceil(H, max_a);
    }
    cout << ans << endl;
}

int main()
{
    long long N;
    scanf("%lld", &N);
    long long H;
    scanf("%lld", &H);
    std::vector<long long> a(N);
    std::vector<long long> b(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &a[i]);
        scanf("%lld", &b[i]);
    }
    solve(N, H, std::move(a), std::move(b));
    return 0;
}
