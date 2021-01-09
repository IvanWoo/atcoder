#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
pair<bool, VI> backtrack(string ABCD, VI ops, int p)
{
    int res = (int)ABCD[0] - '0';
    for (int i = 0; i < 3; i++)
    {
        res += ((int)ABCD[i + 1] - '0') * ops[i];
    }
    if (res == 7)
        return make_pair(true, ops);

    for (int i = p; i < 3; i++)
    {
        ops[i] *= -1;
        pair<bool, VI> output = backtrack(ABCD, ops, p + 1);
        if (output.first)
            return output;
        ops[i] *= -1;
    }
    return make_pair(false, ops);
}

void solve(std::string ABCD)
{
    VI ops(3, 1);
    int p = 0;
    pair<bool, VI> answer = backtrack(ABCD, ops, p);
    cout << ABCD[0];
    for (int i = 0; i < 3; i++)
    {
        cout << (answer.second[i] == 1 ? "+" : "-") << ABCD[i + 1];
    }
    cout << "=7" << endl;
}

int main()
{
    std::string ABCD;
    std::cin >> ABCD;
    solve(ABCD);
    return 0;
}
