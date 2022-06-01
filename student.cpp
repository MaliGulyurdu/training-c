#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct student {
	int number;
	int sira;
	int cevap[20];
	int dogru;
	int yanlis;
	int bos;
};

int main()
{
	srand(time(NULL));
	struct student* ogr;

	int i, j;
	int qa[20]; // 0bos 1a 2b 3c 4d

	for (i = 0; i < 20; i++) { // cevap anahtarý
		qa[i] = 1 + rand() % 4;
	}



	ogr = (struct student*)malloc(10 * sizeof(struct student)); // yer ayýrtma

	for (i = 0; i < 10; ++i) // ogrenci bilgileri
	{
		(ogr + i)->number = 1000 + i;
		(ogr + i)->sira = i + 1;

		for (j = 0; j < 20; j++) {
			(ogr + i)->cevap[j] = rand() % 5;
		}


	}


	
	/* Kontrol: for (i = 0; i<10; i++) {
	printf("%d. ogrencinin numarasi %d\n",(ogr+i)->sira,(ogr+i)->number);
	}

	for(i=0;i<20;i++){
	printf("%d\n",qa[i]);
	}


	for (i = 0; i < 10; i++) {
		for (j = 0; j < 20; j++) {
			printf("%d numarali ogrencinin %d. soruya cevabi: %d\n", (ogr + i)->number, (j + 1), (ogr + i)->cevap[j]);
		}
	}
	*/


	// KARÞILAÞTIRMA

	//printf("\n--------------------------- Karsilastirma -------------------------\n");

	for (i = 0; i < 10; i++) {
		(ogr + i)->dogru = 0;
		(ogr + i)->yanlis = 0;
		(ogr + i)->bos = 0;
		for (j = 0; j < 20; j++) {
			if ((ogr+i)->cevap[j] == 0) {
				(ogr + i)->bos++;
			}
			else if ((qa[j] == (ogr + i)->cevap[j])) {
				(ogr + i)->dogru++;
			}
			else { (ogr + i)->yanlis++; }

		}
	}

	// YAZDIRMA

	FILE* sonuclar;
	sonuclar = fopen("Sonuc.txt", "w");
	fprintf(sonuclar, "Sira\tNumara\tDogru\tYanlis\tBos\n");
	for (i = 0; i < 10; i++) {
		fprintf(sonuclar, "%d.\t%d\t%d\t%d\t%d\n", (ogr + i)->sira,(ogr+i)->number,(ogr+i)->dogru,(ogr+i)->yanlis,(ogr+i)->bos);
	}

	fclose(sonuclar);

	

	return 0;
}