#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// konstan
#define MAX_NAMA 50 // jumlah maks char nama
#define MAX_SISWA 100 // jumlah maks siswa
#define FILENAME "database_siswa.txt" // nama file

// struct untuk data siswa
struct Siswa {
    char nama[MAX_NAMA];
    int umur;
    char nomorRegistrasi[20];
};

/* 
fopen() membuka file yg ada kalau tidak ada akan membuat file baru
fclose() menutup file
fprintf(file, "%s|%d|%s\n", siswa.nama, siswa.umur, siswa.nomorRegistrasi) untuk menulis data ke file
sscanf(line, "%[^|]|%d|%s", nama, &umur, nomor) untuk extract data dari file sesuai format
remove(FILENAME); untuk menghapus file lama
rename("temp_siswa.txt", FILENAME); untuk mengganti nama file
*/

// fungsi untuk menambahkan data siswa
void tambahSiswa() {
    FILE *file = fopen(FILENAME, "a"); 
    
    if (file == NULL) {
        printf("Error: file tidak bisa dibuka!\n");
        return;
    }
    
    struct Siswa siswa; // 
    
    printf("\n=== Tambah Data Siswa ===\n");
    printf("Nama: ");
    fgets(siswa.nama, MAX_NAMA, stdin);
    siswa.nama[strcspn(siswa.nama, "\n")] = '\0';
    
    printf("Umur: ");
    scanf("%d", &siswa.umur);
    getchar(); // clear buffer
    
    printf("Nomor Registrasi: ");
    fgets(siswa.nomorRegistrasi, 20, stdin);
    siswa.nomorRegistrasi[strcspn(siswa.nomorRegistrasi, "\n")] = '\0';
    
    // validasi inputan
    if (strlen(siswa.nama) == 0 || siswa.umur <= 0) {
        printf("Error: Data tidak valid!\n");
        fclose(file);
        return;
    }
    
    // tulis data ke file menggunakan format nama|umur|nomorRegistrasi
    fprintf(file, "%s|%d|%s\n", siswa.nama, siswa.umur, siswa.nomorRegistrasi);
    
    printf("Data siswa berhasil ditambahkan!\n");
    fclose(file);
}

// fungsi untuk mencari data siswa
void cariSiswa() {
    FILE *file = fopen(FILENAME, "r");
    
    if (file == NULL) {
        printf("Error: File tidak ditemukan!\n");
        return;
    }
    
    printf("\n=== Cari Data Siswa ===\n");
    char cariNomor[20];
    printf("Masukkan Nomor Registrasi: ");
    fgets(cariNomor, 20, stdin);
    cariNomor[strcspn(cariNomor, "\n")] = '\0';
    
    char line[200];
    int ditemukan = 0;
    
    // cari nomor sesuai inputan untuk ditampilkan
    while (fgets(line, sizeof(line), file)) {
        char nama[MAX_NAMA];
        int umur;
        char nomor[20];
        
        sscanf(line, "%[^|]|%d|%s", nama, &umur, nomor);
        
        // cari nomor sesuai inputan
        if (strcmp(nomor, cariNomor) == 0) {
            printf("\nData Ditemukan:\n");
            printf("Nama: %s\n", nama);
            printf("Umur: %d tahun\n", umur);
            printf("Nomor Registrasi: %s\n", nomor);
            ditemukan = 1;
            break;
        }
    }
    
    if (!ditemukan) {
        printf("Data siswa tidak ditemukan!\n");
    }
    
    fclose(file);
}

// fungsi untuk menghapus data
void hapusSiswa() {
    FILE *file = fopen(FILENAME, "r"); // membuka file asli readmode
    FILE *temp = fopen("temp_siswa.txt", "w"); // membuat file temp untuk update data
    
    if (file == NULL || temp == NULL) {
        printf("Error: Tidak bisa membuka file!\n");
        return;
    }
    
    printf("\n=== Hapus Data Siswa ===\n");
    char hapusNomor[20];
    printf("Masukkan Nomor Registrasi yang akan dihapus: ");
    fgets(hapusNomor, 20, stdin);
    hapusNomor[strcspn(hapusNomor, "\n")] = '\0';
    
    char line[200];
    int ditemukan = 0;
    
    // cari nomor sesuai inputan untuk dihapus
    while (fgets(line, sizeof(line), file)) {
        char nomor[20];
        sscanf(line, "%*[^|]|%*d|%s", nomor);
        
        if (strcmp(nomor, hapusNomor) == 0) {
            ditemukan = 1;
            // skip tulis data ke file temp (dihapus)
            continue;
        }
        
        // tulis data lain kembali ke file
        fprintf(temp, "%s", line);
    }
    
    fclose(file);
    fclose(temp);
    
    // ganti file asli dengan file temp
    remove(FILENAME);
    rename("temp_siswa.txt", FILENAME);
    
    if (ditemukan) {
        printf("Data siswa berhasil dihapus!\n");
    } else {
        printf("Data siswa tidak ditemukan!\n");
    }
}

// fungsi untuk menampilkan data
void tampilSemuaSiswa() {
    FILE *file = fopen(FILENAME, "r");
    
    if (file == NULL) {
        printf("File kosong atau tidak ada data!\n");
        return;
    }
    
    printf("\n=== Daftar Semua Siswa ===\n");
    printf("%-20s %-5s %-15s\n", "Nama", "Umur", "No. Registrasi");
    printf("================================================\n");
    
    char line[200];
    int jumlah = 0;
    
    while (fgets(line, sizeof(line), file)) {
        char nama[MAX_NAMA];
        int umur;
        char nomor[20];
        
        sscanf(line, "%[^|]|%d|%s", nama, &umur, nomor);
        printf("%-20s %-5d %-15s\n", nama, umur, nomor);
        jumlah++;
    }
    
    printf("================================================\n");
    printf("Total siswa: %d\n", jumlah);
    fclose(file);
}

// program utama untuk pemanggilan fungsi
int main() {
    int pilihan;
    
    while (1) {
        printf("\n================================================\n");
        printf("Program Manajemen Database Siswa     \n");
        printf("================================================\n");
        printf("1. Tambah Data Siswa\n");
        printf("2. Cari Data Siswa\n");
        printf("3. Hapus Data Siswa\n");
        printf("4. Tampil Semua Data\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar();
        
        switch (pilihan) {
            case 1:
                tambahSiswa();
                break;
            case 2:
                cariSiswa();
                break;
            case 3:
                hapusSiswa();
                break;
            case 4:
                tampilSemuaSiswa();
                break;
            case 5:
                printf("Program berakhir\n");
                return 0;
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
    
    return 0;
}