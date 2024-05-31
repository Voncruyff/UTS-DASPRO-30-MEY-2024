#include <iostream>
using namespace std;

// deklarasi double linked list
struct DataUser {
    string nama, prodi;
    DataUser *prev;
    DataUser *next;
};

DataUser *kepala, *ekor, *cur, *nodeBaru, *del, *afterNode;

// Create Double Linked List
void createDoubleLinkedList(string data[4]) {
    kepala = new DataUser();
    kepala->nama = data[0];
    kepala->prodi = data[1];
    kepala->prev = NULL;
    kepala->next = NULL;
    ekor = kepala;
}

// Count Double Linked List
int countDoubleLinkedList() {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    } else {
        cur = kepala;
        int jumlah = 0;
        while (cur != NULL) {
            jumlah++;
            //step
            cur = cur->next;
        }
        return jumlah;
    }
}

// Add First
void addFirst(string data[4]) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    } else {
        nodeBaru = new DataUser();
        nodeBaru->nama = data[0];
        nodeBaru->prodi = data[1];
        nodeBaru->prev = NULL;
        nodeBaru->next = kepala;
        nodeBaru->prev = nodeBaru;
        nodeBaru = nodeBaru;
    }
}

// Add Last
void addLast(string data[4]) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    } else {
        nodeBaru = new DataUser();
        nodeBaru->nama = data[0];
        nodeBaru->prodi = data[1];
        nodeBaru->prev = ekor;
        nodeBaru->next = NULL;
        ekor->next = nodeBaru;
        ekor = nodeBaru;
    }
}

// Add Middle
void addMiddle(string data[4], int posisi) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    } else {
        if (posisi == 1) {
            cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
        } else if (posisi < 1 || posisi > countDoubleLinkedList()) {
            cout << "Posisi diluar jangkauan!!!" << endl;
        } else {
            nodeBaru = new DataUser();
            nodeBaru->nama = data[0];
            nodeBaru->prodi = data[1];

            // tranversing
            cur = kepala;
            int nomor = 1;
            while (nomor < posisi - 1) {
                cur = cur->next;
                nomor++;
            }

            afterNode = cur->next;
            nodeBaru->prev = cur;
            nodeBaru->next = afterNode;
            cur->next = nodeBaru;
            afterNode->prev = nodeBaru;
        }
    }
}

// Remove by Data
void removeByData(string searchData) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!" << endl;
    } else {
        cur = kepala;
        while (cur != NULL) {
            if (cur->nama == searchData || cur->prodi == searchData) {
                // Remove first node
                if (cur == kepala) {
                    kepala = kepala->next;
                    kepala->prev = NULL;
                    delete cur;
                }
                // Remove last node
                else if (cur == ekor) {
                    ekor = ekor->prev;
                    ekor->next = NULL;
                    delete cur;
                }
                // Remove middle node
                else {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                    delete cur;
                }
                cout << "Data " << searchData << " berhasil dihapus!" << endl;
                return;
            }
            cur = cur->next;
        }
        cout << "Data " << searchData << " tidak ditemukan!" << endl;
    }
}

// Print Double Linked List
void printDoubleLinkedList() {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!" << endl;
    } else {
        cout << "Jumlah Data : " << countDoubleLinkedList() << endl;
        cout << "Isi Data : " << endl;
        cur = kepala;
        while (cur != NULL) {
            // print
            cout << "Nama : " << cur->nama << endl;
            cout << "Prodi : " << cur->prodi << "\n" << endl;
            //step
            cur = cur->next;
        }
    }
}

int main() {
    string newData[4] = {"Michael Jordan", "Informatika"};
    createDoubleLinkedList(newData);

   // printDoubleLinkedList();

    string data2[4] = {"Asep PPP", "Elektro"};
    addFirst(data2);

    printDoubleLinkedList();

    string data3[4] = {"Ucup prasetyo", "Informatika"};
    addLast(data3);

  //  printDoubleLinkedList();

    string data4[4] = {"Tinky Winky", "Manajemen"};
    addMiddle(data4, 3);

    printDoubleLinkedList();

    removeByData("Asep ppp");

    printDoubleLinkedList();

  //  removeByData("Tinky Winky");

   // printDoubleLinkedList();

  //  removeByData("Ucup prasetyo");

  //  printDoubleLinkedList();

    return 0;
}