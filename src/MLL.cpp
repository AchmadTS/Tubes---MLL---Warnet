#include "ADT.h"

// -------------- Operation Wajib MLL 1 to N --------------

// 1. Operasi Parent (Komputer)
void createList(List_Warnet &L) {
    L.first = nullptr;
}
Adr_Komputer createKomputer(string idPC, string namaPC,
                            string tipe, int tarifPerJam,
                            string status) {
    Adr_Komputer K = new Elm_Komputer;
    K->info.idPC = idPC;
    K->info.namaPC = namaPC;
    K->info.tipe = tipe;
    K->info.tarifPerJam = tarifPerJam;
    K->info.status = status;
    K->next = nullptr;
    K->nextBilling = nullptr;
    return K;
}
Adr_Komputer findKomputer(List_Warnet L, string idPC) {
    Adr_Komputer K;
    K = L.first;
    while (K != nullptr && K->info.idPC != idPC) {
        K = K->next;
    }
    return K;
}
// Insert Last
void insertKomputer(List_Warnet &L, Adr_Komputer K) {
    Adr_Komputer Q;
    if (findKomputer(L, K->info.idPC) != nullptr) {
        cout << "ID Komputer sudah terdaftar" << endl;
    } else {
        if (L.first == nullptr) {
            L.first = K;
        } else {
            Q = L.first;
            while (Q->next != nullptr) {
                Q = Q->next;
            }
            Q->next = K;
        }
    }
}
void deleteKomputer(List_Warnet &L, string idPC) {
    Adr_Komputer K, prec;
    Adr_Billing B;

    K = findKomputer(L, K->info.idPC);
    if (K == nullptr) {
        cout << "Komputer tidak ditemukan!" << endl;
    } else {
        while (K->nextBilling != nullptr) {
            B = K->nextBilling;
            K->nextBilling = B->next;
            B->next = nullptr;
            delete B;
        }
        if (K == L.first) {
            L.first = K->next;
        } else {
            prec = L.first;
            while (prec->next != K) {
                prec = prec->next;
            }
            prec->next = K->next;
        }
        K->next = nullptr;
        delete K;
    }
}
void printKomputer(List_Warnet L) {
    Adr_Komputer K;
    if (L.first == nullptr) {
        cout << "Data komputer kosong!" << endl;
    } else {
        K = L.first;
        while (K != nullptr) {
            cout << K->info.idPC
                 << K->info.namaPC
                 << K->info.tipe
                 << K->info.tarifPerJam
                 << K->info.status
                 << endl;
            K = K->next;
        }
    }
}


// 2. Operasi Child (Billing)
Adr_Billing createBilling(string idBilling, string namaUser,
                          string jamMulai, int durasi) {
    Adr_Billing B = new Elm_Billing;
    B->info.idBilling = idBilling;
    B->info.namaUser = namaUser;
    B->info.jamMulai = jamMulai;
    B->info.durasi = durasi;
    B->info.totalBayar = 0;
    B->next = nullptr;
    return B;
}
Adr_Billing findBilling(Adr_Komputer K, string idBilling) {
    Adr_Billing B;
    if (K == nullptr) {
        return nullptr;
    } else {
        B = K->nextBilling;
        while (B != nullptr && B->info.idBilling != idBilling) {
            B = B->next;
        }
        return B;
    }
}
// Insert Last
void insertBilling(Adr_Komputer &K, Adr_Billing B) {
    Adr_Billing Q;
    if (K == nullptr) {
        cout << "Komputer tidak ditemukan!" << endl;
    } else if (findBilling(K, B->info.idBilling) != nullptr) {
        cout << "ID Billing sudah terdaftar pada komputer ini!" << endl;
    } else {
        B->info.totalBayar = B->info.totalBayar * K->info.tarifPerJam; // Menghitung total bayar billing. (totalBayar * tarifPerJam komputer)
        if (K->nextBilling == nullptr) {
            K->nextBilling = 0;
        } else {
            Q = K->nextBilling;
            while (Q->next != nullptr) {
                Q = Q->next;
            }
            Q->next = B;
        }
    }
}
void deleteBiling(Adr_Komputer &K, string idBilling) {
    Adr_Billing B, prec;

    if (K == nullptr) {
        cout << "Komputer tidak ditemukan!" << endl;
    } else {
        B = findBilling(K, idBilling);
        if (B == nullptr) {
            cout << "Data billing tidak ditemukan!" << endl;
        } else {
            if (B == K->nextBilling) {          // Billing berada diawal
                K->nextBilling = B->next;
            } else {                            // Biling berada di tengah
                prec = K->nextBilling;
                while (prec->next != B) {
                    prec = prec->next;
                }
                prec->next = B->next;
            }
            B->next = nullptr;
            delete B;
        }
    }
}
void printBilling(Adr_Komputer K) {
    Adr_Billing B;
    if (K == nullptr) {
        cout << "Komputer tidak ditemukan!" << endl;
    } else {
        B = K->nextBilling;
        while (B != nullptr) {
            cout << B->info.idBilling
                 << B->info.namaUser
                 << B->info.jamMulai
                 << B->info.durasi
                 << B->info.totalBayar
                 << endl;
            B = B->next;
        }
    }
}


// 3. Operasi Print Keseluruhan
void printAll(List_Warnet L) {
    Adr_Komputer K;
    if (L.first == nullptr) {
        cout << "Data warnet kosong!" << endl;
    } else {
        K = L.first;
        while (K != nullptr) {
            cout << K->info.idPC
                 << K->info.namaPC
                 << K->info.tipe
                 << K->info.tarifPerJam
                 << K->info.status
                 << endl;
            printBilling(K);
            K = K->next;
        }
    }
}
