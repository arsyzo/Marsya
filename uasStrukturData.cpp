#include <iostream>
#include <string>
using namespace std;

// Struct untuk menyimpan informasi tentang paket perjalanan
struct datatrip
{
    string nama;
    string deskripsi;
    int harga;
};

// Struct untuk menyimpan informasi tentang jenis perjalanan
struct jenistrip
{
    string nama;
    datatrip paket[3]; // Array untuk menyimpan tiga paket perjalanan
} jenisTrip[100];

// Struct untuk menyimpan informasi tentang tanggal
struct tanggal
{
    int hari;
    int bulan;
    int tahun;
};

// Struct untuk menyimpan data pembeli
struct pembeli
{
    string nama;
    string paketTrip;
    int jumlahOrang;
    tanggal tgl;
    int harga;
    int uangDibayar;
    int kembalian;
};

struct LogNode
{
    string action;
    LogNode *next;
};

LogNode *logHead = nullptr;

// Array untuk menyimpan tanggal yang telah diatur
tanggal tidakTersediaTanggal[10];
int jumlahTanggal = 0;

// Array untuk menyimpan riwayat pembeli
pembeli riwayatPembeli[100];
int jumlahPembeli = 0;


void declareTrip()
{
    jenisTrip[0].nama = "Malang Trip";
    jenisTrip[0].paket[0] = {"Paket 1 Hari", "Makan 2x, Gunung Batok, Widodaren Hill, Sunrise Bromo", 275000};
    jenisTrip[0].paket[1] = {"Paket 2 Hari", "Makan 5x, Gunung Batok, Widodaren Hill, Sunrise Bromo, Pura Luhur, Kawah Bromo", 550000};
    jenisTrip[0].paket[2] = {"Paket 3 Hari", "Makan 8x, Gunung Batok, Widodaren Hill, Sunrise Bromo, Pura Luhur, Kawah Bromo, Pasir Berbisik, Padang Savanah", 750000};
    jenisTrip[1].nama = "Jakarta Trip";
    jenisTrip[1].paket[0] = {"Paket 1 Hari", "Makan 2x, Dufan, Jakarta Aquarium, TMII", 225000};
    jenisTrip[1].paket[1] = {"Paket 2 Hari", "Makan 5x, Dufan, Jakarta Aquarium, TMII, Playtopia Gandaria, Museum Macan", 400000};
    jenisTrip[1].paket[2] = {"Paket 3 Hari", "Makan 8x, Dufan, Jakarta Aquarium, TMII, Playtopia Gandaria, Museum Macan, Kep. Seribu, Playtopia PIK", 575000};
    jenisTrip[2].nama = "Bandung Trip";
    jenisTrip[2].paket[0] = {"Paket 1 Hari,", "Makan 2x, Lembang Park, Jl Braga, Rainbow Slide", 215000};
    jenisTrip[2].paket[1] = {"Paket 2 Hari,", "Makan 5x, Lembang Park, Jl Braga, Rainbow Slide, Forest Walk, Hutan Pinus", 350000};
    jenisTrip[2].paket[2] = {"Paket 3 Hari,", "Makan 8x, Lembang Park, Jl Braga, Rainbow Slide, Forest Walk, Hutan Pinus, Kaawah Rengginas, The Lodge Maribaya", 485000};
}

void tampilkanMenu()
{
    std::cout << "\n\nSelamat Datang di Layanan Pemesanan Trip\n";
    std::cout << "=============================================\n";
    std::cout << "1. Pesan Trip\n";
    std::cout << "2. Ubah Data Pesanan\n";
    std::cout << "3. Data Trip\n";
    std::cout << "4. Daftar Pesanan\n";
    std::cout << "5. Log sistem\n";
    std::cout << "\n0. Keluar\n";
    std::cout << "Pilih opsi (1/2/3/0): ";
}

void tampilkanDataTrip()
{
    std::cout << "\n\nPilih Paket Perjalanan:\n";
    std::cout << "=============================================\n";
    std::cout << "1. Tambah Data Trip\n";
    std::cout << "2. Ubah Data Trip\n";
    std::cout << "3. Hapus Data Trip\n";
    std::cout << "\n0. Kembali\n";
    std::cout << "Pilih opsi (1/2/3/0): ";
}

int dapatPanjangJenisTrip()
{
    int y = 0;
    for (int i = 0; i < sizeof(jenisTrip) / sizeof(jenisTrip[0]); i++)
    {
        if (jenisTrip[i].nama != "")
        {
            y++;
        }
    }
    return y;
}

