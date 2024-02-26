// Problem: E. Binary Deque
// Contest: Codeforces - Codeforces Round 799 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1692/E
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

// void solve()
// {
    // ll n, need, cur = 0;
    // cin >> n >> need;
// 
    // vll v(n);
    // for (ll i = 0; i < n; i++)
    // {
        // cin >> v[i];
        // cur += v[i];
    // }
// 
    // if (cur < need)
    // {
        // cout << -1 << endl;
    // }
    // else if (cur == need)
    // {
        // cout << 0 << endl;
    // }
    // else
    // {
        // ll i = 0, j = n - 1;
        // ll count = 0;
// 
        // while (i <= j && cur > need)
        // {
            // if (v[i] == 1)
            // {
                // count++;
                // cur--;
                // i++;
            // }
            // else if (v[j] == 1)
            // {
//             	
                // count++;
                // cur--;
                // j--;
            // }
            // else if (v[i] == 0 || v[j] == 0)
            // {
//             	
                // ll counti =0 ;
                // ll countj =0;
                  // if(v[i]==0) counti=1;
                 // if(v[j]==0 ) countj=1;
//                  
                // while (i < j && v[i] == 0)
                // {
                    // counti++;
                    // i++;
                // }
                // while (i < j && v[j] == 0)
                // {
                    // countj++;
                    // j--;
                // }
                // while(i<j and v[i]==1 and cur>need){
                	// count++;
                	// i++;
                	// cur--;
                // }
                // while(i<j and v[j]==1 and cur>need){
                	// count++;
                	// j--;
                	// cur--;
                // }
                      // // both are on ones
                // if (counti <= countj)
                // {
                    // count += counti;
                    // i++;
//                     
                    // cur--;
                // }
                // else
                // {
                    // count += countj;
                    // j--; 
//                    
                    // cur--;
                // }
            // }
        // }
// 
        // cout << count << endl;
    // }
// }

ll getLongestSubarray(vector<ll>& a, long long k) {
    ll n = a.size(); // size of the array.

    ll left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    ll maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}
void solve(){
	ll n, need,cur=0;
	cin>>n>>need;
	vector<ll> v(n);
	
	
	for(ll i=0;i<n;i++){
		cin>>v[i];
		cur+=v[i];
	}
	if (cur < need)
    {
        cout << -1 << endl;
        return;
    }
    else if (cur == need)
    {
        cout << 0 << endl;
        return;
    }
	cout<<n-getLongestSubarray(v,need)<<endl;
}


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