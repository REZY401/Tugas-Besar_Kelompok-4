#include <iostream>
#include <queue>

using namespace std;

struct Tanaman{
	int kelembapan;
	int cahaya;
	string kesehatan;
	string nama;
};

void cekKesehatan(Tanaman &t){
	if (t.kelembapan <30) {
		t.kesehatan = "Butuh penyiraman segera";
	} else if (t.kelembapan < 60) {
		t.kesehatan = "Kondisi normal";
	} else {
		t.kesehatan = "Tidak perlu disiram";
	} 
	
	if (t.cahaya < 30) {
		t.kesehatan += "dan butuh lebih banyak cahaya";
	} else if (t.cahaya > 70) {
		t.kesehatan += "dan terlalu banyak cahaya";
	} else {
		t.kesehatan += "dan mendapat cukup cahaya";
	}
	
	if (t.kelembapan < 10) {
		t.kesehatan += "(PERINGATAN: Kelembapan sangat rendah!";
	} 
	if (t.cahaya > 90) {
		t.kesehatan += "(PERINGATAN: Cahaya terlalu intens!";
	} else if(t.cahaya < 5){
		t.kesehatan += "PERINGATAN: Cahaya terlalu rnedah!";
	}
}
void tambahTanaman(queue<Tanaman> &tanamanQueue) {
    Tanaman t;
    cin.ignore();
    cout << "Nama: "; getline(cin, t.nama);
    cout << "Kelembapan (0-100): "; cin >> t.kelembapan;
    cout << "Cahaya (0-100): "; cin >> t.cahaya;
    cekKesehatan(t);
    tanamanQueue.push(t);
    cout << "Tanaman berhasil ditambahkan!\n";
}

int main() {
    queue<Tanaman> tanamanQueue;
    int pilihan;

    do {
    	cout << "\n====Sisem pengelolaan kesehatan tanaman====";
        cout << "\n1. Tambah Tanaman\n2. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        
         switch (pilihan) {
            case 1: tambahTanaman(tanamanQueue); break;
            case 2: cout << "Keluar";break;
            default: cout << "Pilihan tidak ada"; break;
	}
	}while (pilihan !=2);
return 0;
}