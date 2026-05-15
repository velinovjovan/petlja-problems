#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<pair<int,int>>> dp(n);

   for(int i = 0; i < n; i++){
    dp[i].push_back({a[i], i});
    if(i == 0) continue; 
    for(auto& [val, idx] : dp[i-1]){
        int nval = val & a[i];
        if(nval != dp[i].back().first)
            dp[i].push_back({nval, idx});
        else
            dp[i].back().second = idx;
    }
}

    while(q--){
        int l, r;
        cin >> l >> r;
        l--; r--;

        auto& v = dp[r];

        int lo = 0, hi = v.size() - 1, ans = v.back().first;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(v[mid].second <= l){
                ans = v[mid].first;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        cout << ans << '\n';
    }

    return 0;
}
