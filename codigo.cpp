#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Obtener el número de variables (n)
    int n;
    cout << "Ingrese el número de variables: ";
    cin >> n;

    // Crear matrices para almacenar los coeficientes y resultados
    vector<vector<double>> coeficientes(n, vector<double>(n, 0.0));
    vector<double> resultados(n, 0.0);

    // Ingresar los coeficientes del sistema de ecuaciones
    cout << "Ingrese los coeficientes del sistema de ecuaciones:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Coeficiente [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> coeficientes[i][j];
        }
        cout << "Resultado [" << i + 1 << "]: ";
        cin >> resultados[i];
    }

    // Resolver el sistema de ecuaciones usando eliminación gaussiana
    for (int i = 0; i < n; ++i) {
        // Hacer que el coeficiente en la diagonal sea 1
        double pivot = coeficientes[i][i];
        for (int j = 0; j < n; ++j) {
            coeficientes[i][j] /= pivot;
        }
        resultados[i] /= pivot;

        // Hacer que los demás elementos de la columna sean 0
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = coeficientes[k][i];
                for (int j = 0; j < n; ++j) {
                    coeficientes[k][j] -= factor * coeficientes[i][j];
                }
                resultados[k] -= factor * resultados[i];
            }
        }
    }

    // Mostrar la solución
    cout << "\nLa solución es:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Variable " << i + 1 << ": " << resultados[i] << endl;
    }

    return 0;
}
