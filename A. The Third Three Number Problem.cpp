// Problem: A. The Third Three Number Problem
// Contest: Codeforces - Codeforces Round 804 (Div. 2)
// URL: https://codeforces.com/contest/1699/problem/A
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
//#define int long long 
#define mod 1000000007
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fr(i, x, n) for (int i = x; i < n; i++)
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
// int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
// int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
// int lowpowerof2(int n) { return 1LL << (int)log2(n); }
// int highpowerof2(int n) { return 1LL << (int)ceil(log2(n)); }
// bool ispowerof2(int n) { return (n != 0) && ((n & (n - 1)) == 0); }
// 
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
bool isprime(int n)  //to check prime
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

int sumvec(vector<int> & v){
	int sum=0;
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

// void solve()
// {
   // ll n;
    // cin>>n;
//     
    // if(n%2==1){
    	// cout<<-1<<endl;
    	// return;
    // }
//     
    // ll flag=3;
     // ll a1=0,a2=0,a3=0;
    // for(ll i=1;i<=32;i++){
    	// ll cur;
    	// if(flag==1) {
    		// flag=2;
    		// cur=a2;
    	// }
    	// else if(flag==2){ flag=3;
    	// cur=a3;
    	// }
    	// else if(flag==3) {flag=1;
    	 // cur=a1;
    	// }
//     	
//     	
    	// ll mask=(1<<i);
//     	
    	// if( mask & n){
    		// if(flag==1) a1|=mask;
    	  // else if(flag==2) a2|=mask;
    	  // else if(flag==3) a3|=mask;
    	// }
//     	
//     	  
//     	
//     	  
//     	
    // }
//     
//     
    // cout<<a1<<" "<<a2<<" "<<a3<<endl;
    // // cout << (a1 ^ (a2 ^ a3)) << endl;
// }





// void solve() {
    // long long int X;
    // cin >> X;
// 
    // // Check if X is odd
    // if (X & 1) {
        // cout << "-1\n"; // No solution if X is odd
        // return;
    // }
// 
    // // Discard the last 0 (divide by 2 or shift right)
    // X >>= 1;
// 
    // // Create 3 binary numbers: start with zeroes and put each 1 bit from X to either a or b or c.
    // // It does not matter which one. Just for fun let's do it in a round-robin manner:
    // long long int a = 0, b = 0, c = 0;
    // bool roundRobin = true;
    // int bitPosition = 0;
// 
    // while (X) {
        // if (X & 1) {
            // if (roundRobin) a |= (1LL << bitPosition);
            // else if (roundRobin == false) b |= (1LL << bitPosition);
            // else c |= (1LL << bitPosition);
// 
            // roundRobin = !roundRobin;
        // }
// 
        // X >>= 1;
        // bitPosition++;
    // }
// 
    // // Check the result
 // //   cout << (a^b) + (b^c) + (c^a) << "\n";
    // cout<<a<<" "<<b<<" "<<c<<endl;
// }

void solve(){
	int n;
	cin>>n;
	
	
	if(n%2==1){
		cout<<-1<<endl;
		return;
		
	}
	
	cout<<0<<" "<<0<<" "<<n/2<<endl;
	
	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}