void tampilkanJenisTrip()
{
    std::cout << "\n\nPilih Jenis Trip:\n";
    std::cout << "=============================================\n";
    for (int i = 0; i < dapatPanjangJenisTrip(); i++)
    {
        std::cout << i + 1 << ". " << jenisTrip[i].nama << endl;
    }
    std::cout << "\n0. Kembali\n";
    std::cout << "Pilih opsi (";
    for (int i = 0; i < dapatPanjangJenisTrip(); i++)
    {
        std::cout << i + 1 << "/";
    }
    std::cout << "0) : ";
}

void tampilkanPaketTrip(int index)
{
    std::cout << "\n\nPilih Paket Perjalanan:\n";
    std::cout << "=============================================\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << jenisTrip[index].paket[i].nama << ": " << jenisTrip[index].paket[i].deskripsi << std::endl;
    }
    std::cout << "=============================================\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << i + 1 << ". " << jenisTrip[index].paket[i].nama << " " << jenisTrip[index].paket[i].harga << std::endl;
    }
    std::cout << "\nPilih opsi (1/2/3): ";
}


void tampilkanNamaBulan()
{
    std::cout << "\n\nPilih Bulan Perjalanan:\n";
    std::cout << "=============================================\n";
    std::cout << "1. Januari\n";
    std::cout << "2. Februari\n";
    std::cout << "3. Maret\n";
    std::cout << "4. April\n";
    std::cout << "5. Mei\n";
    std::cout << "6. Juni\n";
    std::cout << "7. Juli\n";
    std::cout << "8. Agustus\n";
    std::cout << "9. September\n";
    std::cout << "10. Oktober\n";
    std::cout << "11. November\n";
    std::cout << "12. Desember\n";
    std::cout << "\n0. Kembali\n";
    std::cout << "Pilih opsi (1/2/3/4/5/6/7/8/9/10/11/12/0): ";
}

bool cekKetersediaan(tanggal t)
{
    for (int i = 0; i < jumlahTanggal; i++)
    {
        if (tidakTersediaTanggal[i].hari == t.hari && tidakTersediaTanggal[i].bulan == t.bulan && tidakTersediaTanggal[i].tahun == t.tahun)
        {
            return false;
        }
    }
    return true;
}

int dapatIndexTersediaan()
{
    int y = 0;
    for (int i = 0; i < sizeof(tidakTersediaTanggal) / sizeof(tidakTersediaTanggal[0]); i++)
    {
        if (tidakTersediaTanggal[i].hari == 0)
        {
            return y - 1;
        }
        y++;
    }
    return 0;
}

void tambahkanTanggal(int hari, int bulan, int tahun)
{
    tidakTersediaTanggal[jumlahTanggal].hari = hari;
    tidakTersediaTanggal[jumlahTanggal].bulan = bulan;
    tidakTersediaTanggal[jumlahTanggal].tahun = tahun;
    jumlahTanggal++;
}

void prosesPembayaran(pembeli &p)
{
    while (true)
    {
        std::cout << "\n\nTotal harga: " << p.harga << endl;
        std::cout << "Masukkan uang yang dibayar: ";
        std::cin >> p.uangDibayar;
        p.kembalian = p.uangDibayar - p.harga;
        if (p.kembalian < 0)
        {
            std::cout << "\nUang yang dibayar kurang atau input salah.\n";
            p.uangDibayar = 0;
        }
        else
        {
            std::cout << "Pembayaran berhasil. Kembalian: " << p.kembalian << endl;
            return;
        }
    }
}

void tampilkanDaftarPesanan(int tahun, int bulan)
{
    std::cout << "Daftar Pesanan untuk " << bulan << "/" << tahun << ":\n";
    for (int i = 0; i < jumlahPembeli; i++)
    {
        if (riwayatPembeli[i].tgl.tahun == tahun && riwayatPembeli[i].tgl.bulan == bulan)
        {
            std::cout << "Nama: " << riwayatPembeli[i].nama
                << ", Paket: " << riwayatPembeli[i].paketTrip
                << ", Tanggal: " << riwayatPembeli[i].tgl.hari << "/"
                << riwayatPembeli[i].tgl.bulan << "/"
                << riwayatPembeli[i].tgl.tahun
                << ", Jumlah Orang: " << riwayatPembeli[i].jumlahOrang
                << ", Total Harga: " << riwayatPembeli[i].harga << endl;
        }
    }
}

void pushLog(string action)
{
    LogNode *newNode = new LogNode;
    newNode->action = action;
    newNode->next = logHead;
    logHead = newNode;
}

void printLogs()
{
    LogNode *temp = logHead;
    std::cout << "Log Sistem:\n";
    while (temp != nullptr)
    {
        std::cout << temp->action << endl;
        temp = temp->next;
    }
}

