/*
������ : �����
�����Ͻ� : 20181128

*/

#include<iostream>
#include<cstring>

using namespace std;
const int NAME_LEN = 20; //���

void menu(void); //���θŴ�
void making_account(void); //���»���
void deposit_money(void); //�Ա�
void withdraw_money(void); //���
void show_all_account_info(void); // �ܾ���ȸ
 
enum MyEnum
{
	MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT
}; //������

typedef struct {
	int account_ID; //���¹�ȣ
	int balance; //�ܾ�
	char customer_name[NAME_LEN]; //�̸�
}Account;

Account account_array[100]; //Account �迭 ��������
int account_number = 0;

int main(void) {
	int choice;

	while (1) {
		menu();
		cout << "���� : ";
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
			cout << "���ÿ���" <<endl;
		}
	}
	return 0;

}
void menu(void) {
	cout << "////----�޴�----////" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void making_account(void) {
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "���� ID :"; cin >> id;
	cout << "�̸� : "; cin >> name;
	cout << "�Ա� (���� :��) : "; cin >> balance;
	cout << endl;

	account_array[account_number].account_ID = id;
	account_array[account_number].balance = balance;
	strcpy_s(account_array[account_number].customer_name, name);
	account_number++;
}
void deposit_money(void) {
	int money;
	int id;
	cout << "[�Ա�]" << endl;
	cout << "���� ID : "; cin >> id;
	cout << "�Աݾ� : "; cin >> money;

	for (int i = 0; i < account_number; i++) {
		if (account_array[i].account_ID == id) {
			account_array[i].balance += money;
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;

}
void withdraw_money(void) {
	int money;
	int id;
	cout << "[���]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "��ݾ� : "; cin >> money;

	for (int i = 0; i << account_number; i++) {
		if (account_array[i].account_ID == id) {
			if (account_array[i].balance < money) {
				cout << "�ܾ׺���" << endl << endl;
				return;
			}
			account_array[i].balance -= money;
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�" << endl << endl;

}

void show_all_account_info(void) {
	for (int i = 0; i < account_number; i++)
	{
		cout << "����ID :" << account_array[i].account_ID << endl;
		cout << "�̸� : " << account_array[i].customer_name << endl;
		cout << "�ܾ� : " << account_array[i].balance << endl;
	}
}
