#include <iostream>

// 최대 공약수를 구하는 함수
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// 분수를 기약분수로 만드는 함수
void simplifyFraction(int &numerator, int &denominator) {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

// 두 분수의 합을 구하는 함수
void addFractions(int numerator1, int denominator1, int numerator2,
                  int denominator2, int &resultNumerator,
                  int &resultDenominator) {
    resultNumerator = numerator1 * denominator2 + numerator2 * denominator1;
    resultDenominator = denominator1 * denominator2;
    simplifyFraction(resultNumerator, resultDenominator);
}

int main() {
    int numerator1, denominator1, numerator2, denominator2;
    std::cin >> numerator1 >> denominator1 >> numerator2 >> denominator2;

    int resultNumerator, resultDenominator;
    addFractions(numerator1, denominator1, numerator2, denominator2,
                 resultNumerator, resultDenominator);

    std::cout << resultNumerator << " " << resultDenominator << std::endl;

    return 0;
}
