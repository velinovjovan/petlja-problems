#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,k;
	long long c;
	cin >> n >> c >> k;
	
	long long zero_count = 0;
	long long sum = 0;
	
	vector<long long> a (n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
		sum += a[i];
		if(!a[i]) zero_count++;	
	}	
	
	sort(a.begin(), a.end()); // samo treba maks ali me mrzi i prolazi i nlogn
	
	long long ans = 0;
	
	if(k == 0){
		ans += a.size() - zero_count;
		ans += min(zero_count, c);
		
		cout << ans << ' ' << min(zero_count, c);
	}
	else if(k == 1){
		ans += sum;
		ans += c;
		
		cout << ans << ' ' << c;
	}
	else{
		for(int i = 0 ; i < n - 1 ; ++i){
			ans += a[i] * a[i];
		}
		
		if(a[n-1] < 0){
			if(2*abs(a[n-1]) < c){
				a[n-1] += c;
				ans += a[n-1] * a[n-1];
				cout << ans << ' ' << c;
			}
			else{
				ans += a[n-1] * a[n-1];
				cout << ans << ' ' << 0;
			}
		}
		else{
			a[n-1] += c;
			ans += a[n-1] * a[n-1];
			cout << ans << ' ' << c;	
		} 
		
	}
	
	
	return 0;
}
