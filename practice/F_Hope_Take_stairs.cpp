#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solveProblem(int x)
{
    // Your problem-solving code here
    int student, lift;
    cin >> student >> lift;

    int time = 0;

    int gotostu = abs(student-lift);
    time+= gotostu*4;

    int open = 3+5+3;
    time+=open;

    int gotodst = student*4;
    time+= gotodst;

    int reached = 3+5;
    time+= reached;

    cout <<"Case "<<x<<": "<< time << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    int x=1;
    while (t--)
    {
        solveProblem(x);
        x++;
    }

    return 0;
}