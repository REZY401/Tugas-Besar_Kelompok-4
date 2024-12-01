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

void tampilkanTanaman (queue<Tanaman> tanamanQueue){
	if (tanamanQueue.empty()){
		cout << "Tidak ada tanaman. \n";
		return;
	}
	while (!tanamanQueue.empty()){
		Tanaman t = tanamanQueue.front();
		tanamanQueue.pop();
		cout << "Nama: " << t.nama << endl;
		cout << "Kelembapan: " << t.kelembaban << "%" << endl;
		cout << "Cahaya: " << t.cahaya << "%" << endl;
		cout << "Kesehatan: " << t.kesehatan << endl;
	}
}

int main(){
	queue<Tanaman> tanamanQueue;
	int pilihan;
	
	do{
	cout << "Fitur Menampilkan Tanaman yang Telah ditambahkan" << endl;
	cout << "1. Tambahkan Tanaman" << endl;
	cout << "2. Tampilkan Tanaman" << endl;
	cout << "3. Keluar" << endl;
	cout << "Pilih [1..3]: "; cin >> pilihan;
	
	switch (pilihan){
		case 1: tambahTanaman(tanamanQueue);
		break;
		case 2: tampilkanTanaman(tanamanQueue);
		break;
		case 3: cout << "Selesai";
		default: cout << "Ga ada pilihan, try again";
	}
	}while (pilihan !=3);
	
	return 0;
}