void tampilkanStruk(pembeli p)
{
    std::cout << "\n\nStruk Pembelian:\n";
    std::cout << "=============================================\n";
    std::cout << "Pemesan: " << p.nama << std::endl;
    std::cout << "Jenis Trip: " << p.paketTrip << std::endl;
    
    for (int i = 0; i < 3; i++)
    {
        if (jenisTrip[i].nama == p.paketTrip)
        {
            std::cout << "Paket yang dipilih: " << jenisTrip[i].paket[p.jumlahOrang - 1].nama << std::endl;
            std::cout << "Isi Paket: " << jenisTrip[i].paket[p.jumlahOrang - 1].deskripsi << std::endl;
            break;
        }
    }
    std::cout << "Jumlah orang: " << p.jumlahOrang << std::endl;
    std::cout << "Waktu: " << p.tgl.hari << " " << p.tgl.bulan << " " << p.tgl.tahun << std::endl;
    std::cout << "Total harga: " << p.harga << std::endl;
}


void editPesanan()
{
    string nama;
    std::cout << "Masukkan nama pembeli yang ingin diedit: ";
    std::cin.ignore();
    getline(std::cin, nama);

    for (int i = 0; i < jumlahPembeli; i++)
    {
        if (riwayatPembeli[i].nama == nama)
        {
            std::cout << "Mengedit pesanan untuk " << nama << endl;
            std::cout << "Masukkan nama baru: ";
            getline(std::cin, riwayatPembeli[i].nama);

            std::cout << "Masukkan jumlah orang baru: ";
            std::cin >> riwayatPembeli[i].jumlahOrang;

            tampilkanNamaBulan();
            std::cin >> riwayatPembeli[i].tgl.bulan;

            std::cout << "Masukkan tanggal baru: ";
            std::cin >> riwayatPembeli[i].tgl.hari;

            std::cout << "Masukkan tahun baru: ";
            std::cin >> riwayatPembeli[i].tgl.tahun;

            riwayatPembeli[i].harga *= riwayatPembeli[i].jumlahOrang;
            std::cout << "Data berhasil diupdate.\n";
            pushLog("Ubah pesanan: " + riwayatPembeli[i].nama);

            return;
        }
    }
    std::cout << "Data tidak ditemukan.\n";
}

// Fungsi Menambahkan Pesanan
void tambahPesanan()
{
    pembeli p;
    tanggal t;

    int opsiJenis, opsiPaket, jumlahOrang, hari, bulan, tahun;

labelJenisTrip:
    while (true)
    {
        tampilkanJenisTrip();
        std::cin >> opsiJenis;
        if (opsiJenis == 0)
        {
            return;
        }
        else if (opsiJenis > 0 && opsiJenis <= (sizeof(jenisTrip) / sizeof(jenisTrip[0])))
        {
            break;
        }
        std::cout << "Pilihan tidak valid.\n";
    }
    p.paketTrip = jenisTrip[opsiJenis - 1].nama;

labelPaketTrip:
    while (true)
    {
        tampilkanPaketTrip(opsiJenis - 1);
        std::cin >> opsiPaket;
        if (opsiJenis == 0)
        {
            goto labelJenisTrip;
        }
        else if (opsiPaket >= 1 && opsiPaket <= 3)
        {
            break;
        }
        std::cout << "Pilihan tidak valid.\n";
    }
    p.harga = jenisTrip[opsiJenis - 1].paket[opsiPaket - 1].harga;

    while (true)
    {
        std::cout << "Masukkan jumlah orang: ";
        std::cin >> jumlahOrang;
        if (jumlahOrang > 0)
        {
            break;
        }
        std::cout << "Jumlah orang tidak valid.\n";
    }
    p.jumlahOrang = jumlahOrang;
    p.harga = p.harga * jumlahOrang;

    std::cout << "Masukkan nama pembeli: ";
    std::cin.ignore();
    getline(std::cin, p.nama);

    std::cout << "Masukan Tahun : ";
    std::cin >> tahun;

    while (true)
    {
        tampilkanNamaBulan();
        std::cin >> bulan;
        if (bulan == 0)
        {
            goto labelPaketTrip;
        }
        if (bulan >= 1 && bulan <= 12)
        {
            break;
        }
        std::cout << "Pilihan tidak valid.\n";
    }

labelTanggal:
    while (true)
    {
        std::cout << "Masukkan tanggal: ";
        std::cin >> hari;

        if (hari >= 1 && hari <= 31)
        {
            break;
        }
        std::cout << "Tanggal tidak valid.\n";
    }
    t.hari = hari;
    t.bulan = bulan;
    t.tahun = tahun;
    p.tgl = t;

    if (cekKetersediaan(t))
    {
        prosesPembayaran(p);
        if (p.uangDibayar > 0)
        {
            riwayatPembeli[jumlahPembeli++] = p;
            std::cout << "Trip berhasil dipesan.\n";
        }

    tampilkanStruk(p);
    }
    else
    {
        std::cout << "Tanggal tidak tersedia.\n";
        goto labelTanggal;
    }
    tidakTersediaTanggal[dapatIndexTersediaan()] = {hari, bulan, 2024};
    pushLog("Menambah pesanan: " + p.nama);
}

