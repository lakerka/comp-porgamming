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
#include <cassert>
#include <fstream>
 
using namespace std;

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#define cvar(x) cerr << "<" << #x << ": " << x << ">"
#define evar(x) cvar (x) << endl
template<class T> void DISP (const char *s, T x, int n) {cerr << "[" << s << ": "; for (int i = 0; i < n; ++i) cerr << x[i] << " "; cerr << "]" << endl;}
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

const string OUT = ".out";
const string IN = ".in";


string reverseString(string str) {
    int s=0;
    int e = str.length()-1;
    while(s < e) {
        swap(str[s], str[e]);
        s++;
        e--;
    }
    return str;
}
//converts from base 10 to base 2
string toBase2(LL sk) {
    char b1 = '1';
    char b0 = '0';
    string an = "";
    int strLen = 0;
    while(sk != 0) {
         if (sk & 1) {
            an += b1; 
         }else {
            an += b0;
         }
         sk >>= 1;
         strLen += 1;
    }
    int s=0;
    int e = strLen-1;
    while(s < e) {
        swap(an[s], an[e]);
        s++;
        e--;
    }
    return an;
}

//convert from base 2 to 10
LL toBase10(string str) {
    LL an = 0;
    int s=0;
    int len = str.length();
    int e = len-1;
    //apsukim eilute
    while(s < e) {
        swap(str[s], str[e]);
        s++;
        e--;
    }
    LL p = 1;
    for (int i = 0; i < len; i++) {
        //cout <<"i: " << i <<  "p " << p << endl;
        if (str[i] == '1') {
            an += p;
        } 
        p =p *  (LL)2;
    }
    return an;
}


template <typename T>
struct Node {
    T val;
    int level;
    bool visited;
    Node *parent;
    vector<Node *> child;
    LL childCount;
    
    Node() {

    }

    Node(T value, Node *parent) {
        this->val = value;
        this->parent = parent;
        this->childCount = 0;
        this->visited = false;
        this->level = 0;
    }

    void setLevel(int level) {
        this->level = level;
    }

    void getLevel(int level) {
        return this->level;
    }

    void setVisited(bool visited) {
        this->visited = visited;
    }

    void getVisited(bool visited) {
        return this->visited;
    }
    void addChild(Node *child) {
        child->level = this->level + 1;
        this->child.push_back(child);
        this->childCount++;
    }
    bool remChild(int index) {
        bool suc = child.erase(this->child.begin(), this->child.begin() + index);    
        if (suc) {
            this->childCount--;
        }
        return suc;
    }
};

struct Trie {
    Node<char> root;

    Trie() {
        this->root = Node<char>('R', NULL);
        this->root.setLevel(0);
    }
    void add(LL val) {
        Node<char> *cur = &(this->root);
        string v = toBase2(val);
        //fill with zero's
        while(v.length() < 60) {
            v.insert(v.begin(), '0');
        }

        int len = v.length();
        bool found;
        //desim reiksmes i medi
        //bitai arciau saknies yra reiksmingesni
        for (int i = 0; i < len; i++) {
            found = false;
            int childCount = cur->childCount;
            for(int j = 0; j < childCount; j++) {
                // tikrinam ar vaikuose jau nera tokios reiksmes
                if (cur->child[j]->val == v[i]) {
                    found = true;
                    cur = cur->child[j];
                    break;
                }
            }    
            //pridedam virsune, kadangi tokios nera vaikuose
            if (!found) {
                Node<char> *vert = new Node<char>(v[i], cur);
                cur->addChild(vert);
                cur = vert;
            }
        }
    }


};

Node<char>* stepBack(Node<char> *nodePtr)  {
    if (nodePtr != NULL) {
        return nodePtr->parent; 
    }else {
        return NULL;
    }
}

Node<char>* stepTo(char val, Node<char> *nodePtr)  {
    if (nodePtr != NULL) {
        Node<char> *child; 
        for (int i = 0; i < nodePtr->childCount; i++) {
            child = nodePtr->child[i];
            if (child->val == val) {
                return child;
            }
        }
        return NULL;
    }else {
        return NULL;
    }
}

void traverse(Node<char> *node) {
    
    char vienas = 'v';
    char nulis = 'n';
    char back = 'b';
    char exit = 'e';
    char dir = 'y';
    cin >> dir;
    do {
        if (dir == nulis) {
            node = stepTo('0', node);
        }else if (dir == vienas) {
            node = stepTo('1', node);
        }else if (dir == 'b') {
            node = stepBack(node);
        }
        if (node != NULL) {
            cout << node->val << endl;
        }else {
            cout << "NULL" << endl;
        }
        cin >> dir;
    } while (dir != exit);
}


