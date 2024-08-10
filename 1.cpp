

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void printPolynomial(const vector<int>& coeffs) {
    int degree = coeffs.size() - 1;
    bool firstTerm = true;

    for (int i = degree; i >= 0; --i) {
        if (coeffs[i] != 0) {
            if (!firstTerm) {
                cout << " ";
                if (coeffs[i] > 0) cout << "+";
            }
            if (i == 0 || coeffs[i] != 1) {
                cout << coeffs[i];
            }
            if (i > 0) {
                cout << "x";
                if (i > 1) cout << "^" << i;
            }
            firstTerm = false;
        }
    }
    if (firstTerm) {
        cout << "0";
    }
    cout << endl;
}


void calculateAndPrintDerivative(const vector<int>& coeffs) {
    int degree = coeffs.size() - 1;
    vector<int> derivative(degree);

    for (int i = 1; i <= degree; ++i) {
        derivative[i - 1] = coeffs[i] * i;
    }

    cout << "The derivative of the polynomial is: ";
    printPolynomial(derivative);
}

int main() {
    int degree;
    cout << "Enter the degree of the polynomial (0 to 5): ";
    cin >> degree;

    if (degree < 0 || degree > 5) {
        cerr << "Degree out of bounds. Please enter a degree between 0 and 5." << endl;
        return 1;
    }

    vector<int> coefficients(degree + 1);

    cout << "Enter the coefficients of the polynomial (from highest degree to constant term):" << endl;
    for (int i = degree; i >= 0; --i) {
        cout << "Coefficient of x^" << i << ": ";
        cin >> coefficients[i];
    }

    cout << "The polynomial is: ";
    printPolynomial(coefficients);

    calculateAndPrintDerivative(coefficients);

    return 0;
}

