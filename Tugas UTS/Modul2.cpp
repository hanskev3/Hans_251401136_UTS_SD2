#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    int skor;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void insertHead(const string& nama, int skor) {
    Node* newNode = new Node{nama, skor, head};
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
}

void insertTail(const string& nama, int skor) {
    Node* newNode = new Node{nama, skor, nullptr};
    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
}

void deleteHead() {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr) {
        tail = nullptr;
    }
}

void displayLolos() {
    cout << "Daftar Peserta Lolos (Skor >= 75):\n";
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        if (cur->skor >= 75) {
            cout << "- " << cur->nama << " (Skor: " << cur->skor << ")\n";
        }
    }
}

int main() {
    int menu;
    string nama;
    int skor;


    while (cin >> menu && menu != 0) {
        if (menu == 1 || menu == 2) {
            cin.ignore();
            getline(cin, nama);
            cin >> skor;
            if (menu == 1) insertHead(nama, skor);
            else insertTail(nama, skor);
        } else if (menu == 3) {
            deleteHead();
        } else if (menu == 4) {
            displayLolos();
        }
    }

    while (head != nullptr) {
        deleteHead();
    }
    return 0;
}












