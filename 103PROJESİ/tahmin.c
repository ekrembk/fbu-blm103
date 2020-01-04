#include "tahmin.h"
#include "veri.h"

float oklid_uzaklik(int a[], int b[]) {
	int total = 0, diff;
	for (int i = 0; i < PARAMETRE_SAYI; i++) {
		diff = b[i] - a[i];
		total += diff * diff;
	}

	return (float)sqrt(total);
}

int karsilastir(const void* komsu1, const void* komsu2) {
	struct Komsu* k1 = (struct Komsu*)komsu1;
	struct Komsu* k2 = (struct Komsu*)komsu2;

	return (k1->oklid_uzaklik > k2->oklid_uzaklik) - (k1->oklid_uzaklik < k2->oklid_uzaklik);
}

int tahmin(int X_test[PARAMETRE_SAYI]) {
	struct EgitimSeti set = egitimSetiniYukle();
	struct Komsu komsular[EGITIM_VERI_SAYI];

	// Uzakl�klar� hesapla
	for (int i = 0; i < EGITIM_VERI_SAYI; i++) {
		komsular[i].oklid_uzaklik = oklid_uzaklik(X_test, set.X[i]);
		komsular[i].sonuc = set.y[i];
	}

	// Kom�ular� uzakl��a g�re s�rala (k���kten b�y��e)
	qsort(komsular, EGITIM_VERI_SAYI, sizeof(struct Komsu), karsilastir);

	// En yak�ndaki N kom�uyu al ve ka� hasta
	int hasta = 0;
	int hasta_degil = 0;

	for (int i = 0; i < N; i++) {
		if (komsular[i].sonuc == 4) {
			hasta++;
		}
		else {
			hasta_degil++;
		}
	}

	// En yak�n N kom�uda hastalar hasta olmayanlardan fazla m�?
	if (hasta > hasta_degil) {
		return 4;
	}

	return 2;
}
