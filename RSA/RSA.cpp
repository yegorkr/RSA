#include <vector>
#include <iostream>
#include <string>
#include <cstddef>
#include <unordered_map>
#include <string>
#include <fstream>
#include <set>
#include <random>
#include <ctime>
#include <math.h>


using namespace std;
const vector<int> zero = { 0 };
const vector<int> one = { 1 };
const vector<int> two = { 2 };
const vector<int> three = { 3 };
const vector<int> five = { 5 };
const vector<int> four = { 4 };
const vector<int> six = { 6 };
const vector<int> eight = { 8 };

string toString(vector<int> a) {
	string s = "";
	for (int i = 0; i < a.size(); ++i)
		s += to_string(a[i]);
	return s;
}

vector<int> mexp(vector<int> a, vector<int> b, vector<int> c);
vector<int> add(vector<int> a, vector<int> b);
vector<int> sub(vector<int> a, vector<int> b);
vector<int> max(vector<int> a, vector<int> b);
vector<int> min(vector<int> a, vector<int> b);
vector<int> mult(vector<int> a, vector<int> b);
vector<int> div(vector<int> a, vector<int> b);
vector<int> mod(vector<int> a, vector<int> b);
vector<int> pow(vector<int> a, vector<int> b);
vector<int> gcd(vector<int> a, vector<int> b);
vector<int> m(vector<int> a);
vector<int> v(string);
void print(vector<int> a);
string toString(vector<int> a);
string toString(vector<int> a);
int eq(vector<int> a, vector<int> b);

void RSA(vector<int> a, vector<int> b);

const unsigned int k[64] = {
0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2 };

