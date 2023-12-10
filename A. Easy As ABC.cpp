// Problem: A. Easy As ABC
// Contest: Codeforces - 2023-2024 ICPC, Asia Jakarta Regional Contest (Online Mirror, Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/1906/A
// Memory Limit: 1024 MB
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


bool isValid(int r, int c) {
    return (r >= 0 && r < 3 && c >= 0 && c < 3);
}

// Find the lexicographically smallest word
string findSmallestWord(vector<vector<char>>& grid) {
    string smallest = "ZZZ"; // Initialize with a maximum string

    for (int r1 = 0; r1 < 3; ++r1) {
        for (int c1 = 0; c1 < 3; ++c1) {
            for (int r2 = 0; r2 < 3; ++r2) {
                for (int c2 = 0; c2 < 3; ++c2) {
                    for (int r3 = 0; r3 < 3; ++r3) {
                        for (int c3 = 0; c3 < 3; ++c3) {
                            if (!(r1 == r2 && c1 == c2) &&
                                !(r1 == r3 && c1 == c3) &&
                                !(r2 == r3 && c2 == c3)) {
                                
                                // Check adjacency
                                if (isValid(r1, c1) && isValid(r2, c2) && isValid(r3, c3) &&
                                    (abs(r1 - r2) <= 1) && (abs(r2 - r3) <= 1) && (abs(c1 - c2) <= 1) && (abs(c2 - c3) <= 1)) {
                                    
                                    string current = "";
                                    current += grid[r1][c1];
                                    current += grid[r2][c2];
                                    current += grid[r3][c3];

                                    if (current < smallest) {
                                        smallest = current;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return smallest;
}

int main() {
    vector<vector<char>> grid(3, vector<char>(3));

    // Input grid
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> grid[i][j];
        }
    }

    string smallestWord = findSmallestWord(grid);
    cout << smallestWord << endl;

    return 0;
}