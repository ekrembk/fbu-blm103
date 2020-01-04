#include "veri.h"

struct EgitimSeti egitimSetiniYukle() {
	struct EgitimSeti set;

	FILE* fp;

	fopen_s(&fp, EGITIM_DOSYA, "r");

	for (int i = 0; i < EGITIM_VERI_SAYI; i++) {
		char str[255];
		fgets(str, 255, fp);

		int _gozlemNumarasi;
		int clumpThickness;
		int uniformityOfCellSize;
		int uniformityOfCellShape;
		int marginalAdhesion;
		int singleEpithelialCellSize;
		int bareNuclei;
		int blandChromatin;
		int normalNucleoli;
		int mitoses;
		int sonuc;

		sscanf_s(str, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &_gozlemNumarasi, &clumpThickness, &uniformityOfCellSize, &uniformityOfCellShape, &marginalAdhesion, &singleEpithelialCellSize, &bareNuclei, &blandChromatin, &normalNucleoli, &mitoses, &sonuc);

		set.X[i][0] = clumpThickness;
		set.X[i][1] = uniformityOfCellSize;
		set.X[i][2] = uniformityOfCellShape;
		set.X[i][3] = marginalAdhesion;
		set.X[i][4] = singleEpithelialCellSize;
		set.X[i][5] = bareNuclei;
		set.X[i][6] = blandChromatin;
		set.X[i][7] = normalNucleoli;
		set.X[i][8] = mitoses;

		set.y[i] = sonuc;
	}

	fclose(fp);

	return set;
}

struct TestSeti testSetiniYukle() {
	struct TestSeti set;

	FILE* fp;

	fopen_s(&fp, TEST_DOSYA, "r");

	for (int i = 0; i < TEST_VERI_SAYI; i++) {
		char str[255];
		fgets(str, 255, fp);

		int _gozlemNumarasi;
		int clumpThickness;
		int uniformityOfCellSize;
		int uniformityOfCellShape;
		int marginalAdhesion;
		int singleEpithelialCellSize;
		int bareNuclei;
		int blandChromatin;
		int normalNucleoli;
		int mitoses;
		int sonuc;

		sscanf_s(str, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &_gozlemNumarasi, &clumpThickness, &uniformityOfCellSize, &uniformityOfCellShape, &marginalAdhesion, &singleEpithelialCellSize, &bareNuclei, &blandChromatin, &normalNucleoli, &mitoses, &sonuc);

		set.X[i][0] = clumpThickness;
		set.X[i][1] = uniformityOfCellSize;
		set.X[i][2] = uniformityOfCellShape;
		set.X[i][3] = marginalAdhesion;
		set.X[i][4] = singleEpithelialCellSize;
		set.X[i][5] = bareNuclei;
		set.X[i][6] = blandChromatin;
		set.X[i][7] = normalNucleoli;
		set.X[i][8] = mitoses;

		set.y[i] = sonuc;
	}

	fclose(fp);

	return set;
}
