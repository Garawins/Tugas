#include <iostream>
#include <string>
using namespace std;

// Struktur data untuk menyimpan informasi buku
struct NodeBuku {
    string namaBuku;
    string namaPenulis;
    NodeBuku* sebelumnya;
    NodeBuku* berikutnya;
};

NodeBuku* awal = nullptr;
NodeBuku* akhir = nullptr;

// Fungsi untuk menambahkan buku di awal list
void tambahAwal(const string& namaBuku, const string& namaPenulis) {
    NodeBuku* baru = new NodeBuku{namaBuku, namaPenulis, nullptr, awal};
    if (awal != nullptr) {
        awal->sebelumnya = baru;
    } else {
        akhir = baru;
    }
    awal = baru;
    cout << "Buku berhasil ditambahkan di bagian awal.\n";
}

// Fungsi untuk menambahkan buku di akhir list
void tambahAkhir(const string& namaBuku, const string& namaPenulis) {
    NodeBuku* baru = new NodeBuku{namaBuku, namaPenulis, akhir, nullptr};
    if (akhir != nullptr) {
        akhir->berikutnya = baru;
    } else {
        awal = baru;
    }
    akhir = baru;
    cout << "Buku berhasil ditambahkan di bagian akhir.\n";
}

// Menampilkan seluruh buku dalam list
void tampilkanDaftarBuku() {
    if (awal == nullptr) {
        cout << "Belum ada buku dalam daftar.\n";
        return;
    }
    cout << "\n=== Daftar Buku Saat Ini ===\n";
    NodeBuku* ptr = awal;
    int nomor = 1;
    while (ptr != nullptr) {
        cout << nomor++ << ". Judul: " << ptr->namaBuku << ", Penulis: " << ptr->namaPenulis << endl;
        ptr = ptr->berikutnya;
    }
}

// Menghapus buku berdasarkan judul
void hapusBerdasarkanJudul(const string& judulCari) {
    NodeBuku* ptr = awal;
    while (ptr != nullptr) {
        if (ptr->namaBuku == judulCari) {
            if (ptr->sebelumnya != nullptr) {
                ptr->sebelumnya->berikutnya = ptr->berikutnya;
            } else {
                awal = ptr->berikutnya;
            }

            if (ptr->berikutnya != nullptr) {
                ptr->berikutnya->sebelumnya = ptr->sebelumnya;
            } else {
                akhir = ptr->sebelumnya;
            }

            delete ptr;
            cout << "Buku dengan judul \"" << judulCari << "\" berhasil dihapus.\n";
            return;
        }
        ptr = ptr->berikutnya;
    }
    cout << "Buku dengan judul \"" << judulCari << "\" tidak ditemukan.\n";
}

// Fungsi utama untuk menjalankan menu aplikasi
void tampilkanMenu() {
    int pilihan;
    string judul, penulis;
    do {
        cout << "\n=== Menu Manajemen Buku ===\n";
        cout << "1. Tambahkan Buku di Awal\n";
        cout << "2. Tambahkan Buku di Akhir\n";
        cout << "3. Lihat Semua Buku\n";
        cout << "4. Hapus Buku (berdasarkan Judul)\n";
        cout << "0. Keluar dari Program\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                system("cls");
                cout << "Masukkan Judul Buku: ";
                getline(cin, judul);
                cout << "Masukkan Nama Penulis: ";
                getline(cin, penulis);
                tambahAwal(judul, penulis);
                break;
            case 2:
                system("cls");
                cout << "Masukkan Judul Buku: ";
                getline(cin, judul);
                cout << "Masukkan Nama Penulis: ";
                getline(cin, penulis);
                tambahAkhir(judul, penulis);
                break;
            case 3:
                system("cls");
                tampilkanDaftarBuku();
                break;
            case 4:
                cout << "Masukkan Judul Buku yang ingin dihapus: ";
                getline(cin, judul);
                hapusBerdasarkanJudul(judul);
                break;
            case 0:
                system("cls");
                cout << "Sampai jumpa! Terima kasih telah menggunakan program ini.\n";
                break;
            default:
                cout << "Pilihan tidak dikenali, silakan coba lagi.\n";
        }
    } while (pilihan != 0);
}

int main() {
    tampilkanMenu();
    return 0;
}
