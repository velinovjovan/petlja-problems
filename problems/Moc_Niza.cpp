#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> count (10, 0);
	
	int temp;
	for(int i = 0 ; i < n ; ++i){
		cin >> temp;
		count[temp] ++;
	}
	
	temp = 0;
	vector<int> sorted;
	while (temp <= 9){
		if(count[temp]){
			sorted.push_back(temp);
			count[temp] --;
		}
		else{
			temp ++;
		}
	}
	
	int susednih = n - k;
	int ans = INT_MAX;
	
	for(int i = 0 ; i < n - susednih + 1 ; ++i){
		ans = min(ans, sorted[i + susednih - 1] * sorted[i + susednih - 1] - sorted[i]*sorted[i]);
	}
	
	cout << ans;
	
	
	return 0; 
	
}
