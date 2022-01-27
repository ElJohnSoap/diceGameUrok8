/*���� �������. �������: ������� ��� ��������� ������
�� ���������� �� 1 �� 6. ���� ���������� � �����������,
������ ��������� ����������. ��������� ���, � ����
����� �������� ����� �� ������ ���� ������� ������.
������������� ����������� ��������� ������� ����
��������� ���  �����������. ������ ������������
� ������� ��������. � ����� ���� ���������� �������� ������� ����� �� ������� ��� ����� ����������.*/

#include <iostream>
using namespace std;
void diceGame();
void cube(int a);

int main()
{
	setlocale(LC_ALL, "ru");
	//cube(2);
	diceGame();
	return 0;

}

void cube(int a) {

	cout << "  ________" << endl;
	cout << " /_______/|" << endl;
	cout << " |       ||" << endl;
	cout << " |   "<< a << "   ||" << endl;
	cout << " |_______|/" << "\t";
	system("pause");

}

void diceGame() {
	const int rows = 2, cols = 5;
	int arr[rows][cols], sum1=0, sum2=0;
	srand(time(0));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = rand() % 7;
			cout << arr[i][j] << "\t";
		}
		cout << endl;

	}
	cout << "��� ������ ����� ������� ���� ������� ENTER" << endl;
	cin.get();
	int fist = rand() % 2;
	int priority = fist;
	cout <<( (fist) ? "������ ��� � ��������! ��-��-��" : "��� ��� ������");
	cout << endl << endl;
	for (int j = 0; j < cols; j++) {
		for (int i = 0; i < rows; i++, priority++) {
			cout << j+1;
			(priority%2) ? cout << " ��� ��" : cout << " ��� ��������";
			cout << endl;
			cube(arr[i][j]);
			(i) ? sum2 += arr[i][j] : sum1 += arr[i][j];
			(fist) ? cout << "����� ����� �� = " << sum1 << " ����� ����� �������� = " << sum2 << endl << endl :
				     cout << "����� ����� �������� = " << sum1 << " ����� ����� �� = " << sum2 << endl << endl;
		}
	}

	if ((fist == 1 && sum1 > sum2) || (fist == 0 && sum2 > sum1))
		cout << "������� ������!!!";
	else if ((fist == 0 && sum1 > sum2) || (fist == 1 && sum2 > sum1))
		cout << "�����! �� �������!";
	else cout << "���! ����! ���! (�����).";
	cout << endl << endl;
	(fist) ? cout << "������� ���� �� = " << (double) sum1/5 << " ������� ���� �������� = " << (double)sum2 / 5 << endl << endl :
		cout << "������� ���� �������� = " << (double)sum1 / 5 << " ������� ���� �� = " << (double)sum2 / 5 << endl << endl;
}
