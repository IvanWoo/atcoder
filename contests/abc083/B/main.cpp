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

int sum_digit(int n)
{
    int ans = 0;
    string n_s = to_string(n);
    for (auto c : n_s)
    {
        ans += c - '0';
    }
    return ans;
}

void solve(int N, int A, int B)
{
    int ans = 0;
    forn(i, 1, N + 1)
    {
        int s = sum_digit(i);
        if (s >= A && s <= B)
        {
            ans += i;
        }
    }
    cout << ans << endl;
}

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    solve(N, A, B);
    return 0;
}
