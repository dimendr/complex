#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Complex {
private:
    double re;
    double im;

public:

    Complex(double re, double im) {
        this->re = re;
        this->re = im;
    }

    Complex(string num) {
        string result;
        for (int i = 0; i < num.length(); i++) {
            if (num[i] != ' ') result.push_back(num[i]);
        }
        stringstream ss;
        ss << result;
        double res;
        ss >> res;
        this->re = res;

        ss >> res;
        this->im = res;
    }

    double get_re() const {
        return this->re;
    }

    double get_im() const {
        return this->im;
    }

    Complex operator +(const Complex& obj) {
        Complex a(this->re, this->im);
        this->re = this->re + obj.re;
        this->im = this->re + obj.re;
        return a;
    }

    Complex operator -(const Complex& obj) {
        Complex a(this->re, this->im);
        this->re -= obj.re;
        this->im -= obj.im;
        return a;
    }

    Complex operator *(const Complex& obj) {
        Complex a(this->re, this->im);
        this->re *= obj.re;
        this->im *= obj.im;
        return a;
    }




    Complex operator /(const Complex& obj) {
        Complex a(this->re, this->im);
        this->re /= obj.re;
        this->im /= obj.im;
        return a;
    }
};

std::ostream& operator <<(std::ostream& out, const Complex& num) {
    out << num.get_re() << (num.get_im() <= 0 ? "" : "+") << num.get_im() << 'j';
    return out;
}

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1(num);

    std::getline(std::cin, num, 'j');
    Complex c2(num);

    std::cout << c1 + c2 << endl;
}