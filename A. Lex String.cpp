// Problem: A. Lex String
// Contest: Codeforces - Codeforces Round 798 (Div. 2)
// URL: https://codeforces.com/contest/1689/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h> 
using namespace std;  
#define endl "\n"
#define lo long long
#define dob long double
//#define ll long long int
#define int long long 
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

void solve()
{
  int n,m,k;
  cin>>n>>m>>k;
  
  string s1,s2;
  cin>>s1>>s2;

  string ans="";
   sort(all(s1));
   sort(all(s2)); 
   
   int i=0,j=0;
   int flag;
   if(s1[i]<s2[j]) flag=1;
   else flag=2;
   
   
   while(i<n and j<m){
   	 if(flag==1){
   	 	int temp=k;
   	 	ans+=s1[i];i++;
   	 	temp--;
   	 	while(temp and s1[i]<=s2[j] and i<n){
   	 		temp--;
   	 		ans+=s1[i];
   	 		i++;
   	 	}
   	 	flag=2;
   	 }
   	 else if(flag==2){
   	 	int temp=k;
   	 	ans+=s2[j];j++;
   	 	temp--;
   	 	while(temp and s1[i]>=s2[j] and j<m){
   	 		temp--;
   	 		ans+=s2[j];
   	 		j++;
   	 	}
   	 	flag=1;
   	 }
   }
   
   cout<<ans<<endl;
   // int flag;
   // if(s1[0]<s2[0]) flag=1;
   // else flag=2;
   // while(i<n and j<n ){
//    	
   	// if(flag==1){
   		// int temp=k;
   		// while(temp--){
   			// ans+=s1[i];
   			// i++;
   		// }
   		// flag=2;
   	// }
   	// else if(flag=2){
   		// int temp=k;
   		// while(temp--){
   			// ans+=s2[j];
   			// j++;
//    			
   		// }
   		// flag=1;
   	// }
//    	
//    	
   // }
//    
   // cout<<ans<<endl;
}


signed main()  
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