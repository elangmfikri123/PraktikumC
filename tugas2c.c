#include <stdio.h>
#include <math.h>

void printRupiah(double angka)
{

    long long bulat = (long long)angka; // Mengambil bagian bilangan bulat dari angka

    char buf[20];
    int len = sprintf(buf, "%lld", bulat); // Mengubah angka menjadi string
    int i;
    int titik = (len - 1) / 3;
    int start = len % 3;
    if (start == 0)
        start = 3;
    printf("Rp");

    for (i = 0; i < len; i++) // Loop untuk mencetak tiap karakter angka
    {
        if (i == start && titik > 0)
        {
            printf(".");
            start += 3;
            titik--;
        }
        printf("%c", buf[i]);
    }
}

int main()
{
    double totalPembelian, diskon, totalBayar;
    int kupon;

    printf("Input total belanja: "); // Input total belanja dari user
    scanf("%lf", &totalPembelian);

    // Menghitung jumlah kupon:
    // Setiap pembelian 100000 mendapat 1 kupon
    kupon = (int)floor(totalPembelian / 100000.0);

    if (totalPembelian >= 100000.0)
    {
        diskon = totalPembelian * 0.05;
    }
    else
    {
        diskon = 0.0;
    }

    totalBayar = totalPembelian - diskon; // Menghitung total yang harus dibayar setelah diskon

    // Menampilkan output
    printf("\nOutput:\n");

    printf("Total pembelian      : ");
    printRupiah(totalPembelian); 
    printf("\n");

    printf("Jumlah kupon undian  : %d lembar\n", kupon);

    printf("Diskon               : ");
    printRupiah(diskon);
    printf("\n");

    printf("Total dibayar        : ");
    printRupiah(totalBayar);
    printf("\n");

    return 0;
}