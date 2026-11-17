#switch
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <switch.h>

// Fungsi untuk menggambar antarmuka menu utama dalam Bahasa Indonesia
void tampilkanMenu() {
    consoleClear();
    printf("========================================\n");
    printf("     NINTENDO SWITCH PUSAT UNDUHAN      \n");
    printf("========================================\n");
    printf("[A] - Muat Daftar Game dari Server\n");
    printf("[X] - Unduh File Game Terpilih\n");
    printf("[Y] - Cek Ruang Kosong SD Card\n");
    printf("[+] - Keluar dari Aplikasi\n");
    printf("----------------------------------------\n");
    printf("Status: Menunggu perintah...\n");
}

int main(int argc, char **argv) {
    // Inisialisasi konsol teks libnx
    consoleInit(NULL);

    // Inisialisasi modul jaringan (opsional untuk unduh via internet)
    socketInitializeDefault();

    tampilkanMenu();

    // Loop utama aplikasi
    while (appletMainLoop()) {
        hidScanInput();
        u64 tombolTekan = hidKeysDown(CONTROLLER_P1_AUTO);

        // Tombol Plus (+) untuk keluar aplikasi kembali ke Homebrew Menu
        if (tombolTekan & KEY_PLUS) break;

        // Jika tombol A ditekan (Mengambil daftar)
        if (tombolTekan & KEY_A) {
            consoleClear();
            printf("[Proses] Menghubungkan ke server unduhan...\n");
            svcSleepThread(1000000000); // Jeda 1 detik
            printf("[Sukses] Daftar game berhasil dimuat!\n");
            printf("\nTekan (B) untuk kembali ke menu.\n");
        }

        // Jika tombol X ditekan (Simulasi unduh game)
        if (tombolTekan & KEY_X) {
            consoleClear();
            printf("[Proses] Memulai pengunduhan game...\n");
            
            // Simulasi proses unduh menggunakan baris persentase
            for (int i = 0; i <= 100; i += 25) {
                printf("Mengunduh... %d%%\n", i);
                svcSleepThread(500000000); // Jeda setengah detik
            }
            
            printf("\n[Selesai] Game berhasil diunduh ke kartu SD!\n");
            printf("\nTekan (B) untuk kembali ke menu.\n");
        }

        // Jika tombol Y ditekan (Cek memori)
        if (tombolTekan & KEY_Y) {
            consoleClear();
            printf("[Informasi Sistem]\n");
            printf("Penyimpanan Kartu SD: Terbaca aman.\n");
            printf("Format direktori: sdmc:/switch/\n");
            printf("\nTekan (B) untuk kembali ke menu.\n");
        }

        // Tombol B untuk kembali ke menu utama
        if (tombolTekan & KEY_B) {
            tampilkanMenu();
        }

        consoleUpdate(NULL);
    }

    // Tutup jaringan dan matikan konsol sebelum keluar
    socketExit();
    consoleExit();
    return 0;
}
