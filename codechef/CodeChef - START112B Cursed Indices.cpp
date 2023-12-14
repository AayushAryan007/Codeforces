// Problem: Cursed Indices
// Contest: CodeChef - START112B
// URL: https://www.codechef.com/START112B/problems/CURSED
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
#define mod 1e9+7
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

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

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

////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

// void solve()
// {
  // int n;
  // cin>> n;
  // vi v(n);
  // int count=1;
  // int cursum=0;
  // cin>>v[0];
  // cursum=v[0];
  // fr(i,1,n){
  	// cin>>v[i];
  	// if(v[i]<=cursum){
  		// count++;
  		// }cursum+=v[i];
//   		
  // }  
  // sort(all(v));
  // cout<<count<<endl;
  // fr(i,0,n){
  	// cout<<v[i]<<" ";
//   	
  // }cout<<endl;
//   	
// }
// 
// void solve(){
	// int n;
	// cin>>n;
	// vi v(n);
	// fr(i,0,n) cin>>v[i];
// 	
	// sort(all(v));
	// int count=0;
	// int cursum=v[0];
	// fr(i,1,n){
		// if(v[i]<=cursum){
			// count++;
// 			
		// }cursum+=v[i];
	// }
// 	
	// cout<<count<<endl;
	// fr(i,0,n) cout<<v[i]<<" "; 
	// cout<<endl;
// }
// void solve(){
	   // int n;
    // cin >> n;
    // vector<int> v(n);
    // fr(i, 0, n) cin >> v[i];
//     
    // sort(all(v));
    // vector<int> a(n);
// 
    // int left = 0, right = n - 1;
    // for (int i = 0; i < n; ++i) {
        // if (i % 2 == 0) {
            // a[i] = v[left++];
        // } else {
            // a[i] = v[right--];
        // }
    // }
// 
    // int cursum = a[0];
    // int count = 1; // Initialize count to 1 for the first element
    // fr(i, 1, n) {
        // if (a[i] <= cursum) {
            // count++;
        // }
        // cursum += a[i];
    // }
//     
    // cout << count << endl;
    // fr(i, 0, n) cout << a[i] << " ";
    // cout << endl;
// 
// }
// void solve(){
  // int n;
        // cin >> n;
          // ll sum = 0;
       // vi v(n),a(n,0);
        // fr(i,0,n) cin>>v[i];
        // sort(all(v));
       // int count = 0;
// 
        // int m = n / 2;
// 
        // for (int i = 0; i < n; i += 2) {
            // a[i] = v[m++];
        // }
// 
        // m = 0;
        // for (int i = 1; i < n; i += 2) {
            // a[i] = v[m++];
        // }
// 
        // fr(i,0,n) {
          // sum += a[i];
            // if (sum < a[i]*i + 1) {
                // count++;
            // }
        // }
// 
        // cout << count << endl;
        // fr(i,0,n) {
            // cout <<a[i]<< " ";
        // } cout<<endl;
// }
void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	multiset<int> st;
	
	fr(i,0,n){
		cin>>a[i];
		st.insert(a[i]);
	}
	ll sum=0;
	vector<int> ans;
	while(!st.empty()){
		auto it=st.upper_bound(sum);
		if(it==st.end()) break;
		sum+=*it;
		ans.pb(*it);
		st.erase(it);
	}
	
	cout<<st.size()<<endl;
	
	for(auto it:ans){
		cout<<it<<" ";
		
	}
	for(auto it:st){
		cout<<it<<" ";
	}
	cout<<endl;
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
 
    return 0;  
}