#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKINGS 100

// Struktur data pemesanan
typedef struct {
    char name[50];
    int roomNumber;
    char checkInDate[15];
    char checkOutDate[15];
} Booking;

Booking bookings[MAX_BOOKINGS];
int bookingCount = 0;
// ini tuh untuk nambah data pemesanan 
void addBooking() {
    if (bookingCount >= MAX_BOOKINGS) {
        printf("Booking penuh!\n");
        return;
    }
    printf("Nama Pemesan: ");
    scanf(" %[^\n]", bookings[bookingCount].name);
    printf("Nomor Kamar: ");
    scanf("%d", &bookings[bookingCount].roomNumber);
    printf("Tanggal Check-in (dd-mm-yyyy): ");
    scanf(" %[^\n]", bookings[bookingCount].checkInDate);
    printf("Tanggal Check-out (dd-mm-yyyy): ");
    scanf(" %[^\n]", bookings[bookingCount].checkOutDate);
    bookingCount++;
    printf("Booking berhasil ditambahkan!\n");
}
// lait data pemesanan yang telah kita lakukan 
void viewBookings() {
    if (bookingCount == 0) {
        printf("Tidak ada data pemesanan.\n");
        return;
    }
    int i,j;
    printf("\nData Pemesanan:\n");
    for (i = 0; i < bookingCount; i++) {
        printf("%d. Nama: %s, Kamar: %d, Check-in: %s, Check-out: %s\n",
               i + 1, bookings[i].name, bookings[i].roomNumber, bookings[i].checkInDate, bookings[i].checkOutDate);
    }
}
// mengurutkan data 
void sortBookings() {
	int i,j;
    for (i = 0; i < bookingCount - 1; i++) {
        for (j = 0; j < bookingCount - i - 1; j++) {
            if (strcmp(bookings[j].name, bookings[j + 1].name) > 0) {
                Booking temp = bookings[j];
                bookings[j] = bookings[j + 1];
                bookings[j + 1] = temp;
            }
        }
    }
    printf("Data berhasil diurutkan berdasarkan nama.\n");
}
int main() {
    int choice;
    do {
        printf("\n=== Room Booking System ===\n");
        printf("1. Tambah Pemesanan\n");
        printf("2. Lihat Pemesanan\n");
        printf("3. Urutkan Pemesanan (Nama)\n");
        printf("0. Keluar\n");
        printf("Pilih menu:\n ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBooking(); break;
            case 2: viewBookings(); break;
            case 3: sortBookings(); break;
            case 0:  printf("Terima kasih telah menggunakan jasa Room Booking System kami Love  You\n");
                break;
            default: printf("Pilihan tidak valid!\n");
        }
    } while (choice != 0);

    return 0;
}
