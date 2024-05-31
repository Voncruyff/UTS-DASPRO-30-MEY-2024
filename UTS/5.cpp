#include <iostream>
#include <string>
using namespace std;

// Deklarasi struktur untuk Circular Single Linked List
struct Mahasiswa {
    string npm, nama, jurusan;
    Mahasiswa* next;
};

Mahasiswa* kepala = nullptr, * ekor = nullptr, * nodeBaru = nullptr, * cur = nullptr, * del = nullptr;

// create Circular Single Linked List
void createCircularSingleLinkedList(string dataBaru[3]) {
    kepala = new Mahasiswa();
    kepala->npm = dataBaru[0];
    kepala->nama = dataBaru[1];
    kepala->jurusan = dataBaru[2];
    ekor = kepala;
    ekor->next = kepala;
}

// add first
void addFirst(string data[3]) {
    if (kepala == nullptr) {
        cout << "Buat Linked List dulu!!" << endl;
    }
    else {
        nodeBaru = new Mahasiswa();
        nodeBaru->npm = data[0];
        nodeBaru->nama = data[1];
        nodeBaru->jurusan = data[2];
        nodeBaru->next = kepala;
        ekor->next = nodeBaru;
        kepala = nodeBaru;
    }
}

// add Last
void addLast(string data[3]) {
    if (kepala == nullptr) {
        cout << "Buat Linked List dulu!!" << endl;
    }
    else {
        nodeBaru = new Mahasiswa();
        nodeBaru->npm = data[0];
        nodeBaru->nama = data[1];
        nodeBaru->jurusan = data[2];
        nodeBaru->next = kepala;
        ekor->next = nodeBaru;
        ekor = nodeBaru;
    }
}

// add Middle
void addMiddle(string data[3], int posisi) {
    if (kepala == nullptr) {
        cout << "Buat Linked List dulu!!" << endl;
    }
    else {
        if (posisi == 1) {
            cout << "Posisi satu bukan posisi tengah!!!" << endl;
        }
        else {
            nodeBaru = new Mahasiswa();
            nodeBaru->npm = data[0];
            nodeBaru->nama = data[1];
            nodeBaru->jurusan = data[2];

            // tranversing
            int nomor = 1;
            cur = kepala;
            while (nomor < posisi - 1) {
                cur = cur->next;
                nomor++;
            }
            nodeBaru->next = cur->next;
            cur->next = nodeBaru;
        }
    }
}

void printCircular() {
    if (kepala == nullptr) {
        cout << "Buat Linked List dulu!!" << endl;
    }
    else {
        cout << "Data Mahasiswa " << endl;
        cout << "_________________________________________________________________" << endl;
        cout << "| NPM\t\t| Nama\t\t\t| Jurusan\t\t|" << endl;
        cout << "_________________________________________________________________" << endl;
        cur = kepala;
        while (cur->next != kepala) {
            // print
            cout << "| " << cur->npm << "\t| " << cur->nama << "\t| " << cur->jurusan << "\t\t|" << endl;
            cur = cur->next;
        }
        cout << "| " << cur->npm << "\t| " << cur->nama << "\t| " << cur->jurusan << "\t\t|" << endl;
        cout << "_________________________________________________________________" << endl;
    }
}

int main() {
    string dataBaru[3] = { "199010", "Carles Puyol", "Hukum" };
    createCircularSingleLinkedList(dataBaru);

    printCircular();

    string data[3] = { "192002", "Gerard Pique", "Business" };
    addFirst(data);

    printCircular();

    string data2[3] = { "192003", "Max Verstapen", "F1" };
    addLast(data2);

    printCircular();

    string data3[3] = { "192000", "Ucup", "Teknik Elektro" };
    addMiddle(data3, 2);

    printCircular();

    return 0;
}