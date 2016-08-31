#include <iostream>
#include <ctime>
using namespace std;

const int sizeMass = 10;

void processingMatrix(int mass[sizeMass][sizeMass], int maxValue, int minValue);
void processingMatrix(int mass[sizeMass][sizeMass]);
void processingMatrix(int mass[sizeMass][sizeMass], char dioganal);
void processingMatrix(int mass[sizeMass][sizeMass], short line);

int main()
{
	int mass[sizeMass][sizeMass];
	int maxValue;
	int minValue;
	short line;
	short userEnter;
	char dioganal;
	cout << "Vvedite razmer maksimal'nogo znachenija v generiryemom massive: ";
	do
	{
		cin >> maxValue;
		if (maxValue > 100)
		{
			cout << "Maksimal'noe znachenie massiva ne dolgno bit' bol'she 100." << endl <<
				"Povtorite vvod: ";
		}
		else if (maxValue < -98)
		{
			cout << "Maksimal'noe znachenie massiva ne dolgno bit' men'she -98." << endl <<
				"Povtorite vvod: ";
		}
	} while (maxValue < -98 || maxValue > 100);
	cout << "Vvedite razmer minimal'nogo znachenija v generiryemom massive: ";
	do
	{
		cin >> minValue;
		if (minValue >= maxValue)
		{
			cout << "Minimal'noe znachenie massiva ne dolgno bit' bol'she maksimal'nogo." << endl <<
				"Povtorite vvod: ";
		}
		else if (minValue < -99)
		{
			cout << "Minimal'noe znachenie massiva ne dolgno bit' men'she -99." << endl <<
				"Povtorite vvod: ";
		}
		if (minValue > maxValue)
		{
			cout << "Minimal'noe znachenie massiva ne dolgno bit' bol'she 99." << endl <<
				"Povtorite vvod: ";
		}
	} while (minValue >= maxValue || minValue < -99 || minValue > 99);
	processingMatrix(mass, maxValue, minValue);
	processingMatrix(mass);
	while (true)
	{
		cout << "1. Poisk minimyma i maksimym v glavnih diogonaliah massiva" << endl
			<< "2. Sortirovka strok massiva." << endl
			<< "0. Vihod." << endl
			<< "Vvedite nomer neobhodimogo dejstvija: ";
		do
		{
			cin >> userEnter;
			if (userEnter < 0 || userEnter > 2)
			{
				cout << "Ne korektnij vvod, vedite nomer punkta iz ykazannogo spiska: ";
			}
		} while (userEnter < 0 || userEnter > 2);
		switch (userEnter)
		{
		case 1:
			cout << "Vvedite \"\\\" ili \"/\" dli vibora diagonali: ";
			do
			{
				cin >> dioganal;
				if (dioganal != '\\' && dioganal != '/')
				{
					cout << "ne korektnij vvod, pogalyjsta, vvedite \"\\\" ili \"/\" dlia vibora diagonali: ";
				}
			} while (dioganal != '\\' && dioganal != '/');
			processingMatrix(mass, dioganal);
			break;
		case 2:
			cout << "Vvedite nomer stroki, dlia sortirovki (ot 1 do " << sizeMass << "): ";
			do
			{
				cin >> line;
				if (line < 1 || line > sizeMass)
				{
					cout << "Ne korektnij vvod, vvedite nomer stroki, ot 1 do " << sizeMass << ": ";
				}
			} while (line < 1 || line > sizeMass);
			processingMatrix(mass, line);
			processingMatrix(mass);
			break;
		default:
			cout << "Vi vibrali vihod." << endl;
			return 0;
		}
	}
	return 0;
}

void processingMatrix(int mass[sizeMass][sizeMass], int maxValue, int minValue)
{
	minValue *= -1;
	maxValue += minValue;
	srand(25);
	for (int i = 0; i < sizeMass; i++)
	{
		for (int j = 0; j < sizeMass; j++)
		{
			mass[i][j] = (rand() % maxValue) - minValue;
		}
	}
}

void processingMatrix(int mass[sizeMass][sizeMass])
{
	for (int i = 0; i < sizeMass; i++)
	{
		for (int j = 0; j < sizeMass; j++)
		{
			int presentValue = mass[i][j];
			cout << " ";
			if (presentValue >= 0 && presentValue < 10)
			{
				cout << "  " << presentValue;
			}
			else if (presentValue < 0 && presentValue > -10 || presentValue >= 10 && presentValue < 100)
			{
				cout << " " << presentValue;
			}
			else
			{
				cout << presentValue;
			}
		}
		cout << endl;
	}
}

void processingMatrix(int mass[sizeMass][sizeMass], char dioganal)
{
	int maxValue = -100;
	int minValue = 100;

	for (int i = 0; i < sizeMass; i++)
	{
		if (dioganal == '\\')
		{
			maxValue = (mass[i][i] >= maxValue) ? mass[i][i] : maxValue;
			minValue = (mass[i][i] <= minValue) ? mass[i][i] : minValue;
		}
		else if (dioganal == '/')
		{
			maxValue = (mass[sizeMass - 1 - i][i] >= maxValue) ? mass[sizeMass - 1 - i][i] : maxValue;
			minValue = (mass[sizeMass - 1 - i][i] <= minValue) ? mass[sizeMass - 1 - i][i] : minValue;
		}
	}
	cout << "maximal'noe znachenie vibranoj dioganali: " << maxValue << endl <<
		"minimal'noe znachenie vibranoj diagonali: " << minValue << endl;
}

void processingMatrix(int mass[sizeMass][sizeMass], short line)
{
	int buff;
	line -= 1;
	for (int i = 1; i < sizeMass; i++)
	{
		int permutationsÑounter = 0;
		for (int j = 0; j < sizeMass - i; j++)
		{
			if (mass[line][j] < mass[line][j + 1])
			{
				buff = mass[line][j + 1];
				mass[line][j + 1] = mass[line][j];
				mass[line][j] = buff;
				permutationsÑounter++;
			}
		}
		if (permutationsÑounter == 0)
		{
			break;
		}
	}

}