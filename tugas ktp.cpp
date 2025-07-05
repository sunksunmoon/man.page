#include <iostream>
#include <string>
using namespace std;

class KTP {
private:
    long long int nik;
    int tanggal_l, bulan_l, tahun_l, pil_agama;
    string nama, tempat_l, alamat, agama, pekerjaan, kewarganegaraan, gender, rt, status_p, gol, desa, bh, kecamatan;
    char jk;

    void pilih_jk() {
        cout << "Jenis Kelamin (L/P) : ";
        cin >> jk;

        if (jk == 'L' || jk == 'l') {
            gender = "Laki-Laki";
        } else if (jk == 'P' || jk == 'p') {
            gender = "Perempuan";
        } else {
            cout << "Gagal. Tolong masukkan L atau P." << endl;
            pilih_jk();
        }
    }

    void pilih_agama() {
        cout << "Pilih Agama anda:\n";
        cout << "1. Islam\n2. Kristen\n3. Katolik\n4. Hindu\n5. Buddha\n6. Konghucu\n";
        cout << "Pilihan (1-6): ";
        cin >> pil_agama;

        switch (pil_agama) {
            case 1: agama = "Islam"; break;
            case 2: agama = "Kristen"; break;
            case 3: agama = "Katolik"; break;
            case 4: agama = "Hindu"; break;
            case 5: agama = "Buddha"; break;
            case 6: agama = "Konghucu"; break;
            default:
                cout << "Pilihan tidak valid. Ulangi.\n";
                pilih_agama();
        }
    }

public:
    void input() {
        cin.ignore();
        cout << "\nInput Data KTP\n=========================\n";
        cout << "Nama                : "; getline(cin, nama);
        cout << "NIK                 : "; cin >> nik; cin.ignore();
        cout << "Tempat Lahir        : "; getline(cin, tempat_l);
        cout << "Tanggal Lahir       : "; cin >> tanggal_l;
        cout << "Bulan Lahir         : "; cin >> bulan_l;
        cout << "Tahun Lahir         : "; cin >> tahun_l;
        pilih_jk(); cin.ignore();
        cout << "Golongan Darah      : "; getline(cin, gol);
        cout << "Alamat              : "; getline(cin, alamat);
        cout << "RT/RW               : "; getline(cin, rt);
        cout << "Kel/Desa            : "; getline(cin, desa);
        cout << "Kecamatan           : "; getline(cin, kecamatan);
        pilih_agama(); cin.ignore();
        cout << "Status Perkawinan   : "; getline(cin, status_p);
        cout << "Pekerjaan           : "; getline(cin, pekerjaan);
        cout << "Kewarganegaraan     : "; getline(cin, kewarganegaraan);
        cout << "Berlaku Hingga      : "; getline(cin, bh);
    }

    void tampil() {
        cout << "\n+=========================================================+\n";
        cout << "|            KARTU TANDA PENDUDUK (KTP) ELEKTRONIK        |\n";
        cout << "+=========================================================+\n";
        cout << "| NIK                 : " << nik << endl;
        cout << "| Nama                : " << nama << endl;
        cout << "| Tempat/Tgl Lahir    : " << tempat_l << ", " << tanggal_l << "-" << bulan_l << "-" << tahun_l << endl;
        cout << "| Jenis Kelamin       : " << gender << "     Gol. Darah : " << gol << endl;
        cout << "| Alamat              : " << alamat << endl;
        cout << "|    RT/RW            : " << rt << endl;
        cout << "|    Kel/Desa         : " << desa << endl;
        cout << "|    Kecamatan        : " << kecamatan << endl;
        cout << "| Agama               : " << agama << endl;
        cout << "| Status Perkawinan   : " << status_p << endl;
        cout << "| Pekerjaan           : " << pekerjaan << endl;
        cout << "| Kewarganegaraan     : " << kewarganegaraan << endl;
        cout << "| Berlaku Hingga      : " << bh << endl;
        cout << "+=========================================================+\n";
    }

    string get_nama() const { return nama; }
};

// Sorting dengan pointer
void sort_ktp(KTP* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->get_nama() > (arr + j + 1)->get_nama()) {
                KTP temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

// Pencarian rekursif dengan pointer
int cari_nama_rekursif(KTP* arr, int kiri, int kanan, string target) {
    if (kiri > kanan) return -1;
    int tengah = (kiri + kanan) / 2;
    if ((arr + tengah)->get_nama() == target)
        return tengah;
    else if ((arr + tengah)->get_nama() > target)
        return cari_nama_rekursif(arr, kiri, tengah - 1, target);
    else
        return cari_nama_rekursif(arr, tengah + 1, kanan, target);
}

int main() {
    int jumlah;
    cout << "Masukkan jumlah data KTP yang ingin diinput: ";
    cin >> jumlah;

    // Alokasi dinamis pointer ke array KTP
    KTP* data = new KTP[jumlah];

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData ke-" << (i + 1) << endl;
        (data + i)->input();  // akses via pointer
    }

    sort_ktp(data, jumlah);

    system("cls");
    cout << "\nData setelah diurutkan berdasarkan nama:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "\nData ke-" << (i + 1) << endl;
        (data + i)->tampil();  // akses via pointer
    }

    cin.ignore();
    string dicari;
    cout << "\nMasukkan nama yang ingin dicari: ";
    getline(cin, dicari);

    int posisi = cari_nama_rekursif(data, 0, jumlah - 1, dicari);
    if (posisi != -1) {
        cout << "\nData ditemukan pada indeks ke-" << posisi << ":\n";
        (data + posisi)->tampil();  // akses via pointer
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    delete[] data;
    return 0;
}
