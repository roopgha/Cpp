#include <iostream>
#include <stdio.h>
using namespace std;

class Problem {
public:
	float interestRate;
	float afterTaxInterestRate;
	int month;
	int avg;
	float PriceOfMoney = 0;

	void Answer(int answer) {

		if (answer == 0) {
			PriceOfMoney = 0.03f;
		}
		else if (answer == 1) {
			PriceOfMoney = 0.04f;
		}

	}

	void InterestRateCalculator(int year, int savings)
	{
		month = 12 * year;
		avg = month * savings;
		interestRate = (avg * PriceOfMoney * (month + 1) / 24);
		afterTaxInterestRate = (avg * (PriceOfMoney * (month + 1) / 24) * (1 - 0.154f));
	}

	void Print() {
		cout << "세전 총 금액" << endl;
		printf("%.0f\n", avg + interestRate);
		cout << "세후 총 금액" << endl;
		printf("%.0f\n", avg + afterTaxInterestRate);
	}
};

int main() {
	Problem problem;
	
	int year;
	int savings;
	int answer;

	cout << "어떤 적금을 원하시나요? (0 : 일반 적금, 1 : 특판 적금)" << endl;
	cin >> answer;
	report1.Answer(answer);

	cout << "몇 년을 적금할 것인지를 입력하세요" << endl;
	cin >> year;
	cout << "매 월 얼마를 입금할 것인지를 입력하세요" << endl;
	cin >> savings;

	problem.InterestRateCalculator(year, savings);
	problem.Print();
}