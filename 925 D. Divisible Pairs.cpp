// Problem: D. Divisible Pairs
// Contest: Codeforces - Codeforces Round 925 (Div. 3)
// URL: https://codeforces.com/contest/1931/problem/D
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
// 



int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,x,y;
		cin>>n>>x>>y;
		
		ll ans=0;
		
		vll a(n);
		
		for(auto &i:a) cin>>i;
		
		map<pair<ll,ll>,ll>m;
		
		for(auto &i:a){
			ll xm=(x-(i%x))%x;
			ll ym=i%y;
			ans+=m[{xm,ym}];
			m[{i%x,i%y}]++;
		}
		cout<<ans<<endl;
	}
}












// int main() {
    // int t;
    // std::cin >> t;
// nt n, x, y;
        // cin >> n >> x >> y;
        // int arr[n];
// 
        // for (int i = 0; i < n; i++) {
            // cin >> arr[i];
        // }
// 
        // map<pair<int, int>, int> mp;
        // int ans = 0;
// 
        // for (int i = 0; i < n; i++) {
            // int p = arr[i] % x;
            // int q = arr[i] % y;
            // ans += mp[{x - p, q}];
//             
            // if (p == 0) {
                // p = x;
            // }
// 
            // mp[{p, q}]++;
        // }
// 
        // cout << ans << endl; 
    // while (t--) {
    	   // long long n, x, y;
        // cin >> n ;
           // vector<long long> v(n);
           // cin>>x>>y;
//         
//         
//      
// 
        // for (long long   i = 0; i < n; i++) {
//         	
            // cin >> v[i];
        // }
// 
        // map<pair<long long, long long>,  long long> l;
        // long long ans = 0;
// long long p ;
        // for (long long i = 0; i < n; i++) {   long long q = v[i] % y;
//             
//             
        // p=     v[i] % x;
//          
//          
//          
            // ans += l[{x - p, q}];
// 
            // if (p == 0) {
                // p = x;
            // }
// 
// 
            // l[{p, q}]++;
        // }
// 
        // cout << ans << endl;
        // // int n, x, y;
        // // std::cin >> n >> x >> y;
// // 
        // // std::vector<int> a(n);
        // // for (int i = 0; i < n; ++i) {
            // // std::cin >> a[i];
        // // }
// // 
        // // int beautifulPairs = 0;
// // 
        // // for (int i = 0; i < n; ++i) {
            // // for (int j = i + 1; j < n; ++j) {
                // // if ((a[i] + a[j]) % x == 0 && (a[i] - a[j]) % y == 0) {
                    // // beautifulPairs++;
                // // }
            // // }
        // // }
// // 
        // // std::cout << beautifulPairs <<endl;
    // }
// 
    // return 0;
// }


