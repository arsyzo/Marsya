#include <iostream>
#include <list>
using namespace std;

// data perpustakaan
struct Book {
    string isbn;
    string title;
    string status; 
};

// untuk membuat data linked list 
list<Book> library;
// buku yang tersedia di perpustakaan
void displayBuku() {
    library.push_back({"9789792248616", "Negeri 5 Menara", "-"});
    library.push_back({"9789793062792", "Laskar Pelangi", "-"});
    library.push_back({"9789791227780", "Perahu Kertas", "-"});
    library.push_back({"9789797807214", "Sabtu Bersama Bapak", "-"});
    library.push_back({"9789679370256", "Tenggelamnya Kapal Van der Wijck", "-"});
}

// opsi pilihan menu
void displayMenu() {
    cout << "Pilihan Menu:" << endl;
    cout << "A. Buku Perpustakaan Acha" << endl;
    cout << "B. Silahkan pilih buku yang ingin dipinjam" << endl;
    cout << "C. Edit status buku yang dipinjam" << endl;
    cout << "D. Selesai" << endl;
}

// untuk meminjam buku
void borrowBook() {
    string isbn;
    cout << "Masukkan No ISBN buku yang ingin dipinjam: ";
    cin >> isbn;

    // mencari buku di display buku
    for (auto& book : library) {
        if (book.isbn == isbn) {
            if (book.status == "-") {
                book.status = "Dipinjam";
                cout << "Buku berhasil dipinjam" << endl;
            } else {
                cout << "Buku sudah dipinjam" << endl;
            }
            return;
        }
    }

    cout << "Judul buku tersebut tidak ada di Perpustakaan" << endl;
}

// untuk mengedit status buku yang sedang dipinjam
void editBookStatus() {
    string isbn, newStatus;
    cout << "Masukkan No ISBN buku yang ingin diedit: ";
    cin >> isbn;

    // mencari buku menggunakan ISBN
    for (auto& book : library) {
        if (book.isbn == isbn) {
            cout << "Masukkan status baru: ";
            cin >> newStatus;
            book.status = newStatus;
            return;
        }
    }
    cout << "Judul buku tersebut tidak ada di Perpustakaan" << endl;
}

int main() {
    displayBuku();
    cout << "Hallo! Selamat datang di Perpustakaan Acha" << endl;

    char choice;
    do {
        displayMenu();
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice) {
            case 'A':
                // Display untuk pilihan buku
                for (const auto& book : library) {
                    cout << book.isbn << "\t" << book.title << "\t" << book.status << endl;
                }
                break;
            case 'B':
                borrowBook();
                break;
            case 'C':
                editBookStatus();
                break;
            case 'D':
                cout << "Terima kasih! Sudah membaca di Perpustakaan Acha!!!" << endl;
                break;
            default:
                cout << "Silahkan masukkan pilihan opsi menu yang benar" << endl;
        }
    } while (choice != 'D');

    return 0;
}