// Fungsi Menambah Trip
void tambahTrip()
{
    int index = dapatPanjangJenisTrip();
    if (index >= 100)
    {
        std::cout << "Tidak dapat menambah trip baru. Batas maksimum tercapai.\n";
        return;
    }

    std::cout << "Masukkan nama trip: ";
    std::cin.ignore();
    getline(std::cin, jenisTrip[index].nama);

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Masukkan nama paket " << i + 1 << ": ";
        getline(std::cin, jenisTrip[index].paket[i].nama);
        std::cout << "Masukkan deskripsi paket " << i + 1 << ": ";
        getline(std::cin, jenisTrip[index].paket[i].deskripsi);
        std::cout << "Masukkan harga paket " << i + 1 << ": ";
        std::cin >> jenisTrip[index].paket[i].harga;
        std::cin.ignore();
    }

    pushLog("Menambah trip: " + jenisTrip[index].nama);
    std::cout << "Trip baru berhasil ditambahkan.\n";
}

//  Fungsi mengedit trip
void editTrip()
{
    int index;
    tampilkanJenisTrip();
    std::cin >> index;
    if (index <= 0 || index > dapatPanjangJenisTrip())
    {
        std::cout << "Pilihan tidak valid.\n";
        return;
    }

    index--; // Convert to 0-based index

    std::cout << "Mengedit trip: " << jenisTrip[index].nama << endl;
    std::cout << "Masukkan nama baru trip: ";
    std::cin.ignore();
    getline(std::cin, jenisTrip[index].nama);

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Masukkan nama baru paket " << i + 1 << ": ";
        getline(std::cin, jenisTrip[index].paket[i].nama);
        std::cout << "Masukkan deskripsi baru paket " << i + 1 << ": ";
        getline(std::cin, jenisTrip[index].paket[i].deskripsi);
        std::cout << "Masukkan harga baru paket " << i + 1 << ": ";
        std::cin >> jenisTrip[index].paket[i].harga;
        std::cin.ignore();
    }

    pushLog("Mengedit trip: " + jenisTrip[index].nama);
    std::cout << "Trip berhasil diupdate.\n";
}

// Fungsi menghapus trip
void hapusTrip()
{
    int index;
    tampilkanJenisTrip();
    std::cin >> index;
    if (index <= 0 || index > dapatPanjangJenisTrip())
    {
        std::cout << "Pilihan tidak valid.\n";
        return;
    }

    index--; // Convert to 0-based index

    string deletedTripName = jenisTrip[index].nama;

    for (int i = index; i < dapatPanjangJenisTrip() - 1; i++)
    {
        jenisTrip[i] = jenisTrip[i + 1];
    }
    jenisTrip[dapatPanjangJenisTrip() - 1].nama = "";
    for (int i = 0; i < 3; i++)
    {
        jenisTrip[dapatPanjangJenisTrip() - 1].paket[i] = {"", "", 0};
    }

    pushLog("Menghapus trip: " + deletedTripName);
    std::cout << "Trip berhasil dihapus.\n";
}

// Fungsi Mengatur Data Trip
void aturDataTrip()
{
    int pilihan;
    while (true)
    {
        tampilkanDataTrip();
        std::cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            tambahTrip();
            break;
        case 2:
            editTrip();
            break;
        case 3:
            hapusTrip();
            break;
        case 0:
            return;
        default:
            std::cout << "Pilihan tidak valid.\n";
            break;
        }
    }
}

int main()
{
    declareTrip();
    int opsiMenu;
    int tahun, bulan;

    // Contoh tanggal yang tidak tersedia
    tambahkanTanggal(15, 7, 2024);
    tambahkanTanggal(20, 8, 2024);

    while (true)
    {
        tampilkanMenu();
        std::cin >> opsiMenu;

        if (opsiMenu == 0)
        {
            std::cout << "Terima kasih telah menggunakan layanan kami.\n";
            break;
        }

        switch (opsiMenu)
        {
        case 1:
            tambahPesanan();
            break;
        case 2:
            editPesanan();
            break;
        case 3:
            aturDataTrip();
            break;
        case 4:
            std::cout << "masukan tahun : ";
            std::cin >> tahun;
            tampilkanNamaBulan();
            std::cin >> bulan;
            tampilkanDaftarPesanan(tahun, bulan);
            break;
        case 5:
            printLogs();
            break;
        default:
            std::cout << "Pilihan tidak valid.\n";
            break;
        }

        std::cout << "Kembali ke menu utama? (y/n): ";
        char kembali;
        std::cin >> kembali;
        if (kembali == 'n' || kembali == 'N')
        {
            std::cout << "\n========== Program berhenti. ==============\n";
            break;
        }
    }
    return 0;
}