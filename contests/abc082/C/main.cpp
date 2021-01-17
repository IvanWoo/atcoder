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

void solve(long long N, std::vector<long long> a)
{
    unordered_map<LL, LL> counter;
    forn(i, 0, N)
    {
        if (counter.find(a[i]) != counter.end())
        {
            counter[a[i]] += 1;
        }
        else
        {
            counter[a[i]] = 1;
        }
    }
    LL ans = 0;
    for (auto const &[key, val] : counter)
    {
        if (key > val)
        {
            ans += val;
        }
        else
        {
            ans += (val - key);
        }
    }
    cout << ans << endl;
}

int main()
{
    long long N;
    scanf("%lld", &N);
    std::vector<long long> a(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
