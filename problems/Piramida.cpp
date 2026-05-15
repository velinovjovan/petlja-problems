#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	string s;
	unordered_map<char, int> mapa;
	
	for(int i = 0; i < n ; ++i){
		cin >> s;
		
		int ans = 0;
				
		for(int j = 0 ; j < s.length() ; ++j){
			if(mapa[s[j]]){
				mapa[s[j]] --;
				ans ++;
			}
		}
		
		for(int j = 0; j < s.length() ; ++j){
			mapa[s[j]] ++;
		}
		
		if(ans != i){
			cout << i;
			return 0;
		}
	}
	
	cout << n;
	return 0;
}
