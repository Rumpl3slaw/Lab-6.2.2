#include <iostream>
#include <iomanip>

using namespace std;

void Create(int* a, const int n, const int Low, const int High,int i);
void Cout(int* a, const int n,int i);
int Condition(int* a, const int n,int i ,int S);
int Sum(int* a, const int n,int i , int S);
double Avarage(double  Q, double value);

int main()
{
	srand((unsigned)time(NULL));
	const int n = 30;
	int a[n];

	int Low = -30;
	int High = 30;

	Create(a, n, Low, High,0);

	cout << "Masyv:" << endl;
	cout << endl;
	Cout(a, n,0);
	cout << endl;

	int Q = Condition(a, n,0,0);
	cout << "Modyfikovanyi Masyv:" << endl;
	cout << endl;
	Cout(a, n,0);
	cout << endl;

	int value = Sum(a, n,0,0);
	cout << "Suma elementiv z kriteriyu=" << value << endl;
	cout << endl;
	cout << "Kil`kist` elementiv z kriteriyu=" << Q << endl;
	double Av = Avarage(Q, value);
	cout << "Seredne aryfmetychne neparnyh chysel=" << setprecision(1) << Av << endl;

	return 0;
}
void Create(int* a, const int n, const int Low, const int High,int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < n - 1)
		Create(a, n, Low, High, i + 1);
}
void Cout(int* a, const int n,int i)
{
	cout << setw(5) << a[i];
	if (i < n - 1)
		Cout(a, n, i + 1);
	else;
}
int Condition(int* a, const int n,int i,int S)
{
	if (a[i] < 0 && a[i] % 2 == 0 || a[i] > 0 && a[i] % 2 == 0)
		a[i] = 0;
	else
		S += 1;
	if (i < n - 1)
		return Condition(a, n, i + 1, S);
	else
	return S;
}
int Sum(int* a, const int n,int i,int S)
{
	S += a[i];
	if (i < n - 1)
		return Sum(a, n, i + 1, S);
     else
	return S;
}
double  Avarage(double Q, double value)
{
	double A = value / Q;
	return A;
}