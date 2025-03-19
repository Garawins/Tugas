#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;

struct playlist
{
    char judul[100];
    char penyanyi[100];
    char genre[50];
    int tahun;
};

playlist lagu[100];

void bubbleSort(playlist lagu[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strncmp(lagu[j].judul, lagu[j + 1].judul, 100) > 0)
            {
                playlist temp = lagu[j];
                lagu[j] = lagu[j + 1];
                lagu[j + 1] = temp;
            }
        }
    }
}

int main()
{
    char pilihan;
    int n = 0;
    FILE *filelagu;
    bool ditemukan;

    do
    {
        system("cls");
        int menu;
        cout << "Playlist Lagu" << endl;
        cout << setfill('=') << setw(15) << "=" << endl;
        cout << "1. Tambah lagu" << endl;
        cout << "2. Edit lagu" << endl;
        cout << "3. Tampilkan lagu" << endl;
        cout << "4. Cari lagu" << endl;
        cout << "5. Keluar program" << endl;
        cout << "Pilih Menu: ";
        cin >> menu;
        cin.ignore();

        if (menu < 1 || menu > 5)
        {
            cout << "Input tidak valid!\n";
            continue;
        }

        if (menu == 1)
        {
            system("cls");
            filelagu = fopen("playlistlagu.dat", "wb");
            if (filelagu == NULL)
            {
                cout << "Gagal membuka file!\n"; 
                break;
            }

            cout << "Masukkan jumlah lagu yang ingin diinput: ";
            cin >> n;
            cin.ignore();

            for (int i = 0; i < n; i++)
            {
                cout << "Lagu ke-" << i + 1 << ":" << endl;
                cout << "Judul: ";
                cin.getline(lagu[i].judul, 100);
                cout << "Penyanyi: ";
                cin.getline(lagu[i].penyanyi, 100);
                cout << "Genre: ";
                cin.getline(lagu[i].genre, 50);
                cout << "Tahun rilis: ";
                cin >> lagu[i].tahun;
                cin.ignore();

                fprintf(filelagu, "%s|%s|%s|%d\n", lagu[i].judul, lagu[i].penyanyi, lagu[i].genre, lagu[i].tahun);
            }

            fclose(filelagu);
            cout << "Lagu berhasil ditambahkan!\n";
        }

        else if (menu == 2)
        {
            system("cls");
            filelagu = fopen("playlistlagu.txt", "r");
            if (filelagu == NULL)
            {
                cout << "Belum ada lagu dalam daftar!\n";
                break;
            }

            while (fscanf(filelagu, "%[^|]|%[^|]|%[^|]|%[^|]|%d\n", lagu[n].judul, lagu[n].penyanyi, lagu[n].genre, &lagu[n].tahun) == 5)
            {
                n++;
            }

            fclose(filelagu);

            char editJudul[100];
            cout << "Masukkan judul lagu yang ingin diedit: ";
            cin.getline(editJudul, 100);

            ditemukan = false;

            for (int i = 0; i < n; i++)
            {
                if (strncmp(lagu[i].judul, editJudul, 100) == 0)
                {
                    cout << "Masukkan data baru:" << endl;
                    cout << "Judul: ";
                    cin.getline(lagu[i].judul, 100);
                    cout << "Penyanyi: ";
                    cin.getline(lagu[i].penyanyi, 100);
                    cout << "Genre: ";
                    cin.getline(lagu[i].genre, 50);
                    cout << "Tahun rilis: ";
                    cin >> lagu[i].tahun;
                    cin.ignore();
                    ditemukan = true;
                }
            }

            if (!ditemukan)
            {
                cout << "Lagu tidak ditemukan!" << endl;
                break;
            }

            filelagu = fopen("playlistlagu.txt", "w");
            for (int i = 0; i < n; i++)
            {
                fprintf(filelagu, "%s|%s|%s|%s|%d\n", lagu[i].judul, lagu[i].penyanyi, lagu[i].genre, lagu[i].tahun);
            }
            fclose(filelagu);
            cout << "Data lagu berhasil diperbarui!\n";
        }



        else if (menu == 3)
        {
            system("cls");
            filelagu = fopen("playlistlagu.txt", "r");
            if (filelagu == NULL)
            {
                cout << "Belum ada lagu dalam daftar!\n";
                break;
            }

            n = 0;
            while (fscanf(filelagu, "%[^|]|%[^|]|%[^|]|%[^|]|%d\n", lagu[n].judul, lagu[n].penyanyi, lagu[n].genre, &lagu[n].tahun) == 5)
            {
                n++;
            }

            fclose(filelagu);

            if (n == 0)
            {
                cout << "Tidak ada lagu dalam daftar!" << endl;
                break;
            }

            bubbleSort(lagu, n);
            cout << "Daftar lagu setelah diurutkan berdasarkan judul:" << endl;
            cout << "------------------------------------" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "Judul lagu: " << lagu[i].judul << endl;
                cout << "Nama Penyanyi: " << lagu[i].penyanyi << endl;
                cout << "Genre Lagu: " << lagu[i].genre << endl;
                cout << "Tahun rilis: " << lagu[i].tahun << endl;
                cout << "------------------------------------" << endl;
            }
        }


        else if (menu == 4)
        {
            system("cls");
            filelagu = fopen("playlistlagu.txt", "r");
            if (filelagu == NULL)
            {
                cout << "Belum ada lagu dalam daftar!\n";
                break;
            }

            n = 0;
            while (fscanf(filelagu, "%[^|]|%[^|]|%[^|]|%[^|]|%d\n", lagu[n].judul, lagu[n].penyanyi, lagu[n].genre, &lagu[n].tahun) == 5)
            {
                n++;
            }

            fclose(filelagu);

            if (n == 0)
            {
                cout << "Tidak ada lagu dalam daftar!" << endl;
                break;
            }

            char cariJudul[100];
            cout << "Masukkan judul lagu yang ingin dicari: ";
            cin.getline(cariJudul, 100);

            ditemukan = false;

            cout << "Hasil Pencarian:" << endl;
            cout << "------------------------------------" << endl;
            for (int i = 0; i < n; i++)
            {
                if (strncmp(lagu[i].judul, cariJudul, 100) == 0)
                {
                    cout << "Judul lagu: " << lagu[i].judul << endl;
                    cout << "Nama Penyanyi: " << lagu[i].penyanyi << endl;
                    cout << "Genre lagu: " << lagu[i].genre << endl;
                    cout << "Tahun rilis: " << lagu[i].tahun << endl;
                    cout << "------------------------------------" << endl;
                    ditemukan = true;
                }
            }
            if (!ditemukan)
            {
                cout << "Lagu dengan judul \"" << cariJudul << "\" tidak ditemukan!" << endl;
            }
        }

        else if (menu == 5)
        {
            cout << "Program telah keluar. Terima kasih!" << endl;
            return 0;
        }

        cout << "Apakah ingin kembali ke menu utama? (y/n): ";
        cin >> pilihan;
        cin.ignore();
    } while (pilihan == 'Y' || pilihan == 'y');

    return 0;
}
