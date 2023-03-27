#include <bits/stdc++.h> // 백준 2979 1-C
using namespace std;

int A, B, C, D;
int xIn, yIn, zIn;
int xOut, yOut, zOut;

int cOne, cTwo, cThree;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
    cin >> xIn >> xOut;
    cin >> yIn >> yOut;
    cin >> zIn >> zOut;

    int inMin = min({xIn, yIn, zIn});
    int outMax = max({xOut, yOut, zOut});

    // cout << "inMin : " << inMin << "\n";
    // cout << "outMax : " << outMax << "\n";

    while (inMin <= outMax)
    {
        int count = 0;

        // cout << "inMin : " << inMin << "\n";

        if (inMin > xIn && inMin <= xOut)
        {
            count++;
        }
        if (inMin > yIn && inMin <= yOut)
        {
            count++;
        }
        if (inMin > zIn && inMin <= zOut)
        {
            count++;
        }

        // cout << "count : " << count << "\n";

        if (count == 1)
        {
            cOne++;
        }
        else if (count == 2)
        {
            cTwo++;
        }
        else if (count == 3)
        {
            cThree++;
        }
        inMin++;
        count = 0;
    }

    // cout << "cOne : " << cOne << "\n";
    // cout << "cTwo : " << cTwo << "\n";
    // cout << "cThree : " << cThree << "\n";

    D = A * cOne + B * cTwo * 2 + C * cThree * 3;
    cout << D << "\n";

    return 0;
}