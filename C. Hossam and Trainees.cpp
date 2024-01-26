// Problem: C. Hossam and Trainees
// Contest: Codeforces - Codeforces Round 837 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1771/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
// bool isprime(long long int n)  //to check prime
// {
    // for(int i=2; i*i<=n; i++)
    // {
        // if(n%i==0)return false;
    // }
    // return true;
// }
//prime int
// bool isPrime(int n) 
// { 
    // // Corner cases 
    // if (n <= 1) 
        // return false; 
    // if (n <= 3) 
        // return true; 
//   
    // // This is checked so that we can skip 
    // // middle five numbers in below loop 
    // if (n % 2 == 0 || n % 3 == 0) 
        // return false; 
//   
    // for (int i = 5; i * i <= n; i = i + 6) 
        // if (n % i == 0 || n % (i + 2) == 0) 
            // return false; 
//   
    // return true; 
// } 
// 

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

// dieve prime generetor
const int N=1e6+6;
vector<int> isprime(N,1);
//let all number prime
vector<int> sprime;
void sieve(int n){
	isprime[0]=0;
	isprime[1]=0;
	
	for(int i=2;i<=n;i++){
		if(isprime[i]) //if(prime)
		{
			sprime.pb(i); //save it
			for(int j=i*i;j<=n;j+=i){
				isprime[j]=0; //all multiples not prime
			}
		}
	}
}
// now we have all prime numbers till n stored in sprime;

////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
//
// int i,j,k,n,m,t,a[100500],vis[34050];
// vector<int> p;
// 
// void solve(){
	// ios::sync_with_stdio(0);
	// for(i=2;i<=34000;i++){
		// if(!vis[i]){
			// p.push_back(i);
			// for(j=i;j<=34000;j+=i)vis[j]=1;
		// }
	// }
// 	
		// cin>>n;
		// map<int,int> mp;
		// for(i=1;i<=n;i++)cin>>a[i];
		// for(i=1;i<=n;i++){
			// k=a[i];
			// for(auto j:p){
				// if(!(a[i]%j)){
					// if(mp[j]){
						// cout<<"YES\n";return;
					// }
					// mp[j]=1;
					// while(!(k%j))k/=j;
				// }
			// }
			// if(k-1&&mp[k]){
				// cout<<"YES\n";return;
			// }mp[k]++;
		// }
		// cout<<"NO\n";
// 
// 	
// }
// void solve(){
	// int n,k;
	// cin>>n;
	// map<int,int> mp;
	// vi v(n);
	// for(int i=1;i<=n;i++) cin>>v[i];
	// for(int i=1;i<=n;i++){
		// k=v[i];
		  // for(auto j:sprime){
		  	// if(!(v[i]%j)){
		  		 // if(mp[j]){
		  		 	// cout<<"YES"<<endl; return;
// 		  		 	
		  		 // }
		  		 // mp[j]=1;
		  		 // while(!(k%j)) k/=j;
		  	// }
		  // }
		  // if(k-1 and mp[k]){
		  	// cout<<"YES"<<endl; return;
		  // }mp[k]++;
	// }
	// cout<<"NO"<<endl;
// } 
// 
// void solve() {
    // int n;
    // cin >> n;
    // vector<int> v(n);
    // for (int i = 0; i < n; i++) {
        // cin >> v[i];
        // set<int> st;
// 
        // int k = v[i];
        // for (int i = 0; i < sprime.size(); i++) {
            // if (!st.empty() and k % sprime[i] == 0) {
                // if (st.find(sprime[i]) != st.end()) {
                    // cout << "YES" << endl;
                    // return;
                // }
            // }
            // st.insert(sprime[i]);
            // while (k % sprime[i] == 0) {
                // k /= sprime[i];
            // }
        // }
        // if (k != 1 and st.find(k) != st.end()) {
            // cout << "YES" << endl;
            // return;
        // }
    // }
    // cout << "NO" << endl;
// }


// void solve()
// {
    // ll n;
    // cin>>n;
//     
    // vll v(n);
    // int count=0;
    // fr(i,0,n) {cin>>v[i]; if(v[i]%2==0) count++;}
//     
//     
    // if(count>=2){
    	// cout<<"YES"<<endl;
    	// return;
    // }
    // sort(all(v));
    // fr(i,0,n)
      // fr(j,i+1,n){
      	// if(__gcd(v[i],v[j])>=2){
      		// cout<<"YES"<<endl;
      		// return;
      	// }
      // } 
      // cout<<"NO"<<endl;
// }
// 

int i,j,k,n,m,t,a[100500],vis[34050];
vector<int> p;

int main(){
	ios::sync_with_stdio(0);
	for(i=2;i<=34000;i++){
		if(!vis[i]){
			p.push_back(i);
			for(j=i;j<=34000;j+=i)vis[j]=1;
		}
	}
	cin>>t;
	while(t--){
		cin>>n;
		map<int,int> mp;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=1;i<=n;i++){
			k=a[i];
			for(auto j:p){
				if(!(a[i]%j)){
					if(mp[j]){
						cout<<"YES\n";goto aaa;
					}
					mp[j]=1;
					while(!(k%j))k/=j;
				}
			}
			if(k-1&&mp[k]){
				cout<<"YES\n";goto aaa;
			}mp[k]++;
		}
		cout<<"NO\n";
		aaa:;
	}
}