vector<unsigned char> SHA256(vector<unsigned char> input) {
	unsigned long long s = input.size();
	unsigned int w[64], s0, s1, ch, t1, t2;
	input.push_back((unsigned char)128);
	while ((input.size() + 8) % 64 != 0) input.push_back(0);
	input.push_back(s);
	input.push_back(s >> 8);
	input.push_back(s >> 16);
	input.push_back(s >> 24);
	input.push_back(s >> 32);
	input.push_back(s >> 40);
	input.push_back(s >> 48);
	input.push_back(s >> 56);
	unsigned int h0 = 0x6a09e667;
	unsigned int h1 = 0xbb67ae85;
	unsigned int h2 = 0x3c6ef372;
	unsigned int h3 = 0xa54ff53a;
	unsigned int h4 = 0x510e527f;
	unsigned int h5 = 0x9b05688c;
	unsigned int h6 = 0x1f83d9ab;
	unsigned int h7 = 0x5be0cd19;
	while (input.size() > 0) {
		for (int i = 0; i < 16; ++i) w[i] = (unsigned int)input[4 * i] << 24 | (unsigned int)input[4 * i + 1] << 16 | (unsigned int)input[4 * i + 2] << 8 | (unsigned int)input[4 * i + 3];
		for (int i = 16; i < 64; ++i) {
			s0 = (w[i - 15] >> 7 | w[i - 15] << 25) ^ (w[i - 15] >> 18 | w[i - 15] << 14) ^ (w[i - 15] >> 3 | w[i - 15] << 29);
			s1 = (w[i - 2] >> 17 | w[i - 2] << 15) ^ (w[i - 2] >> 19 | w[i - 2] << 13) ^ (w[i - 2] >> 10 | w[i - 2] << 22);
			w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		}
		unsigned int a = h0;
		unsigned int b = h1;
		unsigned int c = h2;
		unsigned int d = h3;
		unsigned int e = h4;
		unsigned int f = h5;
		unsigned int g = h6;
		unsigned int h = h7;
		for (int i = 0; i < 64; ++i) {
			s1 = (e >> 6 | e << 26) ^ (e >> 11 | e << 21) ^ (e >> 25 | e << 7);
			ch = (e & f) ^ ((~e) & g);
			t1 = h + s1 + ch + k[i] + w[i];
			s0 = (a >> 2 | e << 30) ^ (a >> 13 | e << 19) ^ (a >> 22 | e << 10);
			t2 = s0 + ((a & b) ^ (a & c) ^ (b & c));

			h = g;
			g = f;
			f = e;
			e = d + t1;
			d = c;
			c = b;
			b = a;
			a = t1 + t2;
		}
		h0 = h0 + a;
		h1 = h1 + b;
		h2 = h2 + c;
		h3 = h3 + d;
		h4 = h4 + e;
		h5 = h5 + f;
		h6 = h6 + g;
		h7 = h7 + h;
		for (int i = 0; i < 64; ++i) input.erase(input.begin());
	}
	vector<unsigned char> res;
	res.push_back(h0);
	res.push_back(h0 >> 8);
	res.push_back(h0 >> 16);
	res.push_back(h0 >> 24);
	res.push_back(h0 >> 32);
	res.push_back(h0 >> 40);
	res.push_back(h0 >> 48);
	res.push_back(h0 >> 56);
	res.push_back(h1);
	res.push_back(h1 >> 8);
	res.push_back(h1 >> 16);
	res.push_back(h1 >> 24);
	res.push_back(h1 >> 32);
	res.push_back(h1 >> 40);
	res.push_back(h1 >> 48);
	res.push_back(h1 >> 56);
	res.push_back(h2);
	res.push_back(h2 >> 8);
	res.push_back(h2 >> 16);
	res.push_back(h2 >> 24);
	res.push_back(h2 >> 32);
	res.push_back(h2 >> 40);
	res.push_back(h2 >> 48);
	res.push_back(h2 >> 56);
	res.push_back(h3);
	res.push_back(h3 >> 8);
	res.push_back(h3 >> 16);
	res.push_back(h3 >> 24);
	res.push_back(h3 >> 32);
	res.push_back(h3 >> 40);
	res.push_back(h3 >> 48);
	res.push_back(h3 >> 56);
	res.push_back(h4);
	res.push_back(h4 >> 8);
	res.push_back(h4 >> 16);
	res.push_back(h4 >> 24);
	res.push_back(h4 >> 32);
	res.push_back(h4 >> 40);
	res.push_back(h4 >> 48);
	res.push_back(h4 >> 56);
	res.push_back(h4);
	res.push_back(h5 >> 8);
	res.push_back(h5 >> 16);
	res.push_back(h5 >> 24);
	res.push_back(h5 >> 32);
	res.push_back(h5 >> 40);
	res.push_back(h5 >> 48);
	res.push_back(h5 >> 56);
	res.push_back(h6);
	res.push_back(h6 >> 8);
	res.push_back(h6 >> 16);
	res.push_back(h6 >> 24);
	res.push_back(h6 >> 32);
	res.push_back(h6 >> 40);
	res.push_back(h6 >> 48);
	res.push_back(h6 >> 56);
	res.push_back(h7);
	res.push_back(h7 >> 8);
	res.push_back(h7 >> 16);
	res.push_back(h7 >> 24);
	res.push_back(h7 >> 32);
	res.push_back(h7 >> 40);
	res.push_back(h7 >> 48);
	res.push_back(h7 >> 56);
	return res;
}


vector<int> v(string s) {
	vector<int> r;
	int mFlag = 0;
	while (s.length() > 0) {
		string s1 = s.substr(0, 1);
		if (s1 == "-") {
			mFlag++; s.erase(s.begin()); continue;
		}
		int i;
		if (s1 == "0") i = 0;
		if (s1 == "1") i = 1;
		if (s1 == "2") i = 2;
		if (s1 == "3") i = 3;
		if (s1 == "4") i = 4;
		if (s1 == "5") i = 5;
		if (s1 == "6") i = 6;
		if (s1 == "7") i = 7;
		if (s1 == "8") i = 8;
		if (s1 == "9") i = 9;
		r.push_back(i);
		s.erase(s.begin());
	}
	if (mFlag) r[0] *= -1;
	return r;
}

