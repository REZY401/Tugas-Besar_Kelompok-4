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
    if (t.kelembaban < 30) {
        t.kesehatan = "Butuh penyiraman segera";
    } else if (t.kelembaban < 60) {
        t.kesehatan = "Kondisi normal";
    } else {
        t.kesehatan = "Tidak perlu disiram";
    }

    if (t.cahaya < 30) {
        t.kesehatan += " dan butuh lebih banyak cahaya";
    } else if (t.cahaya > 70) {
        t.kesehatan += " dan terlalu banyak cahaya";
    } else {
        t.kesehatan += " dan mendapat cukup cahaya";
    }

    if (t.kelembaban < 10) {
        t.kesehatan += " (PERINGATAN: Kelembapan sangat rendah!)";
    }
    if (t.cahaya > 90) {
        t.kesehatan += " (PERINGATAN: Cahaya terlalu intens!)";
    }else if(t.cahaya < 5){
    	t.kesehatan += " (PERINGATAN: Cahaya terlalu rendah!)";
	}
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
    	cout << "\n====Sisem pengelolaan kesehatan tanaman====";
        cout << "\n1. Tambah Tanaman\n2. Tampilkan Tanaman\n3. Hapus Tanaman\n4. Edit Tanaman\n5. Cari Tanaman\n6. Keluar\n";
        cout << "Pilihan: ";
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