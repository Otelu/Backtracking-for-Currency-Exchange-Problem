#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int i, utilizat[100], t[100], s, n, nr[100], k;

int valid(int sc) {
    if (sc < 0)
        return 0;
    return 1;
}

int solutie(int sc) {
    if (sc == 0)
        return 1;
    return 0;
}

void initial(int &sc) {
    sc = s;
}

void bck(int &sc) {
    initial(sc);
    for (i = 1; i <= n; i++) {
        if (sc / t[i] != 0) {
            if (nr[i] >= sc / t[i]) {
                if (valid(sc) == 1) {
                    nr[i] = nr[i] - sc / t[i];
                    utilizat[i] = sc / t[i];
                    sc = sc - sc / t[i] * t[i];
                    if (solutie(sc) == 1)
                        tipar();
                    else
                        bck(sc);
                }
            }
        }
    }
}

void tipar () {
    k++;
    cout << "\n";
    cout << "Solutia numarul " << k << " este";
    s = 0;
    for (i = 1; i <= n; i++) {
        cout << "\n";
        cout << t[i] << " * " << utilizat[i] << " = " << t[i] * utilizat[i] << ", suma = " << (s += t[i] * utilizat[i]);
    }
    cout << "\n";
}

int main() {
    FILE *f;
    f = fopen("date.in", "r");

    fscanf(f, "%d", &n);
    for (i = 1; i <= n; i++) {
        fscanf(f, "%d", &t[i]);
        fscanf(f, "%d", &nr[i]);
    }
    fscanf(f, "%d", &s);

    bck(s);

    fclose(f);

    return 0;
}