int n;
LL optimalVal = 0;
string curVal = "";
string bestXor = "";
Node<char>* optNode;
Node<char>* curNode;
//goes to opossite if can, adds branch value to bestXor
Node<char>* addOposite(char val) {
    Node<char>* checkNode;
    char opposite;
    if (val == '0') {
        opposite = '1';
    }else {
        opposite = '0';
    }
    checkNode = stepTo(opposite, optNode);
    if (checkNode == NULL) {
        // o jeigu neturi vaiku?
        checkNode = stepTo(val, optNode);    
        bestXor += val;
    }else {
        bestXor += opposite;
    }
    //if (checkNode == NULL) {
        //cout << "VERY BAD" << endl;
    //}
    return checkNode;
}

    int iter = 0;
bool forward()  {
    char val;
    bool moveDone = false;
    bool firstMove = true;
    while(curNode->childCount > 0 && (moveDone || firstMove) ) {
        firstMove = false;
        for (int i = 0; i < curNode->childCount; i++) {
            if (curNode->child[i]->visited == false) {
                moveDone = true;
                curNode = curNode->child[i];
                curNode->visited = true;
                val = curNode->val;
                curVal += val;
                //if (iter >= 24880) {
                    //cout << "curnode null: " << (curNode == NULL) << " level: " << optNode-> level<< endl;
                    //cout << "optimal null: " << (optNode == NULL)<< " level: " << optNode-> level << endl;

                //} 
                optNode = addOposite(val);
                //if (iter >= 24880) {
                    //cout << "no more" << endl;
                //}
                //curNode->child[i]->visited = true; 
                //val = curNode->child[i]->val;
                //curVal += val; 
                //optNode = addOposite(val);
                //curNode = curNode->child[i];
                break;
            }
        }
    }
    return moveDone;
}

bool backward() {
    //if (iter >= 24880) {
        //cout << "pasiekem" << endl;
    //}

    //if (iter >= 24880) {
        //cout << "seg" << endl;
    //}
    while (curNode != NULL && curNode->parent != NULL) {
        //if (iter >= 24880) {
            ////cout << "=1=" << endl;
            //cout << (optNode == NULL) << endl;
        //}
        curNode = curNode->parent;
        optNode = optNode->parent;
        //if (iter >= 24880) {
            //cout << "=2=" << endl;
        //}
        curVal.erase(curVal.end()-1);
        bestXor.erase(bestXor.end()-1);
        //if (iter >= 24880) {
            //cout << "=3=" << endl;
        //}
        for (int i = 0; i < curNode->childCount; i++) {
            if (curNode->child[i]->visited == false) {
                return true;
            }
        }
    }
    return false;
}

LL histo[1000000 + 50];

void brute() {
     LL opt = 0;
     for (int i = 0; i < n; i++) {
        //if (histo[i] > opt) {
            //opt = histo[i];
        //}
        opt = max(opt, histo[i]);
        for (int j = i+1; j < n; j++) {
            opt = max(opt, histo[i]^histo[j]);
            //if (histo[i]^histo[j] > opt) {
                //opt = histo[i]^histo[j];
            //}
        }
     }
    cout << "Brute optimal: " << opt << endl;
}

const string FILENAME = "";
int main () {
    //cout << toBase10("111111111111111111111111111111111111111111111111111111111111") << endl;
    //return 0;
    Trie trie;
    optNode = (&trie.root);
    curNode = (&trie.root);
//1152921504606846975LL larger 
    //if (576460752303423487LL > LL(1e18)) {
        //cout << "larger" << endl;
    //}else {
        //cout << "smaller" << endl;
    //}
    //1000000000000000000 
    cin >> n;
    LL sk = 0;
    LL x = 0;
    for (int i = 0; i < n; i++) {
        cin >> sk;
        x = x^sk;
        //
        //histo[i] = x;
        //cout << x << endl;
        //cout << "b: " << toBase2(x) << endl;
        //
        trie.add(x);
    }
    bool allTraversed = false;
    LL value, valueXor;
    LL xoras;
    
    
    //brute();
    //return 0;    
    while(!allTraversed) {
        ++iter;
        //cout << "Branch: " << ++iter << endl;
        //cout << "forward fail" << endl;
        allTraversed = !forward();
        if (allTraversed) {
            break;
        }
        value = toBase10(curVal);
        valueXor = toBase10(bestXor);
        xoras = value xor valueXor;
        //cout << "curval : " << curVal << endl;
        //cout << "bestXor: " << bestXor << endl;
        //cout << value << " xor " << valueXor << " = " << xoras  << endl;
        //cout << "===================" << endl;
        if (xoras > optimalVal) {
            optimalVal = xoras;
        }
        if (value > optimalVal) {
            optimalVal = value;
            //cout << optimalVal << endl;
        }
        //cout << "backward fail" << endl;
        backward();
    }
    cout << optimalVal << endl;
    return 0;
}
