#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	
	double ans = 0;
	
	while(t--){
		double a, b;
		cin >> a >> b;
		
		ans = max(ans, (b-0.5)/a);
	}
	
	cout << ans;
	
	
	return 0;
}
