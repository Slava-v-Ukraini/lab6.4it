#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

// Функція для генерації динамічного масиву
void Create(double* a, const int size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 101 - 50;  // Генерація випадкових чисел в діапазоні [-50, 50]
    }
}

void Print(const double* a, const int size) {
    for (int i = 0; i < size; i++)
        cout << "a[" << setw(2) << i << " ] = " << setw(6) << a[i] << endl;
    cout << endl;
}

double Max(const double* const b, const int n) {
    double max = b[0];
    for (int i = 1; i < n; i++)
    {
        if (b[i] > max)
        {
            max = b[i];
        }
    }
    return max;
}

int LastPos(const double* const b, const int n) {
    for (int i = n - 1; i >= 0; i--)
    {
        if (b[i] > 0)
            return i;
    }
    return -1;
}


double SumBeforeLastPos(const double* const b, const int n) {
    int lastPos = LastPos(b, n);
    if (lastPos == -1) return 0;
    double sum = 0;
    for (int i = 0; i < lastPos; i++)
        sum += b[i];
    return sum;
}


int CompressArray(double* b, int& n, double lowerLimit, double upperLimit) {
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(b[i]) < lowerLimit || abs(b[i]) > upperLimit)
        {
            b[j] = b[i];
            j++;
        }
    }
    for (int i = j; i < n; i++)
    {
        b[i] = 0;
    }
    n = j;
}


int main() {
    srand(time(0));
    int n;
    double a, b;
    cout << "Enter the size of the array n = "; cin >> n;
    cout << "Enter the lower limit of the interval a = "; cin >> a;
    cout << "Enter the upper limit of the interval b = "; cin >> b;
    double* arr = new double[n];
    Create(arr, n);
    cout << "Initial array:" << endl;
    Print(arr, n);
    cout << "The maximum element of the array: " << Max(arr, n) << endl;
    cout << "The sum of the elements of the array up to the last positive: " << SumBeforeLastPos(arr, n) << endl;
    CompressArray(arr, n, a, b);
    cout << "Compressed array:" << endl;
    Print(arr, n);
    delete[] arr;
    arr = nullptr;
    return 0;
}

