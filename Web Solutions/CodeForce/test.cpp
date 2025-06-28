#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solveProblem(int a, int b)
{
    cout << "the mod is: " << a % b << endl;
}

int32_t main()
{
    int a, b;
    cout << "enter the first number: ";
    cin >> a;
    cout << "enter the second number: ";
    cin >> b;
    solveProblem(a, b);
    return 0;
}