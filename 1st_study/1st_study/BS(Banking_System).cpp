/*
제작자 : 양상준
제작일시 : 20181128

*/

#include<iostream>
#include<cstring>

using namespace std;
const int NAME_LEN = 20; //상수

void menu(void); //메인매뉴
void making_account(void); //계좌생성
void deposit_money(void); //입금
void withdraw_money(void); //출금
void show_all_account_info(void); // 잔액조회
 
enum MyEnum
{
	MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT
}; //열거형

typedef struct {
	int account_ID; //계좌번호
	int balance; //잔액
	char customer_name[NAME_LEN]; //이름
}Account;

Account account_array[100]; //Account 배열 공간설정
int account_number = 0;

int main(void) {
	int choice;

	while (1) {
		menu();
		cout << "선택 : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE :
			making_account();
			break;
		case DEPOSIT :
			deposit_money();
			break;
		case WITHDRAW :
			withdraw_money();
			break;
		case INQUIRE :
			show_all_account_info();
			break;
		case EXIT :
			return 0;
		default:
			cout << "선택오류" <<endl;
		}
	}
	return 0;

}
void menu(void) {
	cout << "////----메뉴----////" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void making_account(void) {
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌 ID :"; cin >> id;
	cout << "이름 : "; cin >> name;
	cout << "입금 (단위 :원) : "; cin >> balance;
	cout << endl;

	account_array[account_number].account_ID = id;
	account_array[account_number].balance = balance;
	strcpy_s(account_array[account_number].customer_name, name);
	account_number++;
}
void deposit_money(void) {
	int money;
	int id;
	cout << "[입금]" << endl;
	cout << "계좌 ID : "; cin >> id;
	cout << "입금액 : "; cin >> money;

	for (int i = 0; i < account_number; i++) {
		if (account_array[i].account_ID == id) {
			account_array[i].balance += money;
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;

}
void withdraw_money(void) {
	int money;
	int id;
	cout << "[출금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "출금액 : "; cin >> money;

	for (int i = 0; i << account_number; i++) {
		if (account_array[i].account_ID == id) {
			if (account_array[i].balance < money) {
				cout << "잔액부족" << endl << endl;
				return;
			}
			account_array[i].balance -= money;
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다" << endl << endl;

}

void show_all_account_info(void) {
	for (int i = 0; i < account_number; i++)
	{
		cout << "계좌ID :" << account_array[i].account_ID << endl;
		cout << "이름 : " << account_array[i].customer_name << endl;
		cout << "잔액 : " << account_array[i].balance << endl;
	}
}
