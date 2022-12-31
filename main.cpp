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

int main()
{

	return 0;
}