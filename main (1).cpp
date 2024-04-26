#include <iostream>
#include <cmath>

using namespace std;

int fibonacci(int n) {
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

bool is_prime(int num) {
    if (num <= 1)
        return false;
    else if (num <= 3)
        return true;
    else if (num % 2 == 0 || num % 3 == 0)
        return false;
    else {
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0)
                return false;
        }
        return true;
    }
}

int nth_term(int N) {
    if (N % 2 == 0) {
        int prime_count = 0;
        int i = 2;
        while (prime_count < N / 2) {
            if (is_prime(i))
                prime_count++;
            i++;
        }
        return i - 1;
    } else {
        int fibonacci_count = 0;
        int i = 0;
        while (fibonacci_count < (N + 1) / 2) {
            i++;
            if (fibonacci(i))
                fibonacci_count++;
        }
        return fibonacci(i);
    }
}

int main() {
    int N;
    cin >> N;
    cout << nth_term(N) << endl;
    return 0;
}
