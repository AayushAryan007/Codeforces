// Problem: C1. Potions (Easy Version)
// Contest: Codeforces - Codeforces Round 723 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1526/C1
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

////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
// 
// int maxItemsToKeepNonNegativeSum(vector<int>& numbers) {
    // int totalItems = numbers.size();
//     
    // // Create a copy of the vector and sort it in ascending order
    // std::vector<int> sortedNumbers = numbers;
    // std::sort(sortedNumbers.begin(), sortedNumbers.end());
//     
    // // Initialize variables
    // int currentSum = 0;
    // int maxItemsToKeep = 0;
//     
    // // Iterate through the sorted numbers
    // for (int num : sortedNumbers) {
        // currentSum += num;
        // maxItemsToKeep++;
//         
        // // If the current sum becomes negative, stop and return the count
        // if (currentSum < 0) {
            // return maxItemsToKeep - 1;
        // }
    // }
//     
    // // If the loop completes, all items can be included to keep the sum non-negative
    // return totalItems;
// }
void solve()
{
    ll n;
    cin>>n;
    
    vector<ll> v(n);
    
    fr(i,0,n){
    	cin>>v[i];
    } 
    
    // cout<<maxItemsToKeepNonNegativeSum(v);
    ll sum=0;
    // int mini=INT_MAX;
    ll ans=0;
    
    // fr(i,0,n){
    	// mini=min(mini,v[i]);
    	// sum+=v[i];
    	// ans++;
//     	
    	// if(sum<0){
    		// sum-=mini;
    		// ans--;
    	// }
    // }// do this using min heap;
//     

    priority_queue<ll,vector<ll>,greater<ll>> pp;
    fr(i,0,n){
    	pp.push(v[i]);
    	sum+=v[i];
    	ans++;
    	if(sum<0){
    		ll x=pp.top();
    		pp.pop();
    		sum-=x;
    		ans--;
    	}
    }
    cout<<ans<<endl;
}


int main()  
{
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL); cout.tie(NULL); // flushes cout  
    
   
       solve(); 
    
    
    // solve();
 
    return 0;  
}