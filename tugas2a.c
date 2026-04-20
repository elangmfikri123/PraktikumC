#include <stdio.h>
#include <string.h>

// Membuat struct untuk data pegawai
struct Pegawai {
    char nip[20];
    char nama[50];
    char alamat[100];
    char no_hp[15];
    char jabatan[50];
    char golongan[3];
    long gaji_pokok; // tipe data untuk menyimpan nilai rupiah
};

// Fungsi untuk menentukan gaji pokok berdasarkan golongan
long tentukanGajiPokok(char golongan[]) {
    if (strcmp(golongan, "D1") == 0) {
        return 3000000;
    } else if (strcmp(golongan, "D2") == 0) {
        return 2500000;
    } else if (strcmp(golongan, "D3") == 0) {
        return 2000000;
    } else {
        return 0; // jika golongan tidak valid
    }
}

int main() {
    struct Pegawai p;

    // Input data pegawai
    printf("=== Input Data Pegawai ===\n");
    
    printf("NIP           : ");
    scanf("%s", p.nip);

    printf("Nama          : ");
    getchar(); // membersihkan buffer
    fgets(p.nama, sizeof(p.nama), stdin);

    printf("Alamat        : ");
    fgets(p.alamat, sizeof(p.alamat), stdin);

    printf("No HP         : ");
    scanf("%s", p.no_hp);

    printf("Jabatan       : ");
    getchar(); // membersihkan buffer
    fgets(p.jabatan, sizeof(p.jabatan), stdin);

    printf("Golongan (D1/D2/D3): ");
    scanf("%s", p.golongan);

    // Menentukan gaji pokok otomatis
    p.gaji_pokok = tentukanGajiPokok(p.golongan);

    // Output data pegawai
    printf("\n=== Data Pegawai ===\n");
    printf("NIP           : %s\n", p.nip);
    printf("Nama          : %s", p.nama);
    printf("Alamat        : %s", p.alamat);
    printf("No HP         : %s\n", p.no_hp);
    printf("Jabatan       : %s", p.jabatan);
    printf("Golongan      : %s\n", p.golongan);

    // Menampilkan gaji pokok
    if (p.gaji_pokok > 0) {
        printf("Gaji Pokok    : Rp %ld\n", p.gaji_pokok);
    } else {
        printf("Gaji Pokok    : Golongan tidak valid!\n");
    }

    return 0;
}