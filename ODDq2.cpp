#include <iostream>
#include <vector>

using namespace std;


void printPrimes(int n) {
    if (n < 2) {
        cout << "No prime numbers less than or equal to " << n << endl;
        return;
    }


    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;


    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    cout << "Prime numbers up to " << n << ": ";
    for (int p = 2; p <= n; ++p) {
        if (isPrime[p]) {
            cout << p << " ";
        }
    }
    cout << endl;
}

int main() {
    int number;

    cout << "Enter an integer: ";
    cin >> number;

    if (number < 0) {
        cout << "The number must be non-negative." << endl;
        return 1;
    }

    printPrimes(number);

    return 0;
}

