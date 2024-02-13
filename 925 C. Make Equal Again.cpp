// Problem: C. Make Equal Again
// Contest: Codeforces - Codeforces Round 925 (Div. 3)
// URL: https://codeforces.com/contest/1931/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h> 
using namespace std;  
#define endl "\n"
#define lo long long
#define dob long double

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
// int minBurles(std::vector<int>& arr) {
    // int n = arr.size();
//     
    // int countFront = 1, countBack = 1;
// 
    // // Count the number of repeated elements on the front
    // for (int i = 1; i < n; ++i) {
        // if (arr[i] == arr[0]) {
            // countFront++;
        // } else {
            // break;
        // }
    // }
// 
    // // Count the number of repeated elements on the back
    // for (int i = n - 2; i >= 0; --i) {
        // if (arr[i] == arr[n - 1]) {
            // countBack++;
        // } else {
            // break;
        // }
    // }
// int flag=0;
    // int i = 0, j = n - 1;
    // if (arr[0] == arr[n - 1]) {
    	// flag=1;
        // while (arr[i] == arr[j]) {
            // i++;
            // if (arr[i] != arr[j] || i > j) {
                // i--;
                // break;
            // }
        // }
        // while (arr[i] == arr[j]) {
            // j--;
            // if (arr[i] != arr[j] || i > j) {
                // j++;
                // break;
            // }
        // }
    // }
// 
    // int h = j - i ;
//     
//  
// 
    // // Return the minimum of the lengths of these runs
    // int ans = std::min(n - countFront-1, n - countBack);
//     
    // // ans = std::min(ans, h);
//     
    // return ans;
// }
// 
typedef long long ll;
void solve() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n];
        unordered_map<ll, ll> freq;
        
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            freq[a[i]]++;
        }

        if (n == 1) {
            cout << 0<<endl;
            
            
            continue;
        }

        ll cnt = 1, cnt1 = 1;

        // Count consecutive elements from the start
        for (int i = 1; i < n; i++)
            if (a[0] == a[i])
            
            
                cnt++;
            else
                break;

        // Count consecutive elements from the end
        for (int i = n - 2;   i >= 0; i--)
        
        
            if (a[n - 1] == a[i])
                cnt1++;
                
            else
            
                break;
                

        if (a[0] == a[n - 1])
        
            cout << max( n - cnt1 - cnt,ll(0)) <<endl;
        else
        
        
            cout << n - max(cnt, cnt1) << endl;
    }
}

int main() {
    solve();
    return 0;
    
    
    void solve(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll a[n], cnt = 1, cnt1 = 1;
        for(auto &i: a) cin >> i;
        if(n == 1){
            cout << "0\n";
            continue;
        }
        for (int i = 1; i < n; i++)
            if(a[0] == a[i]) cnt++;
            else break;
        for (int i = n-2; i >= 0; i--)
            if(a[n -1] == a[i]) cnt1++;
            else break;
        if(a[0] == a[n-1])cout << max(ll(0), n - cnt - cnt1) << '\n';
        else cout << n - max(cnt, cnt1) << '\n';
    }
}

int main(){
    fast
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    solve();
}
}