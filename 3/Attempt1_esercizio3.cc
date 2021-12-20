#include <iostream>

using namespace std;

// SB: ok
bool* create(int dim) {
    bool* array = new bool[dim];
    // SB: meglio evitare di mettere istruzione condizionale e corpo nella stessa riga
    for (int i = 0; i < dim; i++) array[i] = false;
    return array;
}

// SB: ok
void insert(bool* filter, int dim, char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (int(str[i]) < dim) {
            // SB: meglio evitare di mettere istruzione condizionale e corpo nella stessa riga
            if (!filter[int(str[i])]) filter[int(str[i])] = true;
        }
        // SB: meglio evitare di mettere istruzione condizionale e corpo nella stessa riga
        else if (!filter[int(str[i]) % dim])
            filter[int(str[i]) % dim] = true;
    }
}

// SB: ok
bool control(bool* filter, int dim, char str[]) {
    bool presente = true;
    for (int i = 0; str[i] != '\0' && presente; i++) {
        if (int(str[i]) < dim) {
            presente = filter[int(str[i])];
        }
        // SB: meglio evitare di mettere istruzione condizionale e corpo nella stessa riga
        else
            presente = filter[int(str[i]) % dim];
    }
    return presente;
}

// SB: ok
void deinit(bool* filter) {
    delete[] filter;
}

int main(int argc, char* argv[]) {
    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool* bloom_filter = create(n);

    char ciao[] = {'c', 'i', 'a', 'o', '\0'};
    insert(bloom_filter, n, ciao);
    cout << "Ho inserito la parola 'ciao' nel bloom filter" << endl;

    if (control(bloom_filter, n, ciao)) {
        cout << "La parola 'ciao' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'ciao' NON è presente nel bloom filter " << endl;
    }

    char volo[] = {'v', 'o', 'l', 'o', '\0'};
    if (control(bloom_filter, n, volo)) {
        cout << "La parola 'volo' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'volo' NON è presente nel bloom filter " << endl;
    }

    deinit(bloom_filter);

    return 0;
}
