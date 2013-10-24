
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

