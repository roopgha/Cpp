#include <iostream>
#include <stdio.h>
using namespace std;

class Task {
public:
	float interestRate;
	float afterTaxInterestRate;
	int month;
	int avg;

	void InterestRateCalculator(int year, int savings)
	{
		month = 12 * year;
		avg = month * savings;
		interestRate = (avg * 0.0355f * (month + 1) / 24);
		afterTaxInterestRate = (avg * (0.0355f * (month + 1) / 24) * (1 - 0.154f));
	}

	void Print() {
		cout << "세전 총 금액" << endl;
		printf("%.0f\n", avg + interestRate);
		cout << "세후 총 금액" << endl;
		printf("%.0f\n", avg + afterTaxInterestRate);
	}
};

int main() {
	Task task;
	
	int year;
	int savings;

	cout << "몇 년을 적금할 것인지를 입력하세요" << endl;
	cin >> year;
	cout << "매 월 얼마를 입금할 것인지를 입력하세요" << endl;
	cin >> savings;

	task.InterestRateCalculator(year, savings);
	task.Print();
}