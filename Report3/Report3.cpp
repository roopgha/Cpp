#include <iostream>
#include <stdio.h>

using namespace std;

class User {
public:
	int id;
	string* user_name = nullptr;

	void UserInformation(int id, string name) {
		user_name = new string();
		*user_name = name;
	}
	void UserInformation(const User& rsh) {
		id = rsh.id;
		user_name = new string();
		*user_name = *rsh.user_name;
	}
};

class Calculator_Interest {
public:
	float Tax = 1 - 0.154f;
	float InstallmentSavingsInterest(int sum, int month) {
		return (sum * (0.04f * (month + 1) / 24) * Tax);
	}
	float DepositInterest(int money, int month) {
	return ((money * 0.03f) * Tax);
	}
};

class Calculator {
public:
	int sum;

	Calculator_Interest calInterest;

	float InstallmentSavings(int sum, int month) {
		return sum + (calInterest.InstallmentSavingsInterest(sum, month));
	}

	float Deposit(int money, int month) {
		return money + (calInterest.DepositInterest(money, month));
	}
};

void main() {
	User user;
	Calculator cal;
	int id;
	string name;
	int money;
	int month;
	int sum;
	
	cout << "ID : ";
	cin >> id;
	cout << "이름 : ";
	cin >> name;
	cout << "개월 수 : ";
	cin >> month;
	cout << "매달 넣을 금액 : ";
	cin >> money;

	sum = month * money;
	user.UserInformation(id, name);
	float installmentSavings = cal.InstallmentSavings(sum, month);
	float deposit = cal.Deposit(money,month);
	cout << id << "/" << name << endl;
	printf("적금 : 매월 %d씩 %d개월씩 임급하면 %.0f원\n", money, month, installmentSavings);
	printf("예금 : 매월 %d씩 %d개월씩 임급하면 %.0f원", money, month, deposit);
}