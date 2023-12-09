// Problem: Palindromic Prime Numbers
// Contest: CodeChef - START108C
// URL: https://www.codechef.com/START108C/problems/MD_RIEV
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

#define vi vector<int>
#define vpp vector<pair<int,int>>
#define vs vector<string>
#define vll vector<long long>
#define in(v)  for(auto &item : v) cin>>item;
#define inp(v)  for(auto &item : v) cin>>item.ff>>item.ss;

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

bool isprime(long long int n)  //to check prime
{
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)return false;
    }
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
// bool isPrime(int n) {
    // if (n <= 1) return false;
    // if (n <= 3) return true;
// 
    // if (n % 2 == 0 || n % 3 == 0) return false;
// 
    // for (int i = 5; i * i <= n; i += 6) {
        // if (n % i == 0 || n % (i + 2) == 0) return false;
    // }
// 
    // return true;
// }
// 
// int reverse(int n) {
    // int rev = 0;
    // while (n > 0) {
        // rev = rev * 10 + n % 10;
        // n /= 10;
    // }
    // return rev;
// }
// 
// std::vector<int> generatePalindromicPrimes(int n) {
    // std::vector<int> palindromicPrimes;
    // int count = 0;
    // int num = 2; // Start from the first prime number
// 
    // while (count < n) {
        // if (num == reverse(num) && isPrime(num)) {
            // palindromicPrimes.push_back(num);
            // count++;
        // }
        // num++;
    // }
// 
    // return palindromicPrimes;
// }
// 
// void countOddEvenDigits(const std::vector<int>& palindromicPrimes) {
    // int oddDigits = 0, evenDigits = 0;
// 
    // for (int prime : palindromicPrimes) {
        // int digits = 0;
        // int num = prime;
// 
        // while (num > 0) {
            // digits++;
            // num /= 10;
        // }
// 
        // if (digits % 2 == 0)
            // evenDigits++;
        // else
            // oddDigits++;
    // }
// 
   // cout << evenDigits <<" "<< oddDigits <<endl;
// }
void solve()
{
	
	int n;
	cin>>n;
	if (n <= 4)
 {
	cout << 0 <<" "<<n << endl;
                       return;
  }

               cout<<1 <<" "<<n - 1 <<"\n";
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