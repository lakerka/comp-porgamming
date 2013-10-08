
typedef long long LL;
// raises by large power modulus mod
//a- number, p - degree, mod - modulus
//complexity log(p)
int toPower(int a, int p, LL mod){   
    LL r = 1;
	while (p) {
		if (p & 1) r = LL(r) * LL(a) % LL(mod);
		p >>= 1; 
        a = LL(a) * LL(a) % LL(mod);
    }
	return r;
}

