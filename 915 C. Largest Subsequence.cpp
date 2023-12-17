// Problem: C. Largest Subsequence
// Contest: Codeforces - Codeforces Round 915 (Div. 2)
// URL: https://codeforces.com/contest/1905/problem/C
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
void solve(){
 ll n; 
        string str;
        cin >> n;  
        cin >> str;
        vector<ll> lex_idx;
        
        for (ll i = 0; i < n; i++) {
            while (!lex_idx.empty() && (str[i] > str[lex_idx.back()])) lex_idx.pop_back();
            lex_idx.push_back(i);
        }
 
        ll lex_size = lex_idx.size();
        ll first = str[lex_idx[0]];
        ll dup =  0;
        for(ll i = 0 ; i < lex_size ; i++) {
            if(str[lex_idx[i]] == first)
                dup++;
        }
        for (ll i = 0; i < lex_size/2; i++) 
            swap(str[lex_idx[i]], str[lex_idx[lex_size - 1 - i]]);
            
        if(is_sorted(str.begin(), str.end()))
            cout<<lex_size-dup<<endl;
        else
            cout<<-1<<endl;
}


// void solve() {
    // ll n;
    // cin >> n;
    // string s;
    // cin >> s;
// 
    // stack<char> sc;
// 
    // for (int i = 0; i < n; i++) {
        // if (sc.empty()) {
            // sc.push(s[i]);
        // } else {
            // while (!sc.empty() && s[i] > sc.top()) {
                // sc.pop();
            // }
            // sc.push(s[i]);
        // }
    // }//till here stack gives us the lexo largest subseq
 // if(sc.size()==n)
 // cout<<-1<<endl;
 // else
    // cout << sc.size()-1 << endl;
//   
// }

//pretest failed
// void solve()
// {
   // ll n;
   // cin>>n;
   // string s;
   // cin>>s;
   // ll count =0; 
//    
   // fr(i,1,n){
   	// if(s[i]<s[i-1]){
   		// count++;
   	// }
   // }
   // ll flag=count;
   // fr(i,1,n-1){
   	// if(s[i]<s[i-1] and s[i]<s[i+1] and n<=3){
   		// flag=-1;
   		// break;
   	// }
   // }
  // cout<<flag<<endl;
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
 
    return 0;  
}