#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int m, n;
	cin >> m >> n;
	
	vector<pair<long long,long long>> predmeti (m);
	multiset<long long> kutije;
	
	for(int i = 0 ; i < m ; ++i){
		cin >> predmeti[i].second; // tezina
	} 
	
	for(int i = 0 ; i < m ; ++i){
		cin >> predmeti[i].first;  // vrednost
	}
	
	long long temp;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> temp;        // capacity
		kutije.insert(temp);
	}
	
	sort(predmeti.begin(), predmeti.end(), greater<pair<long long, long long>>());
	
	long long ans = 0;
	
	for(int i = 0 ; i < m ; ++i){
		auto it = kutije.lower_bound(predmeti[i].second);
		
		if(it != kutije.end()){
			ans += predmeti[i].first;
			kutije.erase(it);	
		}
	}
	
	cout << ans;
	
	
	return 0;
	
}
