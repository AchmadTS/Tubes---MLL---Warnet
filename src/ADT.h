#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED
#include<iostream>

using namespace std;

struct Infotype_Billing{
    string idBilling, namaUser, jamMulai;
    int durasi, totalBayar;
};

typedef struct Elm_Billing *Adr_Billing;
struct Elm_Billing{
    Infotype_Billing info;
    Adr_Billing next;
};

struct Infotype_Komputer{
    string idPC, namaPC, tipe, status;
    int tarifPerJam;
};

typedef struct Elm_Komputer *Adr_Komputer;
struct Elm_Komputer{
    Infotype_Komputer info;
    Adr_Billing nextBilling;
    Adr_Komputer next;
};

struct List_Warnet{
    Adr_Komputer first;
};

void createList(List_Warnet &L);
Adr_Komputer createKomputer(string idPC, string namaPC, string tipe, int tarifPerJam, string status);
Adr_Komputer findKomputer(List_Warnet L, string idPC);
void insertKomputer(List_Warnet &L, Adr_Komputer K);
void deleteKomputer(List_Warnet &L, string idPC);
void printKomputer(List_Warnet L);
Adr_Billing createBilling(string idBilling, string namaUser, string jamMulai, int durasi);
Adr_Billing findBilling(Adr_Komputer K, string idBilling);
void insertBilling(Adr_Komputer &K, Adr_Billing B);
void deleteBilling(Adr_Komputer &K, string idBilling);
void printBilling(Adr_Komputer K);
void printAll(List_Warnet L);

#endif
