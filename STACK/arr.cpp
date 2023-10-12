#include <iostream>

using namespace std;

// Function to print a matrix
void printMatrix(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i * cols + j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    // Dynamically allocate memory for the matrix data
    int* matrixData = new int[rows * cols];

    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrixData[i * cols + j];
        }
    }

    // Call the function to print the matrix
    printMatrix(matrixData, rows, cols);

    // Free the dynamically allocated memory
    delete[] matrixData;

    return 0;
}
