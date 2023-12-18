// Problem: A. Rating Increase
// Contest: Codeforces - Educational Codeforces Round 160 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1913/problem/0
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
std::pair<int, int> findValues(const std::string& str) {
    int len = str.length();
    std::pair<int, int> result = {-1, -1}; // Initialize with default values

    for (int i = 1; i < len; ++i) {
        std::string firstPart = str.substr(0, i);
        std::string secondPart = str.substr(i);

        // Check for valid parts (without leading zeros)
        if ((firstPart[0] != '0' || firstPart.length() == 1) && 
            (secondPart[0] != '0' || secondPart.length() == 1)) {
            int a = std::stoi(firstPart);
            int b = std::stoi(secondPart);

            if (b > a) {
                result = std::make_pair(a, b);
            }
        }
    }
    return result;
}

void solve() {
    std::string s;
    std::cin >> s;
    std::pair<int, int> result = findValues(s);

    if (result.first == -1 && result.second == -1) {
        std::cout << "-1" << endl;
    } else {
        std::cout << result.first << " " << result.second << endl;
    }
}



// std::pair<std::string, std::string> findNonZeroParts(const std::string& str) {
    // std::string s1 = "", s2 = "";
    // int j = 0, n = str.size();
// 
    // while (str[j] == '0') {
        // j++;
    // }
// 
    // int i = j + 1;
// 
    // while (i < n && str[i] == '0') {
        // i++;
    // }
// 
    // while (j < i) {
        // s1 += str[j++];
    // }
// 
    // while (i < n) {
        // s2 += str[i++];
    // }
// 
    // if (s1 == s2) {
        // return std::make_pair("-1", "-1");
    // }
// 
    // return std::make_pair(s1, s2);
// }
// 
// void solve() {
    // std::string s;
    // std::cin >> s;
// 
    // std::pair<string, string> result = findNonZeroParts(s);
// 
    // std::cout << result.first << " " << result.second << endl;
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