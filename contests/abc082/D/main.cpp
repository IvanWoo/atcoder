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

bool is_achievable(int start, int target, VI nums)
{
    int center = 8000 + 5;
    VVI dp(nums.size() + 1, VI(center * 2, 0));
    dp[0][center + start] = 1;
    forn(i, 0, nums.size())
    {
        forn(j, 0, center * 2)
        {
            if (dp[i][j] == 1)
            {
                dp[i + 1][j + nums[i]] = 1;
                dp[i + 1][j - nums[i]] = 1;
            }
        }
    }
    return dp[nums.size()][center + target] == 1;
}

void solve(string s, int x, int y)
{
    VVI acc(2);
    int flag = 0;
    int counter = 0;
    forn(i, 0, s.size())
    {
        if (s[i] == 'F')
        {
            counter += 1;
        }
        else
        {
            acc[flag].push_back(counter);
            flag ^= 1;
            counter = 0;
        }
    }
    acc[flag].push_back(counter);
    // Initially, the robot is facing in the positive x-axis direction.
    auto x_start = acc[0][0];
    acc[0].erase(acc[0].begin());
    cout << ((is_achievable(x_start, x, acc[0]) && is_achievable(0, y, acc[1])) ? YES : NO) << endl;
}

int main()
{
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    solve(s, x, y);
    return 0;
}
