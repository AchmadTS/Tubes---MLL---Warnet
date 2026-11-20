# Sistem Manajemen & Billing Warnet (Multi Linked List 1-to-N)

![C++](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=flat-square&logo=c%2B%2B)
![Data Structure](https://img.shields.io/badge/Data%20Structure-Multi%20Linked%20List%20(1--to--N)-2EA44F?style=flat-square)
![IDE](https://img.shields.io/badge/IDE-Code%3A%3ABlocks-informational?style=flat-square)

Tugas Besar mata kuliah **Struktur Data** (Kelas SE-49-01, S1 Rekayasa Perangkat Lunak, Telkom University). Program ini mengelola data unit komputer dan transaksi *billing* warnet menggunakan struktur data **Multi Linked List (1-to-N)** menggunakan bahasa C++

## 📐 Arsitektur Struktur Data

Relasi: **1 Parent ke N Child**. Setiap node `Elm_Komputer` menyimpan pointer `nextBilling` yang menunjuk langsung ke node `Elm_Billing` pertamanya

<div align="center">
  <img src="docs/Tubes%20STD%20-%20MLL%20-%20Warnet.png" alt="Diagram Multi Linked List Warnet" width="750"/>
</div>

| Komponen | Tipe / Struct | Atribut & Pointer |
| :--- | :--- | :--- |
| **List Utama** | `List_Warnet` | `first` (`Adr_Komputer`) |
| **Parent (PC)** | `Elm_Komputer` | `idPC`, `namaPC`, `tipe`, `tarifPerJam`, `status`, `nextBilling`, `next` |
| **Child (Billing)** | `Elm_Billing` | `idBilling`, `namaUser`, `jamMulai`, `durasi`, `totalBayar`, `next` |

## ⚙️ Operasi Utama

| Kategori | Primitif | Keterangan |
| :--- | :--- | :--- |
| **Komputer (Parent)** | `createKomputer`, `insertKomputer`, `findKomputer`, `deleteKomputer`, `printKomputer` | Kelola PC dengan validasi duplikat `idPC` & hapus otomatis seluruh riwayat *billing* saat PC dihapus |
| **Billing (Child)** | `createBilling`, `insertBilling`, `findBilling`, `deleteBilling`, `printBilling` | Kelola sesi penggunaan per PC dengan hitung otomatis `totalBayar = durasi * tarifPerJam` |
| **Keseluruhan** | `printAll` | Tampilkan seluruh daftar PC beserta riwayat *billing* di dalamnya |

## 📁 Struktur Folder

```text
Tubes---MLL---Warnet/
├── docs/
│   ├── pseudocode.txt               # Spesifikasi ADT & algoritma
│   └── Tubes STD - MLL - Warnet.png # Diagram ilustrasi MLL 1-to-N
├── src/
│   ├── ADT.h                        # Header struct, pointer, & prototype
│   ├── MLL.cpp                      # Implementasi operasi MLL
│   ├── main.cpp                     # Menu CLI & main program
│   └── Warnet.cbp                   # File proyek Code::Blocks
├── .gitignore
└── README.md
```

## 🚀 Cara Menjalankan

1. Clone repositori ini:
   ```bash
   git clone https://github.com/AchmadTS/Tubes---MLL---Warnet.git
   cd Tubes---MLL---Warnet
   ```
2. Buka file **`src/Warnet.cbp`** di **Code::Blocks**
3. Tekan **`F9`** (*Build and Run*) untuk menjalankan program

> [!TIP]
> Buka proyek langsung lewat file `Warnet.cbp` (bukan buka file `.cpp` satuan) supaya `ADT.h`, `MLL.cpp`, dan `main.cpp` otomatis ter-*link* saat di-*compile*

## 👥 Anggota Kelompok

**Kelas SE-49-01 - S1 Rekayasa Perangkat Lunak, Telkom University**

| Nama | NIM | Tugas |
| :--- | :--- | :--- |
| **Muhammad Syahrul Ihsan** (`@pukislukis`) | `103022500063` | Implementasi Primitif (`MLL.cpp`) & `main.cpp` |
| **Achmad Tirto Sudiro** (`@AchmadTS`) | `103022530029` | Desain Arsitektur MLL, Pseudocode, & Header (`ADT.h`) |
