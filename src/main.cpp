#include <iostream>
#include "ADT.h"
using namespace std;

void tampilkanMenu() {
    cout << "\n=========================================================" << endl;
    cout << "     SISTEM MANAJEMEN & BILLING WARNET (MLL 1-to-N)" << endl;
    cout << "=========================================================" << endl;
    cout << "[ PARENT - KOMPUTER ]" << endl;
    cout << "  1. Tambah Komputer (Insert Parent)" << endl;
    cout << "  2. Cari Komputer (Find Parent)" << endl;
    cout << "  3. Hapus Komputer (Delete Parent + Cascading)" << endl;
    cout << "  4. Tampilkan Daftar Komputer (Print Parent)" << endl;
    cout << "[ CHILD - BILLING ]" << endl;
    cout << "  5. Tambah Billing ke Komputer (Insert Child)" << endl;
    cout << "  6. Cari Billing pada Komputer (Find Child)" << endl;
    cout << "  7. Hapus Billing dari Komputer (Delete Child)" << endl;
    cout << "  8. Tampilkan Riwayat Billing Komputer (Print Child)" << endl;
    cout << "[ LAINNYA ]" << endl;
    cout << "  9. Tampilkan Semua Data Warnet (Print All)" << endl;
    cout << "  0. Keluar" << endl;
    cout << "=========================================================" << endl;
    cout << "Pilih menu [0-9]: ";
}

int main() {
    List_Warnet L;
    Adr_Komputer K;
    Adr_Billing B;

    int pilihan;
    string idPC, namaPC, tipe, status;
    string idBilling, namaUser, jamMulai;
    int tarifPerJam, durasi;

    createList(L);
    do {
        tampilkanMenu();
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1: {
                cout << "--- TAMBAH KOMPUTER ---" << endl;
                cout << "ID PC                    : ";
                cin >> idPC;

                if (findKomputer(L, idPC) != nullptr) {
                    cout << "ID Komputer sudah terdaftar!" << endl;
                    break;
                }

                cout << "Nama PC                  : ";
                cin >> namaPC;
                cout << "Tipe (Gaming/Reguler/VIP): ";
                cin >> tipe;
                cout << "Tarif per Jam            : ";
                cin >> tarifPerJam;
                cout << "Status (Dipakai/Kosong)  : ";
                cin >> status;

                K = createKomputer(idPC, namaPC, tipe, tarifPerJam, status);
                insertKomputer(L, K);
                break;
            }

            case 2: {
                cout << "--- CARI KOMPUTER ---" << endl;
                cout << "Masukkan ID PC: ";
                cin >> idPC;

                K = findKomputer(L, idPC);
                if (K == nullptr) {
                    cout << "Komputer tidak ditemukan!" << endl;
                } else {
                    cout << "Ditemukan: [" << K->info.idPC << "] " << K->info.namaPC << " | " << K->info.tipe << " | Rp" << K->info.tarifPerJam << "/jam | Status: " << K->info.status << endl;
                }
                break;
            }

            case 3: {
                cout << "--- HAPUS KOMPUTER ---" << endl;
                cout << "Masukkan ID PC yang akan dihapus: ";
                cin >> idPC;
                deleteKomputer(L, idPC);
                break;
            }

            case 4: {
                cout << "--- DAFTAR KOMPUTER ---" << endl;
                printKomputer(L);
                break;
            }

            case 5: {
                cout << "--- TAMBAH BILLING KE KOMPUTER ---" << endl;

                cout << "Masukkan ID PC tujuan: ";
                cin >> idPC;
                K = findKomputer(L, idPC);
                if (K == nullptr) {
                    cout << "Komputer tidak ditemukan!" << endl;
                    break;
                }

                cout << "ID Billing           : ";
                cin >> idBilling;
                if (findBilling(K, idBilling) != nullptr) {
                    cout << "ID Billing sudah terdaftar pada komputer ini!" << endl;
                    break;
                }

                cout << "Nama User            : ";
                cin >> namaUser;
                cout << "Jam Mulai (cth 08:00): ";
                cin >> jamMulai;
                cout << "Durasi (jam)         : ";
                cin >> durasi;

                B = createBilling(idBilling, namaUser, jamMulai, durasi);
                insertBilling(K, B);
                break;
            }

            case 6: {
                cout << "--- CARI BILLING PADA KOMPUTER ---" << endl;
                cout << "Masukkan ID PC: ";
                cin >> idPC;

                K = findKomputer(L, idPC);
                if (K == nullptr) {
                    cout << "Komputer tidak ditemukan!" << endl;
                }
                cout << "Masukkan ID Billing: ";
                cin >> idBilling;

                B = findBilling(K, idBilling);
                if (B == nullptr) {
                    cout << "Billing tidak ditemukan!" << endl;
                } else {
                    cout << "Ditemukan: [" << B->info.idBilling << "] "
                         << B->info.namaUser << " | "
                         << B->info.jamMulai << " | "
                         << B->info.durasi << " jam | Total Bayar: Rp"
                         << B->info.totalBayar
                         << endl;
                }
                break;
            }

            case 7: {
                cout << "--- HAPUS BILLING DARI KOMPUTER ---" << endl;
                cout << "Masukkan ID PC: ";
                cin >> idPC;

                K = findKomputer(L, idPC);
                if (K == nullptr) {
                    cout << "Komputer tidak ditemukan!" << endl;
                }

                cout << "Masukkan ID Billing di " << K->info.idPC << " yang ingin dihapus: ";
                cin >> idBilling;
                deleteBilling(K, idBilling);
                break;
            }

            case 8: {
                cout << "--- RIWAYAT BILLING KOMPUTER ---" << endl;
                cout << "Masukkan ID PC: ";
                cin >> idPC;

                K = findKomputer(L, idPC);
                if (K == nullptr) {
                    cout << "Komputer tidak ditemukan!" << endl;
                } else {
                    printBilling(K);
                }
                break;
            }

            case 9: {
                cout << "--- SELURUH DATA WARNET ---" << endl;
                printAll(L);
                break;
            }

            case 0: {
                cout << "Membersihkan memori dan keluar dari program..." << endl;
                break;
            }

            default:
                cout << "Pilihan tidak tersedia. Silakan pilih 0 - 9." << endl;
                break;
        }
    } while (pilihan != 0);

    while (L.first != nullptr) {
        K = L.first;
        while (K->nextBilling != nullptr) {
            B = K->nextBilling;
            K->nextBilling = B->next;
            delete B;
        }
        L.first = K->next;
        delete K;
    }

    return 0;
}
