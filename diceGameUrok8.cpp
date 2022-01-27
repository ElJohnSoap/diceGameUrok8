/*Игра «кубики». Условие: имеется два игральных кубика
со значениями от 1 до 6. Игра происходит с компьютером,
кубики бросаются поочередно. Побеждает тот, у кого
сумма выпавших очков по итогам пяти бросков больше.
Предусмотрите возможность получения первого хода
человеком или  компьютером. Кубики отображаются
с помощью символов. В конце игры необходимо выводить среднюю сумму по броскам для обоих участников.*/

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
	cout << "Для выбора права первого хода нажмите ENTER" << endl;
	cin.get();
	int fist = rand() % 2;
	int priority = fist;
	cout <<( (fist) ? "Первый ход у железяки! ХА-ХА-ХА" : "Ваш ход первый");
	cout << endl << endl;
	for (int j = 0; j < cols; j++) {
		for (int i = 0; i < rows; i++, priority++) {
			cout << j+1;
			(priority%2) ? cout << " ход ИИ" : cout << " ход человека";
			cout << endl;
			cube(arr[i][j]);
			(i) ? sum2 += arr[i][j] : sum1 += arr[i][j];
			(fist) ? cout << "Сумма очков ИИ = " << sum1 << " Сумма очков человека = " << sum2 << endl << endl :
				     cout << "Сумма очков человека = " << sum1 << " Сумма очков ИИ = " << sum2 << endl << endl;
		}
	}

	if ((fist == 1 && sum1 > sum2) || (fist == 0 && sum2 > sum1))
		cout << "Победил металл!!!";
	else if ((fist == 0 && sum1 > sum2) || (fist == 1 && sum2 > sum1))
		cout << "Юхууу! Ты победил!";
	else cout << "Мир! Труд! Май! (ничья).";
	cout << endl << endl;
	(fist) ? cout << "Средний балл ИИ = " << (double) sum1/5 << " Средний балл человека = " << (double)sum2 / 5 << endl << endl :
		cout << "Средний балл человека = " << (double)sum1 / 5 << " Средний балл ИИ = " << (double)sum2 / 5 << endl << endl;
}
