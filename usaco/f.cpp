/*
ID: zilvaru1
PROG: crypt1 
LANG: C++
*/

#include <streambuf>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <fstream>
 
using namespace std;

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#define oo 0x3F3F3F3F
#ifdef DEBUG
#define cvar(x) cerr << "<" << #x << ": " << x << ">"
#define evar(x) cvar (x) << endl
template<class T> void DISP (const char *s, T x, int n) {cerr << "[" << s << ": "; for (int i = 0; i < n; ++i) cerr << x[i] << " "; cerr << "]" << endl;}
#define disp(x,n) DISP (#x " to " #n, x, n)
#else
#define cvar(...) ({})
#define evar(...) ({})
#define disp(...) ({})
#endif
#ifdef WIN32
#define fmt64 "%I64d"
#else
#define fmt64 "%lld"
#endif
#define MKP make_pair
#define Px first
#define Py second
#define PB push_back
#define LEN length()
#define SIZE size()
#define sz_m(x) (int)((x).size ())
#define iter(x) (x).begin (), (x).end ()

typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef set<int> SI;
typedef set<string> SS;
typedef pair<int, int> PII;
typedef pair<string, int> PSI;

template<class T> inline bool chkmin (T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline bool chkmax (T &a, T b) {return a < b ? a = b, true : false;}
template<class T> inline T sqr (T x) {return x * x;}

template<class edge> struct Graph
{
  vector<vector<edge> > adj;
  Graph (int n) {adj.clear (); adj.resize (n + 5);}
  Graph () {adj.clear (); }
  void resize (int n) {adj.resize (n + 5); }
  void add (int s, edge e){adj[s].push_back (e);}
  void del (int s, edge e) {adj[s].erase (find (iter (adj[s]), e)); }
  int deg (int v) {return adj[v].size (); }
  vector<edge>& operator [](int t) {return adj[t];}
};

struct Base {

	string num; 
	int numVal[300];

	Base() {
		num = "";
		for (char i = '0'; i <= '9'; i++) {
			num += i;
		}
		for (char i = 'A'; i <= 'Z'; i++) {
			num += i;
		}
	  	for(int i = 0; i <= 20; i++) {
			 numVal[num[i]] = i;
	  	}
	
	}

	string intToStr(int number) {
		string str = "";
		int rem;
		while(number > 0) {
			rem = number%10;
			number/=10;
			str.insert(str.begin(), num[rem]);
		}
		return str;
	}
	
	int con10(string num, int fromBase) {
		
	
		int an = 0;
		int len = num.LEN;
			for (int i = 0; i < len; i++) {
				an += (numVal[num[i]]);
				if (i + 1 != len) {
					an *= fromBase;
				}
			}
		return an;
	
	}

};


const int MAXN = 10 + 100;

void read() { 
  ifstream input("crypt1.in");
  input.close();
}
int main () {
  ios_base::sync_with_stdio (false);
  read();
  ofstream out("crypt1.out");
  out.close();
  return 0;
}
  

//read all file
//void read() {
  //ifstream in("calfflac.in");
  //string init((istreambuf_iterator<char>(in)),
                  //istreambuf_iterator<char>());
  //cout << init << endl;
  //in.close();
//}
