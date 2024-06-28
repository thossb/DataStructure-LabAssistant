// Implementasi rekursif C++ yang sederhana
// dari masalah LIS (Longest Increasing Subsequence)
#include <bits/stdc++.h>
using namespace std;

// Untuk menggunakan panggilan rekursif, fungsi ini
// harus mengembalikan dua hal:
// 1) Panjang LIS yang berakhir dengan elemen
//    arr[n-1]. Kami menggunakan max_ending_here untuk tujuan ini.
// 2) Nilai maksimum secara keseluruhan karena LIS bisa berakhir
//    dengan suatu elemen sebelum arr[n-1], max_ref
//    digunakan untuk tujuan ini.
// Nilai LIS dari seluruh array berukuran n
//    disimpan di *max_ref yang merupakan hasil akhir kita.
int _lis(int arr[], int n, int* max_ref)
{

    // Kasus dasar
    if (n == 1)
        return 1;

    // 'max_ending_here' adalah panjang LIS yang berakhir dengan
    // arr[n-1]
    int res, max_ending_here = 1;

    // Dapatkan rekursif semua LIS yang berakhir dengan
    // arr[0], arr[1] ... arr[n-2]. Jika
    // arr[i-1] lebih kecil dari arr[n-1],
    // dan max yang berakhir dengan arr[n-1] perlu
    // diperbarui, maka perbarui itu
    for (int i = 1; i < n; i++) {
        res = _lis(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1]
            && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }

    // Bandingkan max_ending_here dengan
    // maksimum secara keseluruhan. Dan perbarui
    // maksimum secara keseluruhan jika diperlukan
    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;

    // Kembalikan panjang LIS yang berakhir
    // dengan arr[n-1]
    return max_ending_here;
}

// Fungsi pembungkus untuk _lis()
int lis(int arr[], int n)
{

    // Variabel max menyimpan hasilnya
    int max = 1;

    // Fungsi _lis() menyimpan hasilnya
    // di max
    _lis(arr, n, &max);

    // Kembalikan max
    return max;
}

// Program pengujian fungsi di atas
int main()
{
    int arr[] = { 4, 1, 13, 7, 0, 2, 8, 11, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Panggil fungsi
    cout << "Panjang lis adalah " << lis(arr, n);
    return 0;
}
