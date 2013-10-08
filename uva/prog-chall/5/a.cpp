//Graphical Editor
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

void color(Rect rect, char toColor) {
    //cout << rect.upleft.x << " " << rect.upleft.y << endl;
    //cout << rect.downRight.x << " " << rect.downRight.y << endl;
    for (int j = rect.upleft.y; j <= rect.downRight.y; j++) {
        for (int i = rect.upleft.x; i <= rect.downRight.x; i++) {
            //cout << i << " " << j << " color:" << toColor << endl;
            col[j][i] = toColor;
        }
    }
}

void colorAdj(Point p, char toColor) {
    stack<Point> s;
    vector<Point> t;
    s.push(p);
    char curColor;
    while (!s.empty()) {
        p = s.top();
        s.pop();
        curColor = col[p.y][p.x];
        col[p.y][p.x] = toColor;
        for (int i = -1; i < 2; i+=2) {

            if (col[p.y][p.x + i] == curColor
                && p.x + i > 0 && p.x + i <= m
                && !taken[p.y][p.x + i]) {

                Point point = Point(p.x + i, p.y); 
                taken[point.y][point.x] = true;
                s.push(point);
                t.push_back(point);
            }
            if (col[p.y + i][p.x] == curColor 
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

void pr(string filename, int x, int y) {
    cout << filename << endl;
    for (int i = 1; i < y+1; i++) {
        for (int j = 1; j < x+1; j++) {
            //cout << y << " " << x << " color: " << col[i][j] <<     endl;
            printf("%c", col[i][j]);
        }
        printf("\n");
    }
}

const char WHITE = 'O';

const string FILENAME = "";
int main () {
    //ios_base::sync_with_stdio (false);
    string line;
    int poz = 0;
    int x1, x2;
    int y1, y2;
    char toColor;
    while(getline(cin, line)) {
        char c = line[0];
        poz = 0;
        switch (c) {
        case 'I' : 

            //cout << "darau i " << endl;
                m = getInt(line, poz); //toColor
                n = getInt(line, poz); // row
                color(Rect(1,1, m, n), WHITE);
            break;
        case 'C' : 
                color(Rect(1,1, m, n), WHITE);
            break;
        case 'L' : 
            //cout << "darau l " << endl;
                x1 = getInt(line, poz); //
                y1 = getInt(line, poz); //
                toColor = getChar(line, poz); //
                //cout << endl << "coord: " << x1 << " " << y1 << endl;
                //cout << endl << "color: " << toColor << endl;
                color(Rect(x1, y1, x1, y1), toColor);
                //cout << col[y1][x1] << endl;
            break;
        case 'V' : 
                x1 = getInt(line, poz); //
                y1 = getInt(line, poz); //
                y2 = getInt(line, poz); //
                toColor = getChar(line, poz); //
                color(Rect(x1, min(y1, y2), x1, max(y1, y2)), toColor);
            
            break;
        case 'H' : 
                x1 = getInt(line, poz); //
                x2 = getInt(line, poz); //
                y1 = getInt(line, poz); //
                toColor = getChar(line, poz); //
                color(Rect(min(x1, x2), y1, max(x1, x2), y1), toColor);
            break;
        case 'K' :
                x1 = getInt(line, poz); //
                y1 = getInt(line, poz); //
                x2 = getInt(line, poz); //
                y2 = getInt(line, poz); //
                toColor = getChar(line, poz); //
                color(Rect(min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2)), toColor);
            break;
        case 'F' : 
                x1 = getInt(line, poz); //
                y1 = getInt(line, poz); //
                toColor = getChar(line, poz); //
                colorAdj(Point(x1, y1), toColor);
            break;
        case 'S' : ;
            line.erase(line.begin(), line.begin() + 2);
            pr(line, m, n);
            break;
        case 'X' :
                return 0;
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
