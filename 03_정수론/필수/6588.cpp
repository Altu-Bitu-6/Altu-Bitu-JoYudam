#include <iostream>
#include <vector>

using namespace std;

bool is_prime[1000012];

void findPrimes() {
    is_prime[1] = true;
    for (int i = 2; i <= 500000; i++) {
        for (int j = i * 2; j <= 1000000; j += i) {
            is_prime[j] = true;
        }
    }
}

void goldBachConjecture() {
    findPrimes();
    vector<int> primes;
    for (int i = 2; i <= 1000000; i++) {
        if (!is_prime[i])
            primes.push_back(i);
    }

    int n;
    while (true) {
        cin >> n;
        if (n == 0)
            break;

        bool is_print = false;
        for (int i = 0; i < primes.size() && primes[i] < n; i++) {
            if (!is_prime[n - primes[i]]) {
                cout << n << " = " << primes[i] << " + " << n - primes[i]
                     << "\n";
                is_print = true;
                break;
            }
        }
        if (!is_print)
            cout << "Goldbach's conjecture is wrong.\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    goldBachConjecture();

    return 0;
}
