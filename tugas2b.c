#include <stdio.h> //Import library untuk input dan output
#include <string.h> //Import library untuk fungsi string seperti strcmp

int main() {
// Deklarasi variabel
char nip[50], nama[50], alamat[100], no_hp[20], jabatan[50];
char golongan[5];
int jam_lembur;
long gaji_pokok = 0;
long tarif_lembur = 0;
long total_gaji = 0;

printf("=== PROGRAM PENGHITUNGAN GAJI PEGAWAI ===\n\n");

// Memasukkan Inputan Data Pegawai
printf("Silakan masukkan data pegawai:\n");
printf("NIP      = ");
scanf("%s", nip);
printf("Nama     = ");
scanf(" %[^\n]", nama); 
printf("Alamat   = ");
scanf(" %[^\n]", alamat);
printf("No HP    = ");
scanf("%s", no_hp);
printf("Jabatan  = ");
scanf(" %[^\n]", jabatan);

printf("Golongan (D1/D2/D3) = ");
scanf("%s", golongan);

// Perhitungan Gaji berdasarkan Golongan Jabatan
if (strcmp(golongan, "D1") == 0) {
    gaji_pokok = 3000000;
    tarif_lembur = 15000;
} else if (strcmp(golongan, "D2") == 0) {
    gaji_pokok = 2500000;
    tarif_lembur = 10000;
} else if (strcmp(golongan, "D3") == 0) {
    gaji_pokok = 2000000;
    tarif_lembur = 5000;
} else {
    printf("\nGolongan tidak valid!\n");
    gaji_pokok = 0;
    tarif_lembur = 0;
}
// Menampilkan hasil dari inputan data pegawai
printf("\n--- TAMPILAN DATA PEGAWAI ---\n");
printf("NIP      = %s\n", nip);
printf("Nama     = %s\n", nama);
printf("Alamat   = %s\n", alamat);
printf("No HP    = %s\n", no_hp);
printf("Jabatan  = %s\n", jabatan);
printf("Golongan = %s\n", golongan);
printf("Gaji     = Rp %ld\n", gaji_pokok);

// Menampilkan inputan jumlah jam lembur
printf("\nMasukkan jumlah jam lembur bulan ini:\n");
printf("Lembur (jam) = ");
scanf("%d", &jam_lembur);

// Perhitungan total gaji dengan lembur
total_gaji = gaji_pokok + (jam_lembur * tarif_lembur);

// Menampilkan Output untuk perhitungan Lemburan dengan total gaji
printf("\n--- SLIP GAJI BULAN INI ---\n");
printf("NIP                  = %s\n", nip);
printf("Golongan             = %s\n", golongan);
printf("Lembur               = %d jam\n", jam_lembur);
printf("Total Gaji Bulan Ini = Rp %ld\n", total_gaji);

return 0;
}