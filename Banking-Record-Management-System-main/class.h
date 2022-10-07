// class used

class Account
{
private:
	int acc_no;
	char name[50];
	int deposit;
	char type;

public:
	void create_account(); // func to get data from user

	void show_account(); // func to show data on console

	void modify(); // func to change previous data

	void deposit_money(int); // func to add money to account

	void draw(int); // func to withdraw from account

	void report(); // func to show data in tabular form

	int retaccno(); // func to return acc no

	int retdeposit(); // func to return balance

	char rettype(); // func to return type of acc (c/s)
};