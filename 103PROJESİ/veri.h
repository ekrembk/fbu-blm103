#ifndef egitim_h
#define egitim_h

#include <stdio.h>
#include "parametreler.h"

struct EgitimSeti {
	int X[EGITIM_VERI_SAYI][PARAMETRE_SAYI];
	int y[EGITIM_VERI_SAYI];
};

struct EgitimSeti egitimSetiniYukle(void);

struct TestSeti {
	int X[TEST_VERI_SAYI][PARAMETRE_SAYI];
	int y[TEST_VERI_SAYI];
};

struct TestSeti testSetiniYukle(void);


#endif /* egitim_h */



