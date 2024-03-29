// Problem: B. Planet Lapituletti
// Contest: Codeforces - Codeforces Round 705 (Div. 2)
// URL: https://codeforces.com/contest/1493/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
// 
// void solve()
// {
     // string hh,mm;
     // cin>>hh>>mm ;
     // string limit= hh+mm;
//      
//      
     // string curtime;
     // cin>>curtime;
     // string check="";
//      
     // // string orig="01258";
     // // string refl="01528";
     // // vector<char> orig{"0", "1", "2","5", "8"};
     // // vector<char> refl{"0", "1", "5","2", "8"};
//      
     // int carry=0;
     // for(int i=4;i>=0;i--){
     	// if(curtime[i]==':'){
//      		
     		// check+=curtime[i];
//      		
     	// }
     	// else{
     		// if(carry==1 ||(curtime[i]=='3'||curtime[i]=='4'||curtime[i]=='6'||curtime[i]=='7'||curtime[i]=='9')){
     			// if(curtime[i]=='0'){
     				// check[i]='1';
     			// }
     			// else if(curtime[i]=='0'){
     				// check[i]='1';
     			// }
     		// }
//      		
     	// }
     // }
// }
// 
// 
// signed main() {
   // int T;
    // cin >> T;
// 
    // // Valid reflections for numbers 0, 1, 2, 5, 8
    // vector<char> valid_reflections = {'0', '1', '5', '2', '8'};
// 
    // for (int t = 0; t < T; ++t) {
        // int h, m;
        // cin >> h >> m;
//         
        // string start_time;
        // cin >> start_time;
//         
        // // Extract hours and minutes from the start time
        // int hours = stoi(start_time.substr(0, 2));
        // int minutes = stoi(start_time.substr(3));
// 
        // // Iterate over minutes and hours to construct reflected time
        // while (true) {
            // string reflected_minutes = to_string(minutes);
            // string reflected_hours = to_string(hours);
// 
            // // Add leading zeros if necessary
            // if (reflected_minutes.size() == 1) {
                // reflected_minutes = "0" + reflected_minutes;
            // }
            // if (reflected_hours.size() == 1) {
                // reflected_hours = "0" + reflected_hours;
            // }
// 
            // // Check if the reflected time is valid
            // if (find(valid_reflections.begin(), valid_reflections.end(), reflected_minutes[0]) != valid_reflections.end() &&
                // find(valid_reflections.begin(), valid_reflections.end(), reflected_minutes[1]) != valid_reflections.end() &&
                // find(valid_reflections.begin(), valid_reflections.end(), reflected_hours[0]) != valid_reflections.end() &&
                // find(valid_reflections.begin(), valid_reflections.end(), reflected_hours[1]) != valid_reflections.end()) {
//                 
                // // Check if the reflected time is within bounds
                // if (hours < h && minutes < m) {
                    // cout << reflected_hours << ":" << reflected_minutes << endl;
                // } else {
                    // cout << "00:00" << endl;
                // }
                // break;
            // }
// 
            // // Increment minutes and hours
            // minutes++;
            // if (minutes == m) {
                // minutes = 0;
                // hours++;
                // if (hours == h) {
                    // hours = 0;
                // }
            // }
        // }
    // }
// 
    // return 0;
// }

signed main(){
	int t;
	cin>>t;
	while(t--){
		int h,m;
		cin>>h>>m;
		string s;
		cin>>s;
		
		vector<int> v(10);
		v[0]=0,
		v[1]=1,
		v[2]=5,
		v[3]=-1,
		v[4]=-1,
		v[5]=2,
		v[6]=-1,
		v[7]=-1,
		v[8]=8,
		v[9]=-1;
		
		vector<pair<int,int>> vv;
		int hh=10*(s[0]-'0')+(s[1]-'0');
		int mm=10*(s[3]-'0')+(s[4]-'0');
		
		for(int i=hh;i<h;i++){
			for(int j=0;j<m;j++){
				int q,w,e,r;
				q=i/10;
				w=i%10;
				e=j/10;
				r=j%10;
				
				if(v[q]==-1 || v[w]==-1 || v[e]==-1 || v[r]==-1){
					continue;
				}
				
				q=v[q];
				w=v[w];
				e=v[e];
				r=v[r];
				
				int newh=(10*r)+e;
				int newm=(10*w)+q;
				
				if(newh<h and newm<m and ((i>hh )|(i==hh and j>=mm))){
					vv.push_back({i,j});
					break;
				}
			}
		}
		
		if(vv.size()==0){
			cout<<"00:00"<<endl;
			continue;
		}
		else{
			cout<<vv[0].first/10<<vv[0].first%10<<":"<<vv[0].second/10<<vv[0].second%10<<endl;
		}
		
	}
}