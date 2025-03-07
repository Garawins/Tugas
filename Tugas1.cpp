#include <iostream>
using namespace std;

struct playlist
{
    string judul, artis, genre;
    int tahun;
};

void menu(playlist lagu[], int &n, int capacity)
{
    cout << "Playlist Lagu" << endl;
    cout << "=============" << endl;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if(lagu[j].judul > lagu[j + 1].judul)
            {
                swap(lagu[j], lagu[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". " << lagu[i].judul << " - " << lagu[i].artis << "\n";
    }
    cout << "\n";
    cout << "1. Tambah Lagu" << endl;
    cout << "2. Cari Lagu" << endl;
    cout << "3. Keluar" << endl;

}

main()
{
    int pilihan;
    int jumlah;
    int capacity = 11;
    playlist lagu[capacity];
    int n = 0;
    bool founded = false;
    string keyword;
    while (pilihan != 3)
    {
        menu(lagu, n, capacity);
        cout << "Pilih menu : ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            cout << "Masukan jumlah lagu yang ingin ditambahkan : ";
            cin >> jumlah;
            cin.ignore();
            cout << "\n";

            if (n + jumlah > capacity)
            {
                cout << "Jumlah lagu melebihi kapasitas. Maksimal lagu yang bisa ditambahkan : " << capacity - n << "\n\n";
                break;
            }
            for (int i = n; i < jumlah + n; i++)
            {
                cout << "Judul Lagu : ";
                getline(cin, lagu[i].judul);
                cout << "Artis : ";
                getline(cin, lagu[i].artis);
                cout << "Genre : ";
                getline(cin, lagu[i].genre);
                cout << "Tahun : ";
                cin >> lagu[i].tahun;
                cin.ignore();
                cout << "\n";
            }
            n += jumlah;
            cout << "\n";
            break;

        case 2:
            cout << "Masukan judul lagu yang ingin dicari : ";
            cin.ignore();
            getline(cin, keyword);

            for (int i = 0; i < n; i++)
            { 
                if (lagu[i].judul == keyword){

                    cout << "Lagu ditemukan!" << endl << endl;
                    cout << "Judul Lagu : " << lagu[i].judul << endl;
                    cout << "Artis : " << lagu[i].artis << endl;
                    cout << "Genre : " << lagu[i].genre << endl;
                    cout << "Tahun : " << lagu[i].tahun << endl;
                    cout << "\n\n";
                    founded = true;
                    break;
                }
            }
                if (!founded)
                {
                    cout << "\nLagu tidak ditemukan\n" << endl;
                }
            
            cout << "Kembali ke menu? (1. Ya / 2. Tidak) : \n";

            break;
        case 3:
            cout << "Keluar" << endl;
            break;
        default:
            cout << "\nMenu tidak tersedia\n" << endl;
            break;
        }
        system("cls");
    }
}
