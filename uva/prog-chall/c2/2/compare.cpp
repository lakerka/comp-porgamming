#include <tr1/unordered_map>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
 
using namespace std;

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



const int MAXN = 5 + 3;
struct Card {
    char color;
    int value;
    Card() {
    }
    Card(char color, int value) {
        this->color = color;
        this->value = value;
    }
    bool operator==(const Card card) {
        if (this->color == card.color
                && this->value == card.value) {
            return true;
        }
        return false;
    }
};

vector<string> r, m;


int main () {
    string my, real;
    ifstream inReal, inMy;    
    inReal.open("correct");
    inMy.open("my");
    while(getline(inReal, real)) {
        //cout << real << endl;
        r.push_back(real); 
    }
    while(getline(inMy, my)) {
        //cout << real << endl;
        m.push_back(my); 
    }
    int k = 1;
    while(k != r.size()) {
        //cout << real << "|" << my << endl;
        if (r[k-1][0] != m[k-1][0]) {
            cout << "Wrong line: " << k << endl;
        }
        //break;
        k++;
    }
    inReal.close();
    inMy.close();
    return 0;
}
