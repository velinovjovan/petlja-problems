#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b, c;
    cin >> a >> b >> c;

    vector<string> v = {
        a + b + c,
        a + c + b,
        b + a + c,
        b + c + a,
        c + a + b,
        c + b + a
    };

    cout << *max_element(v.begin(), v.end());
    

    return 0;
}
