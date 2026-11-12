#include <stdio.h>

char tahta[3][3];
char oyuncu = 'X';

// Tahtayı başlangıçta boşluklarla doldur
void tahtayiHazirla() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tahta[i][j] = ' ';
        }
    }
}

// Tahtayı ekrana yazdır
void tahtayiGoster() {
    printf("\n");
    printf("  1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tahta[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf(" ---+---+---\n");
    }
    printf("\n");
}

// Kazanma kontrolü
char kazananiKontrolEt() {
    // Satırlar ve sütunlar
    for (int i = 0; i < 3; i++) {
        if (tahta[i][0] == tahta[i][1] && tahta[i][0] == tahta[i][2] && tahta[i][0] != ' ')
            return tahta[i][0];
        if (tahta[0][i] == tahta[1][i] && tahta[0][i] == tahta[2][i] && tahta[0][i] != ' ')
            return tahta[0][i];
    }
    // Köşegenler
    if (tahta[0][0] == tahta[1][1] && tahta[0][0] == tahta[2][2] && tahta[0][0] != ' ')
        return tahta[0][0];
    if (tahta[0][2] == tahta[1][1] && tahta[0][2] == tahta[2][0] && tahta[0][2] != ' ')
        return tahta[0][2];

    return ' ';
}

// Boş yer kalıp kalmadığını kontrol et
int berabereKontrolEt() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tahta[i][j] == ' ') return 0;
        }
    }
    return 1;
}

int main() {
    int satir, sutun;
    char kazanan = ' ';

    tahtayiHazirla();

    while (kazanan == ' ' && !berabereKontrolEt()) {
        tahtayiGoster();
        printf("Oyuncu %c, lutfen satir (1-3) ve sutun (1-3) secin: ", oyuncu);
        if (scanf("%d %d", &satir, &sutun) != 2) {
            printf("Gecersiz giris!\n");
            while (getchar() != '\n'); // Buffer temizle
            continue;
        }

        satir--;
        sutun--;

        if (satir >= 0 && satir < 3 && sutun >= 0 && sutun < 3 && tahta[satir][sutun] == ' ') {
            tahta[satir][sutun] = oyuncu;
            kazanan = kazananiKontrolEt();
            if (kazanan == ' ') {
                oyuncu = (oyuncu == 'X') ? 'O' : 'X';
            }
        } else {
            printf("Bu hamle gecersiz veya dolu, tekrar deneyin.\n");
        }
    }

    tahtayiGoster();

    if (kazanan != ' ') {
        printf("Tebrikler! Oyuncu %c kazandi!\n", kazanan);
    } else {
        printf("Oyun berabere bitti!\n");
    }

    return 0;
}

