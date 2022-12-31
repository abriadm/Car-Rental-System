#include <iostream>
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib>

using namespace std;

struct car
{
	char plate_num[10];
	char brand[20];
	char model[20];
	float capacity;
	char colour[20];
	float rate_per_hour;
	float rate_per_half;
	float rate_per_day;
	char transmission[6];
};

struct customer
{
	int id;
	char name[100];
	char phone[15];
	char ic[15];
	char address[1500];
};

struct pass
{
	int ID;
	char passWord[20];
};

pass userPass[1000];
car rent[1000];
customer cust[1000];
car avail[1000];

void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

const string currentDateTime()
{
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%d/%m/%Y Time: %x", &tstruct);

	return buf;
}

const string Date()
{
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%d/%m/%Y Time: %x", &tstruct);

	return buf;
}

void time()
{
	int i = 0;

	while (i < 5)
	{
		Boarder();
		gotoxy(20,20);
		cout << "\n\n\n\n\n\t |\t\t\t\tDate: " << currentDateTime() << endl;
		Sleep(900);
		system("cls");
		i++;
	}
	menu();
}

void date()
{
	cout << "\n\t |\t\t\t\t\t\tDate: " << Date() << endl;
}

void readUserPass()
{
	ifstream ifs;
	ifs.open("UserPass.txt");

	int i;
	while (!ifs.eof())
	{
		ifs >> userPass[i].ID;
		ifs.ignore();
		ifs.getline(userPass[i].passWord,20);
		i++;
	}
	ifs.close();
}

void password()
{
	Boarder();
	countUser();
	string password;
	char c;
	gotoxy(40,20);
	cout << "\n\n\n\n\t |\t\t\tPassword: ";

	while (c != '\r') //Loop until 'Enter' is pressed
	{
		c = getch();
		if (c == 0)
		{
			switch (getch())
			{
			default:
				break;
			};
		}
		else if (c == '\b') // If the 'Backspace' key is pressed
		{
			if (password.size() != 0) // If the password string contains data, erase last character
			{
				cout << "\b \b";
				password.erase(password.size() - 1,1);
			}
			continue;
		}
		else if (c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') // If user enters 1-9, a-z, or A-z, add it to the password and display an asterisk
		{
			password += c;
			cout << "*";
		}
		else
		{
			continue;
		}
		for (int i = 0; i < countUser(); i++)
		{
			if (password.compare(userPass[i].passWord) == 0)
			{
				system("cls");
				load_CHECK();
				admin();
			}
		}
		if (password == 'a')
		{
			system("cls");
			load_CHECK();
			admin();
		}
		else
		{
			cout << "\n\t |\t\t\tWrong Password... Call Administrator";
			cout << "\n\t |\t\t\tReturning to Main Menu..." << endl;
			cout << "\n\t |\t\t\t";
			Sleep(1000);
			cout << "\n\t |\t\t\tPress Enter to Continue.";
			cout << "\n\t |\t\t\t";
			getch();
			menu();
		}
	}
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void load()
{
	Boarder();
	int timer = 5 + rand() % 20;
	int row, col, r, c, q;
	gotoxy(60,36);
	for (r = 1; r < timer; r++)
	{
		for (q = 0; q < 100000000; q++); // to dislay character slowly
		printf("%c", 177);
	}
	Sleep(100);
	system("cls");
}

void load_CHECK()
{
	Boarder();
	int timer = rand() % 5 + 1;
	int row, col, r, c, q;
	gotoxy(65,34);
	printf("LOG IN....");
	gotoxy(60, 36);
	for (r = 1; r < timer; r++)
	{
		for (q = 0; q < 100000000; q++); // to display character slowly
		printf("%c", 177);
	}
	Sleep(100);
	system("cls");
}

int main()
{

	return 0;
}