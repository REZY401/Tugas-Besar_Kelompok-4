#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Struktur untuk menyimpan data tanaman
struct Tanaman {
    string nama;
    int kelembaban; // dalam persen
    int cahaya;     // dalam persen
    string kesehatan;
};

// Fungsi untuk memeriksa status kesehatan tanaman
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
    }
}

// Fungsi untuk menambah tanaman (enqueue)
void enqueueTanaman(queue<Tanaman> &tanamanQueue) {
    Tanaman t;

    cout << "\nMasukkan nama tanaman: ";
   cin.ignore(); // Menghapus buffer input
   getline(cin,t.nama);

    cout << "Masukkan kelembapan tanah (0-100): ";
    cin >> t.kelembaban;

    cout << "Masukkan intensitas cahaya (0-100): ";
    cin >> t.cahaya;

    cekKesehatan(t);

    tanamanQueue.push(t);

    cout << "Tanaman berhasil ditambahkan!\n";
}

// Fungsi untuk menampilkan catatan kesehatan tanaman
void tampilkanCatatanKesehatan(queue<Tanaman> &tanamanQueue) {
    if (tanamanQueue.empty()) {
        cout << "Tidak ada data tanaman untuk ditampilkan.\n";
        return;
    }

    cout << "\nCatatan Kesehatan Tanaman:\n";
    queue<Tanaman> tempQueue = tanamanQueue;  // Menyalin queue sementara
    while (!tempQueue.empty()) {
        Tanaman t = tempQueue.front();
        cout << "Tanaman: " << t.nama << endl;
        cout << "Kelembapan: " << t.kelembaban << "%" << endl;
        cout << "Cahaya: " << t.cahaya << "%" << endl;
        cout << "Status Kesehatan: " << t.kesehatan << endl;
        cout << "-----------------------------------" << endl;
        tempQueue.pop();  // Menghapus tanaman dari queue sementara
    }
}

// Fungsi untuk menghapus tanaman (dequeue)
void dequeueTanaman(queue<Tanaman> &tanamanQueue) {
    if (tanamanQueue.empty()) {
        cout << "Tidak ada tanaman dalam antrean untuk dihapus.\n";
        return;
    }

    Tanaman t = tanamanQueue.front();
    tanamanQueue.pop();
    cout << "Tanaman " << t.nama << " telah di hapus dari antrean.\n";
}

// Fungsi untuk menghapus tanaman berdasarkan nama
void hapusTanaman(queue<Tanaman> &tanamanQueue) {
    if (tanamanQueue.empty()) {
        cout << "Tidak ada data tanaman untuk dihapus.\n";
        return;
    }

    string namaTanaman;
    cout << "Masukkan nama tanaman yang ingin dihapus: ";
    cin.ignore(); // Menghapus buffer input
    getline(cin, namaTanaman);

    queue<Tanaman> tempQueue;
    bool ditemukan = false;

    // Menyalin tanaman ke queue sementara, kecuali yang akan dihapus
    while (!tanamanQueue.empty()) {
        Tanaman t = tanamanQueue.front();
        tanamanQueue.pop();

        if (t.nama == namaTanaman) {
            ditemukan = true;
            cout << "Tanaman " << namaTanaman << " berhasil dihapus.\n";
        } else {
            tempQueue.push(t);
        }
    } 

    // Menyalin kembali data yang tidak dihapus ke queue asli
    tanamanQueue = tempQueue;

    if (!ditemukan) {
        cout << "Tanaman dengan nama " << namaTanaman << " tidak ditemukan.\n";
    }
}

// Fungsi untuk mengedit tanaman
void editTanaman(queue<Tanaman> &tanamanQueue) {
    if (tanamanQueue.empty()) {
        cout << "Tidak ada data tanaman untuk diedit.\n";
        return;
    }

    string namaTanaman;
    cout << "Masukkan nama tanaman yang ingin diedit: ";
    cin.ignore();
    getline(cin, namaTanaman);

    queue<Tanaman> tempQueue;
    bool ditemukan = false;

    // Menyalin tanaman ke queue sementara dan mengedit jika ditemukan
    while (!tanamanQueue.empty()) {
        Tanaman t = tanamanQueue.front();
        tanamanQueue.pop();

        if (t.nama == namaTanaman) {
            cout << "Masukkan kelembapan baru (0-100): ";
            cin >> t.kelembaban;

            cout << "Masukkan intensitas cahaya baru (0-100): ";
            cin >> t.cahaya;

            cekKesehatan(t);
            ditemukan = true;
        }

        tempQueue.push(t);
    }

    // Menyalin kembali data yang telah diperbarui ke queue asli
    tanamanQueue = tempQueue;
    if (!ditemukan) {
        cout << "Tanaman tidak ditemukan.\n";
    }
}

// Fungsi untuk mencari tanaman
void cariTanaman(queue<Tanaman> &tanamanQueue) {
    if (tanamanQueue.empty()) {
        cout << "Tidak ada data tanaman untuk dicari.\n";
        return;
    }

    string namaTanaman;
    cout << "Masukkan nama tanaman yang ingin dicari: ";
    cin.ignore();
    getline(cin, namaTanaman);

    bool ditemukan = false;
    queue<Tanaman> tempQueue = tanamanQueue; // Menyalin queue sementara

    // Mencari tanaman dalam queue sementara
    while (!tempQueue.empty()) {
        Tanaman t = tempQueue.front();
        tempQueue.pop();

        if (t.nama == namaTanaman) {
            cout << "\nInformasi Tanaman:\n";
            cout << "Tanaman: " << t.nama << endl;
            cout << "Kelembapan: " << t.kelembaban << "%" << endl;
            cout << "Cahaya: " << t.cahaya << "%" << endl;
            cout << "Status Kesehatan: " << t.kesehatan << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Tanaman tidak ditemukan.\n";
    }
}

// Fungsi utama
int main() {
    queue<Tanaman> tanamanQueue;
    int pilihan;

    do {
        cout << "\n=== Sistem Pengelolaan Kesehatan Tanaman ===" << endl;
        cout << "1. Tambah Tanaman (Enqueue)" << endl;
        cout << "2. Tampilkan Catatan Kesehatan" << endl;
        cout << "3. Hapus Tanaman (Dequeue)" << endl;
        cout << "4. Edit Tanaman" << endl;
        cout << "5. Cari Tanaman" << endl;
        cout << "6. Keluar" << endl;

        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: enqueueTanaman(tanamanQueue); break;
            case 2: tampilkanCatatanKesehatan(tanamanQueue); break;
            case 3: hapusTanaman(tanamanQueue); break;
            case 4: editTanaman(tanamanQueue); break;
            case 5: cariTanaman(tanamanQueue); break;
            case 6: cout << "Keluar dari program." << endl; break;
            default: cout << "Pilihan tidak valid." << endl;
        }

    } while (pilihan != 6);

    return 0;
}
