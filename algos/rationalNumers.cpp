struct Number {
    LL u, d;

    Number() {
    }

    Number(LL up, LL down) {
        this->u = up;
        this->d = down;
    }


    LL gcd(LL a, LL b) {
        a = abs(a);
        b = abs(b);
        if (b == 0) return a;
        return gcd(b, a%b);
    }

    LL lcm(LL a, LL b) {
        return a/gcd(a, b)*b;
    }

    void simplify(LL &up, LL &down) {
        LL gcdiv = gcd(up, down);
        up /= gcdiv;
        down /= gcdiv;
    }

    Number& operator=(const Number &number) {
        this->u = number.u;
        this->d = number.d;
        return *this;  // Return a reference to myself.
    }

    Number operator+(const Number number) {
        LL up;
        LL down;
        up = this->u*number.d + number.u*this->d;
        down = this->d*number.d;
        simplify(up, down);
        return Number(up, down);
    }

    Number operator-(const Number number) {
        LL up;
        LL down;
        up = this->u*number.d - number.u*this->d;
        down = this->d*number.d;
        simplify(up, down);
        return Number(up, down);
    }

    Number operator*(const Number number) {
        LL up;
        LL down;
        up = this->u*number.u;
        down = this->d*number.d;
        simplify(up, down);
        return Number(up, down);
    }

    Number operator/(const Number number) {
        LL up;
        LL down;
        up = this->u*number.d;
        down = this->d*number.u;
        simplify(up, down);
        return Number(up, down);
    }

    bool operator>(const Number number) {
        Number rez = (*this)-number;
        return (rez.u > 0 && rez.d > 0);
    }

    bool operator<=(const Number number) {
        Number rez = (*this)-number;
        return (rez.u <= 0 && rez.d > 0);
    }

};

