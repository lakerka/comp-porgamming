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

struct Point {
    int x, y;
    Point() {
        this->x = 0;
        this->y = 0;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    inline Point operator = (const int &val) {
        this->x = val;
        this->y = val;
    }

    inline Point operator = (const Point &p) {
        this->x = p.x;
        this->y = p.y;
    }
};

struct Rect {
    Point upleft, downRight;
    Rect() {
        this->upleft = Point();
        this->downRight = Point();
    }
    Rect(Point l, Point r) {
        this->upleft = l;
        this->downRight = r;
    }
    Rect(int lx, int ly, int rx, int ry) {
        this->upleft.x = lx;
        this->upleft.y = ly;
        this->downRight.x = rx;
        this->downRight.y = ry;
    }
    Rect(Point p) {
        this->upleft = p;
        this->downRight = p;
    }
    
};

const int MAXN = 250 + 3;
char col[MAXN][MAXN];
bool taken[MAXN][MAXN];
int n; // column
int m; // row

void color(Rect rect, char color) {
    for (int j = rect.upleft.y; j >= rect.downRight.y; j--) {
        for (int i = rect.upleft.x; i <= rect.downRight.x; i++) {
            col[j][i] = color;
        }
    }
}

void colorAdj(Point p, char color) {
    stack<Point> s;
    vector<Point> t;
    s.push(p);
    char curColor;
    while (!s.empty()) {
        p = s.top();
        s.pop();
        curColor = col[p.y][p.x];
        col[p.y][p.x] = color;
        for (int i = -1; i < 2; i+=2) {

            if (col[p.y][p.x + i] == color
                && p.x + i > 0 && p.x + i <= m
                && !taken[p.y][p.x + i]) {

                Point point = Point(p.x + i, p.y); 
                taken[point.y][point.x] = true;
                s.push(point);
                t.push_back(point);
            }
            if (col[p.y + i][p.x] == color 
                && p.y + i > 0 && p.y + i <= n
                && !taken[p.y + i][p.x]) {

                Point point = Point(p.x, p.y + i); 
                taken[point.y][point.x] = true;
                s.push(point);
                t.push_back(point);
            }
        }
    }
    int size = t.size();
    REP(i, size) {
        p = t.back();
        taken[p.y][p.x] = false;
        t.pop_back();
    }
    
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

const string FILENAME = "";
int main () {
    //ios_base::sync_with_stdio (false);
    string line;
    int poz = 0;
    while(getline(cin, line)) {
        char c = line[0];
        switch (c) {
        case 'I' : 
             
            ; 
            break;
        case 'C' : ; 
            break;
        case 'L' : ;
            break;
        case 'V' : ;
            break;
        case 'H' : ;
            break;
        case 'K' : ;
            break;
        case 'F' : ;
            break;
        case 'S' : ;
            break;
        case 'X' : return 0;
            break;

        }
    }
    //FILE *out;
    //out = fopen((FILENAME+OUT).c_str(), "w");
    //FILE *in;
    //in = fopen((FILENAME+IN).c_str(), "r");
    //fclose(in);
    //fclose(out);
    return 0;
}
