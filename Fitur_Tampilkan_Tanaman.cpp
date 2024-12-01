#include <iostream>
#include <queue>
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
	cout << "\nFitur Menampilkan Tanaman yang Telah ditambahkan" << endl;
	cout << "1. Tampilkan Tanaman" << endl;
	cout << "2. Keluar" << endl;
	cout << "Pilih [1..2]: "; cin >> pilihan;
	
	switch (pilihan){
		case 1: tampilkanTanaman(tanamanQueue);
		break;
		case 2: cout << "Selesai";
		default: cout << "Ga ada pilihan, try again";
	}
	}while (pilihan !=2);
	
	return 0;
}