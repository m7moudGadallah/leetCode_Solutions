#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	
	
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    
	    string s;
	    cin>>s;
	   
	    
	    vector<int>v(n,1);
	    
	    for(int i=1;i<n;i++){
	        if(s[i]==s[i-1]){
	            v[i]=0;
	        }
	    }
	    
	    
	    for(int i=1;i<n;i++){
	        v[i]+=v[i-1];
	    }
	    
	    int ans=0;
	    
	    for(int i=k;i<n;i++){
	        ans+=v[i]-v[i-k];
	    }
	    
	    cout<<ans<<endl;
	}
	return 0;
}