void print(vector<int> a) {
	for (int i = 0; i < a.size(); ++i)
		cout << a[i];
	cout << "\n";
}
vector<int> m(vector<int> a) {
	a[0] = abs(a[0]);
	return a;
}

vector<int> neg(vector<int> a) {
	a[0] = a[0] * (-1);
	return a;
}

vector<int> toNeg(vector<int> a) {
	for (int i = 1; i < a.size(); ++i)
		a[i] *= -1;
	return(a);
}

vector<int> max(vector<int> a, vector<int> b) {
	if (a.size() > 1)
		if (a[0] == 0 && a[1] == 0)
			a = zero;
	if (b.size() > 1)
		if (b[0] == 0 && b[1] == 0)
			b = zero;
	if (a.size() == 0) return b;
	if (b.size() == 0) return a;
	if (a[0] < 0 && b[0] < 0) {
		if (a.size() > b.size()) return b;
		if (a.size() < b.size()) return a;
		for (int i = 0; i < a.size(); ++i)
			if (abs(a[i]) > abs(b[i])) return b;
			else if (abs(b[i]) > abs(a[i])) return a;
	}
	if (a[0] < 0) return b;
	if (b[0] < 0) return a;
	if (a.size() > b.size()) return a;
	if (a.size() < b.size()) return b;
	for (int i = 0; i < a.size(); ++i)
		if (a[i] > b[i]) return a;
		else if (b[i] > a[i]) return b;
	return a;
}

vector<int> min(vector<int> a, vector<int> b) {
	if (max(a, b) == a) return b;
	return a;
}
int eq(vector<int> a, vector<int> b) {
	if (max(a, b) == a && min(a, b) == a)
		return 1;
	return 0;
}

vector<int> add(vector<int> a, vector<int> b) {
	if (!(a[0] < 0 && b[0] < 0)) {
		if (a[0] < 0) return sub(m(b), m(a));
		if (b[0] < 0) return sub(m(a), m(b));
	}
	if (a.size() < b.size())
		swap(a, b);
	for (int i = 1; i <= a.size(); ++i) {
		if (b.size() >= i)
			a.at(a.size() - i) += b.at(b.size() - i);
		while (a.at(a.size() - i) > 9)
			if (a.size() - i == 0) {
				a.insert(a.begin(), 1);
				a[1] -= 10;
			}
			else {
				a.at(a.size() - i) -= 10;
				a.at(a.size() - i - 1) += 1;
			}
	}
	return a;
}

vector<int> sub(vector<int> a, vector<int> b) {
	int mFlag = 0;
	if (a[0] < 0 && b[0] < 0)
		return sub(m(b), m(a));
	if (a[0] < 0)
		return sub(zero, add(m(a), m(b)));
	if (b[0] < 0)
		return add(m(a), m(b));
	while (a.size() < b.size())
		a.insert(a.begin(), 0);
	if (max(a, b) == b) {
		swap(a, b);
		mFlag++;
	}
	for (int i = 1; i <= b.size(); ++i) {
		a[a.size() - i] -= b[b.size() - i];
		if (a[a.size() - i] < 0) {
			a[a.size() - i] += 10;
			a[a.size() - i - 1] -= 1;
		}
	}
	while (a[0] == 0 && a.size() > 1)
		a.erase(a.begin());
	if (mFlag) a[0] *= -1;
	return a;
}

vector<int> mult(vector<int> a, vector<int> b) {
	int mFlag = 0;
	if (a.size() < b.size())
		swap(a, b);
	if (a == zero || b == zero)
		return zero;
	if ((a[0] > 0 && b[0] < 0) || (a[0] < 0 && b[0] > 0)) {
		a = m(a);
		b = m(b);
		mFlag++;
	}
	a = m(a); b = m(b);
	vector<int> r = zero;
	for (int i = 1; i <= b.size(); ++i) {
		vector<int> c = zero;
		for (int j = b[b.size() - i]; j > 0; --j)
			c = add(c, a);
		for (int j = 1; j < i; ++j)
			c.push_back(0);
		r = add(r, c);
	}
	if (mFlag) r = neg(r);
	return r;
}

