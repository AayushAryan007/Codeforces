#include <bits/stdc++.h> 
using namespace std;  
#define endl "\n"
#define lo long long
#define dob long double
#define ll long long int
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
// 
// struct Edge {
    // int to;
    // int capacity;
    // int flow;
    // int rev; // Index of the reverse edge in the adjacency list
// };
// 
// // Class to represent a graph
// class Graph {
// public:
    // int num_nodes;
    // vector<vector<Edge>> adj_list;
// 
    // Graph(int num_nodes) : num_nodes(num_nodes), adj_list(num_nodes) {}
// 
    // void add_edge(int from, int to, int capacity) {
        // Edge edge = {to, capacity, 0, static_cast<int>(adj_list[to].size())};
        // Edge rev_edge = {from, 0, 0, static_cast<int>(adj_list[from].size())};
        // adj_list[from].push_back(edge);
        // adj_list[to].push_back(rev_edge);
    // }
// };
// 
// // Function to find the minimum cut using Ford-Fulkerson algorithm
// int min_cut(Graph& graph, int source, int sink) {
    // int max_flow = 0;
// 
    // while (true) {
        // vector<int> parent(graph.num_nodes, -1);
        // parent[source] = source;
        // queue<int> q;
        // q.push(source);
// 
        // while (!q.empty() && parent[sink] == -1) {
            // int current = q.front();
            // q.pop();
// 
            // for (Edge& edge : graph.adj_list[current]) {
                // if (parent[edge.to] == -1 && edge.capacity > edge.flow) {
                    // parent[edge.to] = current;
                    // q.push(edge.to);
                // }
            // }
        // }
// 
        // if (parent[sink] == -1) {
            // break; // No augmenting path found
        // }
// 
        // int min_flow_on_path = numeric_limits<int>::max();
        // for (int v = sink; v != source; v = parent[v]) {
            // Edge& edge = graph.adj_list[parent[v]][v];
            // min_flow_on_path = min(min_flow_on_path, edge.capacity - edge.flow);
        // }
// 
        // for (int v = sink; v != source; v = parent[v]) {
            // Edge& edge = graph.adj_list[parent[v]][v];
            // edge.flow += min_flow_on_path;
            // graph.adj_list[v][edge.rev].flow -= min_flow_on_path;
        // }
// 
        // max_flow += min_flow_on_path;
    // }
// 
    // return max_flow;
// }
// 
// int min_moves_min_cut(const vector<string>& tables) {
    // int num_tables = tables.size();
// 
    // // Create the graph
    // Graph graph(num_tables + 4);  // Additional nodes for source, sink, "phở tái", and "phở chín"
    // int source = num_tables;
    // int sink = num_tables + 1;
    // int pho_tai = num_tables + 2;
    // int pho_chin = num_tables + 3;
// 
    // for (int i = 0; i < num_tables; ++i) {
        // int zeros = count(tables[i].begin(), tables[i].end(), '0');
        // int ones = count(tables[i].begin(), tables[i].end(), '1');
        // graph.add_edge(source, i, min(zeros, ones));
        // graph.add_edge(i, pho_tai, zeros);
        // graph.add_edge(i, pho_chin, ones);
    // }
// 
    // graph.add_edge(pho_tai, sink, numeric_limits<int>::max());
    // graph.add_edge(pho_chin, sink, numeric_limits<int>::max());
// 
    // int min_cut_result = min_cut(graph, source, sink);
    // return min_cut_result;
// }
// 
// int main() {
    // // // Sample input
    // // std::vector<std::string> tables = {
        // // "11101101",
        // // "00",
        // // "10001",
        // // "10",
    // // };
  // int t;  
  // cin>>t;
  // while(t--){
  	 // int n;
// 
    // std::cin >> n;
// 
    // // Input the table strings
    // std::vector<std::string> tables;
    // for (int i = 0; i < n; ++i) {
        // std::string table;
       // // std::cout << "Enter table " << i + 1 << " string: ";
      // cin >> table;
        // tables.push_back(table);
    // }
// 
    // // Calculate and print the minimum number of moves
 // cout <<  min_moves_min_cut(tables) << endl;
// 
  // }
    // // Calculate and print the minimum number of moves
//   
// 
    // return 0;
// }
int main() {
	int t;
	cin>>t;
	while(t--){
		 int n;
    cin >> n;

    vector<vector<int>> counts(n, vector<int>(2, 0));

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        for (char c : s) {
            counts[i][c - '0']++;
        }
    }

    int total = 0;

    for (int i = 0; i < n; ++i) {
        total += min(counts[i][0], counts[i][1]);
    }

    cout << total << endl;
	
   }

    return 0;
}