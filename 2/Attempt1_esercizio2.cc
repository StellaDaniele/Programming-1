#include <cstdlib>
#include <iostream>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"

int pow(int base, int exponent) {
    if (exponent <= 0)
        return 1;
    return base * pow(base, exponent - 1);
}

int cifre(int n, int c) {
    int tmp = n % (pow(10, c));
    tmp = tmp / (pow(10, c - 1));
    return tmp;
}

void funzione_aux(int n, int& ris) {
    if (n <= 0)
        return;
    if (cifre(n, 1) % 2 != 0 && cifre(n, 2) % 2 != 0)
        funzione_aux(n / 10, ++ris);
    else
        funzione_aux(n / 10, ris);
}

int funzione(int n) {
    // Soluzione non efficientissima, ma corretta!
    int ris = 0;
    funzione_aux(n, ris);
    return ris;
}
// Scrivere qui sopra la dichiarazione e definizione della funzione "funzione"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <positivenum> " << std::endl;
        exit(1);
    }
    int n = atoi(argv[1]);
    std::cout << "The read string is: " << argv[1] << std::endl;
    std::cout << "The converted value is: " << n << std::endl;
    std::cout << "function(" << n << ") = " << funzione(n) << std::endl;
}
