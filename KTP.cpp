#include <iostream>
#include <string>
using namespace std;

class KTP {
private:
    string nama, tempat_l, alamat, agama, gender, status_p, pekerjaan, kewarganegaraan;
    int nik, tanggal_l, bulan_l, tahun_l, pil_agama;
    char jk;

    void pilih_jk() {
        cout << "Jenis Kelamin (L/P) : ";
        cin >> jk;

        if (jk == 'L' || jk == 'l') {
            gender = "Laki-Laki";
        } else if (jk == 'P' || jk == 'p') {
            gender = "Perempuan";
        } else {
            cout << "Input salah. Masukkan L atau P." << endl;
            pilih_jk();
        }
    }

    void pilih_agama() {
        cout << "Pilih Agama anda    :" << endl;
        cout << "1. Islam" << endl;
        cout << "2. Kristen" << endl;
        cout << "3. Katolik" << endl;
        cout << "4. Hindu" << endl;
        cout << "5. Buddha" << endl;
        cout << "6. Konghuchu" << endl;
        cout << "Pilihan (1-6): ";
        cin >> pil_agama;

        switch (pil_agama) {
            case 1: agama = "Islam"; break;
            case 2: agama = "Kristen"; break;
            case 3: agama = "Katolik"; break;
            case 4: agama = "Hindu"; break;
            case 5: agama = "Buddha"; break;
            case 6: agama = "Konghuchu"; break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
                pilih_agama();
                break;
        }
    }

public:
    void input() {
        cout << "     Input Data KTP     " << endl;
        cout << "________________________" << endl;
        cout << "Nama                : ";
        getline(cin, nama);
        cout << "NIK                 : ";
        cin >> nik;
        cin.ignore();
        cout << "Tempat Lahir        : ";
        getline(cin, tempat_l);
        cout << "Tanggal Lahir       : ";
        cin >> tanggal_l;
        cout << "Bulan Lahir         : ";
        cin >> bulan_l;
        cout << "Tahun Lahir         : ";
        cin >> tahun_l;
        pilih_jk();
        cin.ignore();
        cout << "Alamat              : ";
        getline(cin, alamat);
        pilih_agama();
        cin.ignore();
        cout << "Status Perkawinan   : ";
        getline(cin, status_p);
        cout << "Pekerjaan           : ";
        getline(cin, pekerjaan);
        cout << "Kewarganegaraan     : ";
        getline(cin, kewarganegaraan);
    }

    void tampil() {
    	cout<<endl;
        cout << "       Data KTP       " << endl;
        cout << "______________________" << endl;
        cout << "Nama                  : " << nama << endl;
        cout << "NIK                   : " << nik << endl;
        cout << "Tempat, Tanggal Lahir : " << tempat_l << ", " << tanggal_l << "-" << bulan_l << "-" << tahun_l << endl;
        cout << "Jenis Kelamin         : " << gender << endl;
        cout << "Alamat                : " << alamat << endl;
        cout << "Agama                 : " << agama << endl;
        cout << "Status Perkawinan     : " << status_p << endl;
        cout << "Pekerjaan             : " << pekerjaan << endl;
        cout << "Kewarganegaraan       : " << kewarganegaraan << endl;
    }
};

int main() {
    KTP orang;
    orang.input();
    system("pause");
    system("cls");
    orang.tampil();

    return 0;
}

