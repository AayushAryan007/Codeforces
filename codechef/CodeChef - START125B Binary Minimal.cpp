// Problem: Binary Minimal
// Contest: CodeChef - START125B
// URL: https://www.codechef.com/START125B/problems/BILM
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h> 
using namespace std;  
#define endl "\n"
#define lo long long
#define dob long double
#define ll long long int
// #define int long long int
#define mod 1000000007
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fr(i, x, n) for (ll i = x; i < n; i++)
#define nfr(i, x, n) for (int i = x; i > n; i--)
#define sp(x) setprecision(x)
#define vi vector<int>
#define vpp vector<pair<int,int>>
#define vs vector<string>
#define vll vector<long long>
#define in(v)  for(auto &item : v) cin>>item;
#define inp(v)  for(auto &item : v) cin>>item.ff>>item.ss;
#define ub(x) upper_bound(x)
// #define pq priority_queue<int, std::vector<int>, std::greater<int>>
#define ss second
#define ff first
//count set bits\|/
#define bp(a) __builtin_popcount(a)

int binpow(int a, int b)
{
  if(b==0)
  return 1;
  int res=binpow(a,b/2);

  if(b%2)
  return res*res*a;
  else
  return res*res;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int lowpowerof2(int n) { return 1LL << (int)log2(n); }
int highpowerof2(int n) { return 1LL << (int)ceil(log2(n)); }
bool ispowerof2(int n) { return (n != 0) && ((n & (n - 1)) == 0); }

// int gcd(int a, int b)
// {
    // // Everything divides 0
    // if (a == 0)
       // return b;
    // if (b == 0)
       // return a;
//   
    // // base case
    // if (a == b)
        // return a;
//   
    // // a is greater
    // if (a > b)
        // return gcd(a-b, b);
    // return gcd(a, b-a);
// }

//prime ll
bool isprime(long long int n)  //to check prime
{
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)return false;
    }
    return true;
}
//prime int
bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 


int LIS(vector<int> &a)//returns longest non decreasing subsequence
{
  //lnds[i]=element at which an increasng subsequence of length 'i' ends

  vector<int> lis;
  for(auto &x:a)
  {
    auto it=upper_bound(lis.begin(),lis.end(), x); //upper_bound for non-decreasing
    if(it==lis.end())
    lis.push_back(x);
    else
    *it=x;
  }

  return lis.size();
}
 
 //iota(v.begin(),v.end(),1); assign 1-n incrementation in vector
 void reverse(int arr[], int index, int count)
{
    if (index < count)
    {
        swap(arr[index], arr[count]);
        reverse(arr, index + 1, count - 1);
    }
}

//print binary of int ,10 bits
void printBinary(int num){
	for(int i=10;i>=0;i--){
		cout<<((num>>i)&1);
	}
	cout<<endl;
}
// 
// long long powi(long long base, long long exponent) {
    // long long result = 1;
    // while (exponent > 0) {
        // if (exponent % 2 == 1) {
            // result *= base;
        // }
        // base *= base;
        // exponent /= 2;
    // }
    // return result;
// }

//i power of number function
int powi(int base, int exponent) {
     int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}

ll sumvec(vector<ll> & v){
	ll sum=0;
	fr(i,0,v.size()){
		sum+=v[i];
	}
	return sum;
}

// int N=1e7+5;
// vector<ll> spf(N+1,1);
// 
// void sieve(){
	// ll i,j;
	// for(i=2;i<N;i++){
		// if(spf[i]==1){
			// spf[i]=i;
			// for(j=i*i;j<=N;j+=i){
				// if(spf[j]==1){
					// spf[j]=i;
				// }
			// }
		// }
	// }
// }

// #ifndef Aayush_Ryan
// #include "C:\Users\Ayush\Documents\Codeforces\handle_debug.hpp" 
// #define debug(...) cout<<'[';debug_print(#__VA_ARGS__, __VA_ARGS__);cout<<"]\n";
// #else
// #define debug(...)
// #endif
 
////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
// void solve() {
// 	
	// // int n, k;
    // // cin >> n >> k;
    // // string s;
    // // cin >> s;
// // 
    // // vector<char> result(s.begin(), s.end());
    // // vector<int> ind;
    // // int cnt = 0;
// // 
    // // for (int i = 0; i < n; i++) {
        // // if (s[i] == '1') {
            // // cnt++;
        // // }
    // // }
// // 
    // // if (cnt > k) {
        // // for (int i = 0; i < n; i++) {
            // // if (s[i] == '1' && k > 0) {
                // // result[i] = '0';
                // // k--;
            // // }
        // // }
        // // cout << string(result.begin(), result.end()) << endl;
    // // } else {
        // // for (int i = 0; i < (n - k); i++) {
            // // cout << 0;
        // // }
        // // cout << endl;
// // 
	// // }
// 	
    // int n, k;
    // cin >> n >> k;
    // string s;
    // cin >> s;
// 
    // string ans = "";
//     
//     
    // vector<int> pref(n,0);
    // if(s[n-1]=='1') pref[n-1]=1;
    // for(int i=n-2;i>=0;i--){
    	// if(s[i]=='1'){
    		// pref[i]=pref[i]+pref[i+1]+1;
    	// }
    	// else{
    		// pref[i]=pref[i+1];
    	// }
    // }
    // // debug(pref)
// //     
    // for(int i=0;i<n;i++){
    	// if(k>0){
//     		   
    		   	// if(pref[i]>0){
    		   		// if(s[i]=='1') k--;
    		   		// ans+="0";
    		   		// }
    		   	// else {
    		   		// ans+="";
    		      	// k--;
    		   	// }
//     		   
//     		
    	// }
    	// else{
    		// ans+=s[i];
    	// }
    // }
    // cout<<ans<<endl;
//     
    // // 
    // // if (k > 0 and s[0] == '1') {
        // // ans += '0';
        // // k--;
        // // flag++;
    // // }
// //     
    // // int check=flag;
// // int temp;
    // // // Move to the first '1' after the initial '1' at index 0
    // // while (flag < n && s[flag] != '1') {
// //        
        // // flag++;
        // // if(s[flag]=='1'){
            // // temp=check;
            // // check=flag;
            // // flag=temp;
            // // break;
        // // }
    // // }
// //     
    // // fr(i,flag,check){
    	// // ans+="0";
// //     	
    // // }
// //      
    // // // Continue processing the rest of the string
    // // for (int i = check; i < n; i++) {
        // // if (k > 0) {
            // // if (s[i] == '1') {
                // // ans += '0';
                // // k--;
            // // } else {
                // // ans += "";
                // // k--;
            // // }
        // // } else {
            // // ans += s[i];
        // // }
    // // }
// // 
    // // cout << ans << endl;
// }

void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int c1=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			c1++;
		}
	}
	string ans="";
	if(c1<=k){
		n=n-k;
		for(int i=0;i<n;i++){
			ans+="0";
		}
		
		cout<<ans<<endl;
		return;
	}
	
	
	else {
		for(int i=0;i<n;i++){
			if(k<=0) break;
			else if(s[i]=='1'){
				s[i]='0';
				k--;
			
				
			}
			
		}
	}
	
	cout<<s<<endl;
	
	
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}