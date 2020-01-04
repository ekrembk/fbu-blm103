#include <stdio.h>
#include "veri.h"
#include "tahmin.h"

void girisMesajiniGoster() {
	printf("Yapay Zeka ile Kanser Tespiti\n");
	printf("k Nearest Neighborhood\n");
	printf("-----------------------------\n");
}

int kullaniciTercihiniAl() {
	int secim;

	printf("Tercihinizi girin:\n");
	printf("1) Test verisetini hesapla\n");
	printf("2) Parametre giri�i ile tahminde bulun\n");

	// Kullan�c�n�n se�imini al
	scanf_s("%d", &secim);

	return secim;
}

char* okunabilirSonuc(int sonuc) {
	return sonuc == 2 ? "Hasta de�il" : "Hasta";
}

void testSonuclari() {
	printf("Test sonu�lar�:\n");
	printf("---------------\n");
	struct TestSeti testSeti = testSetiniYukle();
	int basariliTahmin = 0;
	int falsePositive = 0;
	int falseNegative = 0;

	for (int i = 0; i < TEST_VERI_SAYI; i++) {
		int asilSonuc = testSeti.y[i];
		int tahminEdilenSonuc = tahmin(testSeti.X[i]);

		printf("As�l sonu�: %-18s|Tahmin: %-20s\n",
			okunabilirSonuc(asilSonuc),
			okunabilirSonuc(tahminEdilenSonuc));

		if (asilSonuc == tahminEdilenSonuc) {
			basariliTahmin++;
		}
		else if (asilSonuc == 2 && tahminEdilenSonuc == 4) {
			falsePositive++;
		}
		else if (asilSonuc == 4 && tahminEdilenSonuc == 2) {
			falseNegative++;
		}
	}

	printf("\n\n");
	printf("�zet Sonu�lar\n");
	printf("----------------------\n");
	printf("Test say�s�:    %d\n", TEST_VERI_SAYI);
	printf("Do�ru tahmin:   %d\n", basariliTahmin);
	printf("Yanl�� tahmin:  %d\n", TEST_VERI_SAYI - basariliTahmin);
	printf("Accuracy:       %.2f%%\n", ((float)basariliTahmin / (float)TEST_VERI_SAYI) * 100);
	printf("False positive  %d\n", falsePositive);
	printf("False negative  %d\n", falseNegative);
}

void kullaniciGirisiyleTahmin() {
	int clumpThickness;
	int uniformityOfCellSize;
	int uniformityOfCellShape;
	int marginalAdhesion;
	int singleEpithelialCellSize;
	int bareNuclei;
	int blandChromatin;
	int normalNucleoli;
	int mitoses;

	printf("Clump thickness:\n");
	scanf_s("%d", &clumpThickness);
	printf("Uniformity of Cell Size:\n");
	scanf_s("%d", &uniformityOfCellSize);
	printf("Uniformity of Cell Shape:\n");
	scanf_s("%d", &uniformityOfCellShape);
	printf("Marginal Adhesion:\n");
	scanf_s("%d", &marginalAdhesion);
	printf("Single Epithelial Cell Size:\n");
	scanf_s("%d", &singleEpithelialCellSize);
	printf("Bare Nuclei:\n");
	scanf_s("%d", &bareNuclei);
	printf("Bland Chromatin:\n");
	scanf_s("%d", &blandChromatin);
	printf("Normal Nucleoli:\n");
	scanf_s("%d", &normalNucleoli);
	printf("Mitoses:\n");
	scanf_s("%d", &mitoses);

	int X[PARAMETRE_SAYI] = { clumpThickness, uniformityOfCellSize, uniformityOfCellShape, marginalAdhesion, singleEpithelialCellSize, bareNuclei, blandChromatin, normalNucleoli, mitoses };

	printf("Sonu�: %s\n", okunabilirSonuc(tahmin(X)));
}

int main() {
	int secim;

	girisMesajiniGoster();

	while (1) {
		// Kullan�c�n�n tercihini sor
		secim = kullaniciTercihiniAl();

		// Ge�erli bir giri� olmad�k�a kar��lama mesaj� g�ster
		if (secim == 1) {
			testSonuclari();
			break;
		}
		else if (secim == 2) {
			kullaniciGirisiyleTahmin();
			break;
		}
	}

	return 0;
}
