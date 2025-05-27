#include<iostream>
using namespace std;

int main(){
	string ussername, password;
	cout<<"Masukkan Nama :"; cin>>ussername;
	cout<<"Masukkan Password : "; cin>>password;
	if(ussername == "admin" && password == "185"){
		cout<<"BERHASIL LOGIN";
	}else{
		cout<<"GAGAL LOGIN";
	}
	cout<<endl;

	system("pause");
	
	int total, barang, harga, diskon, pilihBarang;
	do{
	cout<<"\n------PILIH BARANG------"<<endl;
	cout<<"1. Beras 1kg = 14000\n"; 
	cout<<"2. Tepung 1kg = 12000\n";
	cout<<"3. KELUAR\n";
	cout<<"pilih barang yang akan anda beli (1-3) :"; cin>>pilihBarang;
	cout<<endl;

		switch(pilihBarang){
		case 1:
			cout<<"Harga Barang = ";
			cout<<14000<<endl; cin>>harga;
		break;
		case 2:
			cout<<"Harga Barang = ";	
			cout<<12000<<endl; cin>>harga;
		break;
	}
	system("pause");
	/*cout<<"Total Harga Belanja : "<<total<<endl;
	total = pilihBarang + harga;
	diskon = total - 0.15;
	cout<<"Diskon Belanja 15% : "; cin>>diskon;
	}*/
	
	}while(pilihBarang!=3);
	system("cls");
	cout<<"TERIMAKASIH/ARIGATOU"<<endl;
	return 0;
}
