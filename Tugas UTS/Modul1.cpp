#include <iostream>
using namespace std;

int main() {
    int arr[2][3][4];
    int sum[3][4] = {0};

    // Mengisi lapis pertama
    int even = 2;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            arr[0][i][j] = even;
            even += 2;
        }
    }

    // Mengisi lapis kedua
    int odd = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            arr[1][i][j] = odd;
            odd += 2;
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            sum[i][j] = arr[0][i][j] + arr[1][i][j];
        }
    }

    // Menampilkan hasil penjumlahan dalam tabel
    cout << "Hasil Penjumlahan Lapis 1 (Genap) dan Lapis 2 (Ganjil):\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << sum[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}