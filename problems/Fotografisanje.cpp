#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0 ; i < n ; ++i) cin >> a[i];
    
    if (n == 2) {
        cout << 1 << ' ' << a[1];
        return 0;
    }

    vector<long long> gap(n - 1);

    for (int i = 0 ; i < n - 1 ; ++i) gap[i] = a[i + 1] - a[i];


    vector<long long> pref(n - 1), suf(n - 1);

    pref[0] = gap[0];
    
    for (int i = 1 ; i < n - 1 ; ++i) pref[i] = max(pref[i - 1], gap[i]);
    

    suf[n - 2] = gap[n - 2];
    for (int i = n - 3; i >= 0; i--) {
        suf[i] = max(suf[i + 1], gap[i]);
    }

    long long best = (1LL << 60);
    int bestIdx = 1;
    long long bestTime = a[0];

    for (int i = 0 ; i < n ; ++i) {
        long long mx = 0;

        if (i >= 2) mx = max(mx, pref[i - 2]);
        if (i + 1 <= n - 2) mx = max(mx, suf[i + 1]);

        long long mergedGap = 0;
        if (i > 0 && i < n - 1) mergedGap = a[i + 1] - a[i - 1];
    
        long long y;

        if (i == 0) {
            y = a[1];
        }
        else if (i == n - 1) {
            y = a[n - 2];
        }
        else {
            y = (a[i - 1] + a[i + 1]) / 2;
        }

    	long long afterInsert = (mergedGap + 1) / 2;

        long long finalMx = max(mx, afterInsert);

        if (finalMx < best) {
            best = finalMx;
            bestIdx = i + 1;
            bestTime = y;
        }
    }

    cout << bestIdx << ' ' << bestTime;


    return 0;
}
