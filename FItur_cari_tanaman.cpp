#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Tanaman {
    string nama;
    int kelembaban;
    int cahaya;
    string kesehatan;
};

    void cariTanaman(queue<Tanaman> &tanamanQueue) {
    if (tanamanQueue.empty()) {
        cout << "Tidak ada tanaman untuk dicari.\n";
        return;
    }
    string nama;
    cin.ignore();
    cout << "Nama tanaman yang dicari: ";
    getline(cin, nama);

    queue<Tanaman> tempQueue = tanamanQueue;
    bool ditemukan = false;

    while (!tempQueue.empty()) {
        Tanaman t = tempQueue.front();
        tempQueue.pop();
        if (t.nama == nama) {
            cout << "Nama: " << t.nama << endl;
			cout << "Kelembaban: " << t.kelembaban << "%" << endl;
        	cout << "Cahaya: " << t.cahaya << "%" << endl; 
			cout << "Kesehatan: " << t.kesehatan << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Tanaman tidak ditemukan.\n";
    }
}

int main() {
    queue<Tanaman> tanamanQueue;
    int pilihan;

    do {
    	cout << "\n====Sisem pengelolaan kesehatan tanaman====";
        cout << "\n1. Cari Tanaman\n2. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        
         switch (pilihan) {
            case 1: cariTanaman(tanamanQueue); break;
            case 2: cout << "Keluar dari program." << endl; break;
            default: cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 2);

    return 0;
}