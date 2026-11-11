// Gunakan data dari pertemuan 3, buat program menggunakan struktur stack untuk mengecek apakah sebuah kata merupakan Palindrom, katanya bisa apa saja, masukkan huruf ke dalam stack, keluarkan huruf satu per satu dari stack membentuk kata terbalik, bandingkan kata tersebut
// buat output masukkan kata, penegecekan:, kata dibalik, dan kesimpulan
// mana bagian kesimpulan: kok ga ada, dan setelah pengecekan, kata dibalik, kesimpulan, dan kata yang dimasukkan bisa huruf besar atau kecil, tapi pengecekan harus tidak sensitif terhadap huruf besar/kecil
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool isPalindrome(const string& str) {
    stack<char> charStack;
    for (char ch : str) {
        charStack.push(ch);
    }

    string reversedStr;
    while (!charStack.empty()) {
        reversedStr += charStack.top();
        charStack.pop();
    }

    return str == reversedStr;
}

int main() {
    string input;
    cout << "Masukkan kata: ";
    cin >> input;

    transform(input.begin(), input.end(), input.begin(), ::tolower);

    cout << "Pengecekan: " << input << endl;
    string reversedInput;
    stack<char> charStack;
    for (char ch : input) {
        charStack.push(ch);
    }
    while (!charStack.empty()) {
        reversedInput += charStack.top();
        charStack.pop();
    }
    cout << "Kata dibalik: " << reversedInput << endl;
    if (input == reversedInput) {
        cout << "KATA INI ADALAH PALINDROM" << endl;
    } else {
        cout << "BUKAN PALINDROM" << endl;
    }
    return 0;
}