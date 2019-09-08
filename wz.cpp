
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

double win_rate(int red, int blue) {
    if (red <= 0)
        return 0.0;
    if (blue < 0)
        return 1;
    if (red == 1 && blue == 1)
        return 0.5;
    if (red == 1 && blue == 0)
        return 1;
    double res = ((double) red / (red + blue));
    res += ((double) blue / (red + blue)) * ((double) (blue - 1) / (red + blue - 1)) *
           ((double) (blue - 2) / (red + blue - 2)) * win_rate(red, blue - 3) +
           (double) red / (red + blue - 2) * win_rate(red - 1, blue - 2);
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << setiosflags(ios::fixed) << setprecision(5) << win_rate(n, m);
    return 0;
}