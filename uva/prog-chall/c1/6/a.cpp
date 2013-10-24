//Interpreter
#include <tr1/unordered_map>
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
#include <string>
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
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
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

//read all file
//void read() {
  //ifstream in("calfflac.in");
  //string init((istreambuf_iterator<char>(in)),
                  //istreambuf_iterator<char>());
  //cout << init << endl;
  //in.close();
//}

const string OUT = ".out";
const string IN = ".in";

LL gcd(LL a, LL b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

LL lcm(LL a, LL b) {
	return a/gcd(a, b)*b;
}

template <typename T>
T StringToNumber (const string &Text) {
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
int getInt(string s, int &poz) {
    int len = s.length();
    char c;
    int an = 0;
    bool numberFound = false;
    string str;
    while(poz < len) {
        c = s[poz];
        if ((c >= '0') && (c <= '9')) {
                numberFound = true;
                str = c;
                an = an*10 + StringToNumber<int>(str); 
        }else if (numberFound) {
            break;
        }
        poz++;
    }
    return an;
}

char getChar(string s, int &poz) {
    int len = s.length();
    char c;
    while(poz < len) {
        c = s[poz];
        if ((c >= 'A') && (c <= 'Z')) {
            return c;
        }
        poz++;
    }
    return 0;
}


const int MAXN = 1200 + 3;
const int MOD = 1000;
int reg[10];
int ram[MAXN];
int cases;

void clearAll() {
    for (int i = 0; i < 10; i++) {
        reg[i] = 0;
    }
    for (int i = 0; i < MAXN; i++) {
        ram[i] = 0;
    }
}


const string FILENAME = "";
int main () {
    //ios_base::sync_with_stdio (false);
    cin >> cases;
    string line;
    int commnad;
    int ramSize = 0, counter = 0;
    int poz = 0;
    getline(cin, line);
    bool stop;
    getline(cin, line);

    for (int i = 0; i < cases; i++) {
        clearAll();
        counter = 0;
        ramSize = 0;
        counter = 0;
        while(getline(cin, line) 
                && line != "" 
                && line != "\n"
                && line != "\r\n") {
            poz = 0;
            int val = getInt(line, poz);
            ram[ramSize] = val;
            ramSize++;
            if (cin.eof()) {
                break;
            }
        }       
        stop = false;
        for (int j = 0; j < 1000 && !stop; j++) {
            commnad  = ram[j] / 100;
            int s, f;
            s = ((ram[j]/10) % 10);
            f = ram[j] % 10;
            counter++;
            switch (commnad) {
                case 1 : 
                    if (i == 0) {
                        cout << counter << endl;
                    }else {
                        cout << endl << counter << endl;
                    }
                    stop = true;
                    break;
                case 2 :
                    reg[s] = f;
                    break;
                case 3 : 
                    reg[s] = (reg[s] + f) % MOD;
                    break;
                case 4 : 
                    reg[s] = (reg[s]*f) % MOD;
                    break;
                case 5 : 
                    reg[s] = (reg[f]) % MOD;
                    break;
                case 6 : 
                    reg[s] = (reg[s] + reg[f]) % MOD;
                    break;
                case 7 : 
                    reg[s] = (reg[s]*reg[f]) % MOD;
                    break;
                case 8 :
                    reg[s] = (ram[reg[f]]) % MOD;
                    break;
                case 9 :
                    ram[reg[f]] = reg[s] % MOD;
                    break;
                case 0 :
                    if (reg[f]!=0) {
                        int val = reg[s];
                        j = val % MOD;
                        j--;
                    }
                    break;
            }
        }
    }
    return 0;
}