vector<int> div(vector<int> a, vector<int> b) {
	int mFlag = 0;
	if (eq(a, b)) return one;
	if (a == zero || max(a, b) == b) return zero;
	if (b == zero) { cout << "ERROR";  return a; }
	if ((a[0] > 0 && b[0] < 0) || (a[0] < 0 && b[0] > 0)) {
		a = m(a);
		b = m(b);
		mFlag++;
	}
	a = m(a); b = m(b);
	vector<int> r;
	vector<int> c;
	int i = 0; int j = 0;
	while (max(b, c) != c)
		c.push_back(a[i++]);
	while (max(b, c) == c) {
		c = sub(c, b);
		++j;
	}
	r.push_back(j);
	for (i; i > 0; --i)
		a.erase(a.begin());
	while (a.size() > 0) {
		if (c == zero) c.erase(c.begin());
		j = 0;
		while (max(b, c) != c) {
			if (i == a.size()) {
				r.push_back(0);
				return r;
			}
			c.push_back(a[i++]);
			if (i > 1) r.push_back(0);
		}
		while (max(b, c) == c) {
			c = sub(c, b);
			++j;
		}
		r.push_back(j);
		if (i > a.size()) break;
		for (i; i > 0; --i)
			a.erase(a.begin());
	}
	if (mFlag) r = neg(r);
	return r;
}

vector<int> mod(vector<int> a, vector<int> b) {
	return sub(a, mult(b, div(a, b)));
}

vector<int> pow(vector<int> a, vector<int> b) {
	b = m(b);
	vector<int> c = zero;
	vector<int> r = one;
	while (!eq(c, b)) {
		r = mult(a, r);
		c = add(c, one);
	}
	return r;
}

vector<int> gcd(vector<int> a, vector<int> b) {
	if (a == zero) return b;
	while (b != zero) {
		vector<int> r = mod(a, b);
		a = b;
		b = r;
	}
	return a;
}


vector<int> lcm(vector<int> a, vector<int> b) {
	return div(mult(a, b), gcd(a, b));
}

vector<int> mexp(vector<int> a, vector<int> b, vector<int> n) {
	if (eq(n, one)) return zero;
	vector<int> x = one;
	vector<int> y = a;
	while (!eq(b, zero)) {
		if (eq(mod(b, two), one)) {
			x = mod(mult(x, y), n); // multiplying with base
		}
		y = mod(mult(y, y), n); // squaring the base
		b = div(b, two);
	}
	return mod(x, n);
}


void RSA(vector<int> a, vector<int> b, vector<int> m) {
	srand(time(0));
	vector<int> n = mult(a, b);
	vector<int> t = mult(sub(a, one), sub(b, one));
	vector<int> e = v("343");
	while (!eq(e, t)) {
		if (eq(gcd(e, t), one)) break;
		else e = add(e, one);
	}
	vector<int> d;
	vector<int> k = two;
	vector<int> tmp = add(one, mult(k, t));
	while (!eq(mod(tmp, e), zero)) {
		k = add(k, one);
		tmp = add(one, mult(k, t));
	}
	d = div(tmp, e);
	vector<int> r;
	r.push_back((rand() % 9) + 1);
	for (int i = 1; i < 8; ++i) r.push_back((rand() % 10));
	for (int i = 0; i < 8; ++i) m.insert(m.begin() + i, r[i]);
	vector<int> c = one;
	c = mexp(m, e, n);
	print(c);
	vector<int> md = one;
	md = mexp(c, d, n);
	print(md);
}


int main()
{
	string A = "4089532177";
	string B = "60821";
	vector<unsigned char> d;
	d.push_back('3');
	d.push_back('2');
	d.push_back('4');
	d = SHA256(d);
	string ss;
	for (int i = 0; i < 2; ++i) ss = ss + to_string(d[i]);
	cout << ss << "\n";
	vector<int> m = v(ss);
	string s1, s2, s3;
	cout << "RSA\n";
	RSA(v(A), v(B), m);
	return 0;
}