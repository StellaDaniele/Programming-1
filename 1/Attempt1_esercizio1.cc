#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

#define MAX_LEN 101

int length(char s[]) {
    int i = 0;
    for (; s[i] != '\0'; i++)
        ;
    return i;
}

bool check(char s[]) {
    bool res = true;
    if (length(s) != 19) res = false;
    for (int i = 0; s[i] != '\0' && res; i++) {
        if (i == 4 || i == 9 || i == 14) {
            if (s[i] != '-') res = false;
        } else if (s[i] > '9' || s[i] < '0')
            res = false;
    }
    return res;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
        exit(1);
    }

    fstream in, out;
    in.open(argv[1], ios::in);
    out.open(argv[2], ios::out);
    if (in.fail() || out.fail()) {
        cerr << "An error has occured trying to open the specified files" << endl;
        in.close();
        out.close();
        exit(1);
    }
    int cont = 0;
    char buffer[MAX_LEN];
    while (in >> buffer) {
        if (check(buffer))
            cont++;
    }
    out << cont << endl;
    in.close();
    out.close();
    return 0;
}
