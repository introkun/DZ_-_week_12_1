#include <iostream>
#include <ctime>
using namespace std;

void numberGenerator(int mass[], int size);
void dismantlingOf(int mass[], int size, int userNumber);
int chekcUserEnter();
void comparingNumbers(int unknownNumber[], int userNumber[], int size, int* pBools, int* pCows);

int main()
{
	const int size = 4;
	int unknownNumber[size];
	int userNumberMass[size];
	int userEnter;
	int bools = 0;
	int cows = 0;
	int attemptsCounter = 0;
	numberGenerator(unknownNumber, size);
	cout << "Komp'jyter zagadal chetirehznachnoe chislo, poprbyjte ego ygadat'." << endl
		<< "Vam bydyt dani podskazki takie kak \"biki\" - ygadannie chisla," << endl
		<< "i \"korovi\" - ygadannie chisla, stojashie na svoih mestah." << endl
		<< "Vvedite predpologaemoe chislo: ";
	do
	{
		userEnter = chekcUserEnter();
		dismantlingOf(userNumberMass, size, userEnter);
		comparingNumbers(unknownNumber, userNumberMass, size, &bools, &cows);
		attemptsCounter++;
	} while (cows < 4);
	cout << "Pozdravliaem, vi ygadali chislo zagadannoe komp'jyterom s " << attemptsCounter << " popitki" << endl;
	return 0;
}


void numberGenerator(int mass[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		mass[i] = rand() % 9 + 1;
	}
}

void dismantlingOf(int mass[], int size, int userNumber)
{
	for (int i = size - 1; i >= 0; i--)
	{
		mass[i] = userNumber % 10;
		userNumber /= 10;
	}
}

int chekcUserEnter()
{
	int userEnter;
	do
	{
		cin >> userEnter;
		if (userEnter < 1000)
		{
			cout << "Chislo ne dolgno bit' men'she 1000 i ne dolgno nachinat'sia s \"0\"." << endl
				<< "Povtorite vvod:";
			continue;
		}
		else if (userEnter > 9999)
		{
			cout << "Chislo ne dolgno bit' bol'she 9999." << endl
				<< "Povtorite vvod:";
			continue;
		}
	} while (userEnter < 1000 || userEnter > 9999);
	return userEnter;
}

void comparingNumbers(int unknownNumber[], int userNumber[], int size, int* pBools, int* pCows)
{
	*pCows = 0;
	*pBools = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (userNumber[i] == unknownNumber[j] && i == j)
			{
				*pCows += 1;
			}
			else if (userNumber[i] == unknownNumber[j])
			{
				*pBools += 1;
			}
		}
	}
	cout << "V vashem chisle " << *pCows << " korow i " << *pBools << " bikov" << endl;
}