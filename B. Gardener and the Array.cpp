// Problem: B. Gardener and the Array
// Contest: Codeforces - Codeforces Round 843 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1775/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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


void solve(){
	int n;
	cin>>n;
	
	unordered_map<int,int> mp;
	vector<vector<int>>v(n);
	
	for(int i=0;i<n;i++){
		int bits=0;
		cin>>bits;
		
		while(bits--){
			int x=0;
			cin>>x;
			mp[x]++;
			v[i].pb(x);
		}
	}
	
	for(auto & bits:v){
		int flag=1;
		
		for(auto& i:bits){
			if(mp[i]==1){
				flag=0;
				break;
			}
		}
		
		if(flag){
			cout<<"Yes"<<endl;
			return;
		}
	}
	
	cout<<"No"<<endl;
}

// void solve(){
	// ll n;
	// cin>>n;
// 	
	// vector<ll> nums(n);
	// map<ll,ll> mp; // to store count of how many time a certain bit was set in one or more than oone number
// 	
	// for(ll i=0;i<n;i++){
		// ll x;
		// cin>>x;ll num=0;
// 		
		// while(x--){
			// ll b;
			// cin>>b;
			// mp[b]++; //counting the bit in mape
			// num+=(1<<b); // set all biits of number in nums integer
// 			
		// }
		// nums[i]=num; //push in nums array
// 		
	// }
// 	
	// // now for  each elemtn in array nums, check if we remove one elemtn will it affect over all OR
	// // we can do this by checking if any of the set bits in the particular number appeared in some other elemmtn to or not, if not answer is no as this set bit  is contributiong to the OR
// 	
	// // debug(mp)
	// ll maxi=32;
	// ll flag;
	// for(ll i=0;i<n;i++) {
		// flag=1;
		// for(ll bit=0;bit<=maxi;bit++){
			// if(nums[i] & (1<<bit)){ //for some set bit in number
				// if(mp[bit]==1){
					// flag=0;
// 					
				// }
			// }
// 			
// 			
		// } if(flag==1){
			// cout<<"Yes"<<endl;
			// return;
		// }	
// 		
// 		
	// }
	// cout<<"No"<<endl;
// 	
// 	
// 	
// 	
// // 	
	// // debug(nums)
// }



// void solve()
// {
     // ll n;
     // cin>>n;
//      
     // unordered_map<ll,ll> mp;
//  
     // // vector<vector<int>> vv(count);
     // vector<int> arrel;
      // int num;
      // while(n--){
      	// ll x;
      	// cin>>x;
      	  // // vector<int> curV;
      	 // num=0;
      	// while(x--){
                // int k;
                // cin>>k;
               // num+=(1<<k);     		
      		  // mp[k]++;
      	// }
      	// // vv.push_back(curV);
      	// arrel.push_back(num);
      // }
//       
      // bool flag=1;
      // for(int i=0;i<arrel.size();i++){
//       	
      	// for(int j=0;j<=32;j++){
      		// if(arrel[i] & (1<<j)) {
      			// if(mp[j]==1)
      			// flag=0;
      		// }
      		// if(!flag) break;
      	// }
      	// if(!flag) break;
//       	
//       	
      // }
//       
      // if(flag){
      	// cout<<"Yes"<<endl;
      // }
      // else cout<<"No"<<endl;
//       
      // // fr(i,0,arrel.size()){
      	// // cout<<arrel[i]<<" ";
      // // }cout<<endl;
      // // debug(mp)
//       
      // // debug(vv)
      // // bool flag=1;
      // // for(int i=0;i<count;i++){
      	// // int k=0;
      	 // // for(auto j:vv[i]){
      	 	// // for(int k=0;k<=32;k++){
      	 		// // if(j & (1<<k) and mp[j]<2){
      	 			// // int flag=0;    	 		 
      	 		// // }
// //       	 		
      	 		// // if(!flag) break;
      	 	// // }if(!flag) break;
      	 // // }if(!flag) break;
      // // }
// //       
      // // if(flag)
      // // cout<<"Yes"<<endl;
      // // else
// //       
      // // // for(const auto &pair:mp){
      	// // // if(pair.second==count){
      		// // // cout<<"Yes"<<endl;
      		// // // return;
      	// // // }
      // // // }
      // // cout<<"No"<<endl;
// }


int main()  
{
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL); cout.tie(NULL); // flushes cout  
    
    //start writing below
    int t;
    cin>>t;
    while(t--)
    {
       solve(); 
    }
    
    // solve();
 
    return 0;  
}