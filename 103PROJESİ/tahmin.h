#ifndef tahmin_h
#define tahmin_h

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "parametreler.h"

struct Komsu {
	float oklid_uzaklik;
	int sonuc;
};

float oklid_uzaklik(int[], int[]);

int karsilastir(const void* komsu1, const void* komsu2);

int tahmin(int X_test[PARAMETRE_SAYI]);

#endif /* tahmin_h */
