#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n;
    cout << "Ingrese el número de variables: ";
    cin >> n;

    
    vector<vector<double>> coeficientes(n, vector<double>(n, 0.0));
    vector<double> resultados(n, 0.0);

    
    cout << "Ingrese los coeficientes del sistema de ecuaciones:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Coeficiente [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> coeficientes[i][j];
        }
        cout << "Resultado [" << i + 1 << "]: ";
        cin >> resultados[i];
    }

    
    for (int i = 0; i < n; ++i) {
        
        double pivot = coeficientes[i][i];
        for (int j = 0; j < n; ++j) {
            coeficientes[i][j] /= pivot;
        }
        resultados[i] /= pivot;

        
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = coeficientes[k][i];
                for (int j = 0; j < n; j++) {
                    coeficientes[k][j] -= factor * coeficientes[i][j];
                }
                resultados[k] -= factor * resultados[i];
            }
        }
    }

   
    cout << "\nLa solución es:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Variable " << i + 1 << ": " << resultados[i] << endl;
    }

    return 0;
}
