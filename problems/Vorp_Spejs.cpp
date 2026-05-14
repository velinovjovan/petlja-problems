#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	int a_x, a_y;
	cin >> a_x >> a_y;
	
	int b_x, b_y;
	cin >> b_x >> b_y;
	
	int x_len = min(abs(b_x - a_x), n - abs(b_x - a_x));
	int y_len = min(abs(b_y - a_y), m - abs(b_y - a_y));
	
	
	cout << x_len + y_len;
	
	
	return 0;
	
}
