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

void cekKesehatan(Tanaman &t) {
    t.kesehatan = (t.kelembaban < 30 ? "Butuh penyiraman" : 
                   t.kelembaban < 60 ? "Normal" : "Tidak perlu disiram");
    t.kesehatan += (t.cahaya < 30 ? ", butuh cahaya" : 
                    t.cahaya > 70 ? ", terlalu banyak cahaya" : ", cukup cahaya");
}

void tambahTanaman(queue<Tanaman> &tanamanQueue) {
    Tanaman t;
    cin.ignore();
    cout << "Nama: "; getline(cin, t.nama);
    cout << "Kelembaban (0-100): "; cin >> t.kelembaban;
    cout << "Cahaya (0-100): "; cin >> t.cahaya;
    cekKesehatan(t);
    tanamanQueue.push(t);
    cout << "Tanaman berhasil ditambahkan!\n";
}

void tampilkanTanaman(queue<Tanaman> tanamanQueue) {
    if (tanamanQueue.empty()) {
        cout << "Tidak ada tanaman.\n";
        return;
    }
    while (!tanamanQueue.empty()) {
        Tanaman t = tanamanQueue.front();
        tanamanQueue.pop();
        cout << "Nama: " << t.nama << endl;
		cout << "Kelembaban: " << t.kelembaban << "%" << endl;
        cout << "Cahaya: " << t.cahaya << "%" << endl; 
		cout << "Kesehatan: " << t.kesehatan << endl;
    }
}

void hapusTanaman(queue<Tanaman> &tanamanQueue) {
    if (tanamanQueue.empty()) {
        cout << "Tidak ada tanaman untuk dihapus.\n";
        return;
    }
    string nama;
    cin.ignore();
    cout << "Nama tanaman yang akan dihapus: ";
    getline(cin, nama);

    queue<Tanaman> tempQueue;
    bool ditemukan = false;

    while (!tanamanQueue.empty()) {
        Tanaman t = tanamanQueue.front();
        tanamanQueue.pop();
        if (t.nama == nama) {
            ditemukan = true;
            cout << "Tanaman " << nama << " berhasil dihapus.\n";
        } else {
            tempQueue.push(t);
        }
    }
    tanamanQueue = tempQueue;

    if (!ditemukan) {
        cout << "Tanaman tidak ditemukan.\n";
    }
}

void editTanaman(queue<Tanaman> &tanamanQueue) {
    if (tanamanQueue.empty()) {
        cout << "Tidak ada tanaman untuk diedit.\n";
        return;
    }
    string nama;
    cin.ignore();
    cout << "Nama tanaman yang akan diedit: ";
    getline(cin, nama);

    queue<Tanaman> tempQueue;
    bool ditemukan = false;

    while (!tanamanQueue.empty()) {
        Tanaman t = tanamanQueue.front();
        tanamanQueue.pop();
        if (t.nama == nama) {
            cout << "Kelembaban baru (0-100): "; cin >> t.kelembaban;
            cout << "Cahaya baru (0-100): "; cin >> t.cahaya;
            cekKesehatan(t);
            ditemukan = true;
        }
        tempQueue.push(t);
    }
    tanamanQueue = tempQueue;

    if (!ditemukan) {
        cout << "Tanaman tidak ditemukan.\n";
    }
}

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
        cout << "\n1. Tambah Tanaman\n2. Tampilkan Tanaman\n3. Hapus Tanaman\n4. Edit Tanaman\n5. Cari Tanaman\n6. Keluar\nPilihan: ";
        cin >> pilihan;
        
         switch (pilihan) {
            case 1: tambahTanaman(tanamanQueue); break;
            case 2: tampilkanTanaman(tanamanQueue); break;
            case 3: hapusTanaman(tanamanQueue); break;
            case 4: editTanaman(tanamanQueue); break;
            case 5: cariTanaman(tanamanQueue); break;
            case 6: cout << "Keluar dari program." << endl; break;
            default: cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 6);

    return 0;
}