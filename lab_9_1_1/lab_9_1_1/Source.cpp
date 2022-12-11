#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Spec { COMPUTERSCIENCE, IT, ECONOMY, PHYSICS, ART };

string specStr[] = { "����'����� �����", "�����������", "���������� �� ��������", "������ �� �����������", "������� ��������" };
struct Student
{
	string prizv;
	unsigned kurs;
	Spec spec;
	unsigned physicsGrades;
	unsigned mathsGrades;
	unsigned ITGrades;
	
};

void Create(Student* s, const int N);
void Sort(Student* s, const int N);
void Print(Student* s, const int N);
int Count(Student* s, const int N);
void LowestAverage(Student* s, const int N);

int main()
{ 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 

	int N;
	cout << "������ N: "; cin >> N;

	Student* s = new Student[N];
	Create(s, N);
	Sort(s, N);
	Print(s, N);
	cout << "ʳ������ ��������, ������� ��� ���� ������ �� 4: " << Count(s, N) << endl;
	LowestAverage(s, N);
	return 0;
}

void Create(Student * s, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "��������� � " << i + 1 << ":" << endl;
		cin.get(); 
		cin.sync(); 

		cout << " �������: "; getline(cin, s[i].prizv);
		cout << " ����: "; cin >> s[i].kurs;
		cout << " ������������ (0 - ����'����� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - ������ �� �����������, 4 - ������� ��������): ";
		cin >> spec;
		cout << " ������ � ������: "; cin >> s[i].physicsGrades;
		cout << " ������ � ����������: "; cin >> s[i].mathsGrades;
		cout << " ������ � �����������: "; cin >> s[i].ITGrades;
		s[i].spec = (Spec)spec;
		cout << endl;
	}
}
void Print(Student* s, const int N)
{
	cout << "=================================================================================================================="
		<< endl;
	cout << "| �  | �������    | ����| ������������          | ������ � ������ | ������ � ���������� | ������ � ����������� |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(12) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << " "
			<< "| " << setw(23) << left << specStr[s[i].spec]
			<< "| " << setw(15) << right << s[i].physicsGrades << " "
			<< "| " << setw(19) << left << s[i].mathsGrades << " "
			<< "| " << setw(20) << right << s[i].ITGrades << " " << "|";
		cout << endl;
	}
	cout << "================================================================================================================="
		<< endl;
	cout << endl;
}

void Sort(Student* s, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++)
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if (s[i1].prizv > s[i1 + 1].prizv)
			{
				tmp = s[i1];
				s[i1] = s[i1 + 1];
				s[i1 + 1] = tmp;
			}
}

int Count(Student* s, const int N)
{
	int k = 0;
	for (int i = 0; i < N; i++)

		if (((s[i].mathsGrades + s[i].ITGrades + s[i].physicsGrades)/3) < 4)
		{
			k++;
		}

	return k;
}

void LowestAverage(Student *s, const int N)
{
	double MathsAv;
	double ITAv;
	double PhysicsAv;

	int m = 0;
	int p = 0;
	int t = 0;

	for (int i = 0; i < N; i++) {

		m += s[i].mathsGrades;
		p += s[i].physicsGrades;
		t += s[i].ITGrades;
	}

	MathsAv =  m / N;
	PhysicsAv = p / N;
	ITAv = t / N;

	double min;
	if (PhysicsAv < MathsAv && PhysicsAv < ITAv) {

		min = PhysicsAv;
		cout << "��������� ������� ��� � ������, �� ������� " << min;

	}

	else if (ITAv < MathsAv && ITAv < PhysicsAv) {

		min = ITAv;
		cout << "��������� ������� ��� � �����������, �� ������� " << min;
	
	}

	else {

		min = MathsAv;
		cout << "��������� ������� ��� � ����������, �� ������� " << min;

	}

}