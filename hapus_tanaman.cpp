#include <iostream>
#include <queue>
using namespace std;

struct Tanaman {
	string nama; 
	int kelembapan;
	int cahaya;
	string kesehatan;
};
 void hapustanaman(queue<Tanaman> &tanamanQueue){
 	if (tanamanQueue.empty()){
 		cout <<"tidak ada tanaman untuk dihapus.\n";
 		return; 
	 }
 	string nama;
 	cin.ignore();
 	cout <<"Nama tanaman yang akan dihapus :";
 	getline(cin,nama);
 	
	queue<Tanaman> tempQueue;
 	bool ditemukan = false;
 	
 	while (!tanamanQueue.empty()){
 		Tanaman t = tanamanQueue.front();
 		tanamanQueue.pop();
 		if(t.nama == nama){
 			ditemukan =true;
 			cout <<"Tanaman"<<nama<< "berhasil dihspus.\n";
 		}else{
 			tempQueue.push(t);
 	
		 }
	 }
	   tanamanQueue = tempQueue;
	   
	   if(!ditemukan){
	   	cout<<"tidak di temukan.\n";
	   }
  }
	   
int main(){
	queue<Tanaman> tanamanQueue;
	int pilihan;
	
	cout << "Fitur Hapus tanaman" << endl;
	cout << "1. Hapus Tanaman"<<endl;
	cout << "2. Keluar" << endl;
	cout << "Masukka Pilihan [1..2]: "; cin >> pilihan;
	
	switch (pilihan){
		case 1: hapustanaman(tanamanQueue);
		break;
		case 2: cout << "Keluar";
		break;
		default : cout << "Pilihan tidak ada";
		break;
	}
}
 
