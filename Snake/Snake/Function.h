#pragma once
#include <iostream>
#include <windows.h>
#include "mylib.h"
#include<fstream>
#include <MMsystem.h>
#define MAX 100
using namespace std;
int sl = 4;
void ve_tuong_tren();
void ve_tuong_duoi();
void ve_tuong_phai();
void ve_tuong_trai();
void ve_tuong();
void show_diem();
void khoi_tao_ran(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);
void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int& xqua, int& yqua);
void them(int a[], int x);
void xoa(int a[], int vt);
void xoa_du_lieu_cu(int toadox[], int toadoy[]);
bool kt_ran_cham_tuong(int x0, int y0);
bool kt_ran_cham_duoi(int toadox[], int toadoy[]);
bool kt_gameover(int toadox[], int toadoy[]);
void tao_qua(int& xqua, int& yqua, int toadox[], int toadoy[]);
bool kt_ran_de_qua(int toadox[], int toadoy[], int xqua, int yqua);
bool kt_ran_an_qua(int x0, int y0, int xqua, int yqua);
void Menu();
void Run_Game();
void luu_diem_cao();
void xuat_diem_cao();
void end_game(int toadox[], int toadoy[]);
int reset_diem();
int reset_sl();
void reset();
int diem = 0;
int diemcao;
int choose_lever = 0;
#include "Function.h"
void ve_tuong_tren()
{
	int x = 10; int y = 1;
	while (x < 100)
	{
		gotoXY(x, y);
		cout << char(196);
		x++;
	}
}
void ve_tuong_duoi()
{
	int x = 10; int y = 26;
	while (x < 100)
	{
		gotoXY(x, y);
		cout << char(196);
		x++;
	}
}
void ve_tuong_phai()
{
	int x = 10; int y = 1;
	while (y < 26)
	{
		gotoXY(x, y);
		cout << char(179);
		y++;
	}
}
void ve_tuong_trai()
{
	int x = 100; int y = 1;
	while (y < 26)
	{
		gotoXY(x, y);
		cout << char(179);
		y++;
	}
}
void ve_tuong()
{
	SetColor(3);
	ve_tuong_tren();
	ve_tuong_duoi();
	ve_tuong_phai();
	ve_tuong_trai();
	gotoXY(10, 1);
	cout << char(218);
	gotoXY(100, 1);
	cout << char(191);
	gotoXY(10, 26);
	cout << char(192);
	gotoXY(100, 26);
	cout << char(217);
	SetColor(7);
}
void show_diem()
{
	SetColor(3);
	gotoXY(12, 27);
	cout << "Score: " << diem;

}
void khoi_tao_ran(int toadox[], int toadoy[])
{
	int x = 50, y = 13;
	for (int i = 0; i < sl; i++)
	{
		toadox[i] = x;
		toadoy[i] = y;
		x--;
	}
}
void ve_ran(int toadox[], int toadoy[])
{
	SetColor(5);
	for (int i = 0; i < sl; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		if (i == 0)
		{
			cout << char(002);
		}
		else cout << "o";
	}
}
void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int& xqua, int& yqua)
{
	//them toa do moi vao dau mang
	them(toadox, x);
	them(toadoy, y);
	//xoa toa do cuoi mang
	if (kt_ran_an_qua(toadox[0], toadoy[0], xqua, yqua) == false)
	{
		xoa(toadox, sl - 1);
		xoa(toadoy, sl - 1);
	}
	else
	{
		tao_qua(xqua, yqua, toadox, toadoy);
		sl--;
		if ((sl - 4) % 6 == 0 && (sl - 4) > 0)
		{
			PlaySound(TEXT("C:\\NHAC GAME\\antraitym.wav"), NULL, SND_ASYNC);
			diem = diem + 3;
		}
		else
		{
			PlaySound(TEXT("C:\\NHAC GAME\\andolar.wav"), NULL, SND_ASYNC);
			diem++;
		}

	}
	//ve ran
	ve_ran(toadox, toadoy);
}

void them(int a[], int x)
{
	for (int i = sl; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
	sl++;
}
void xoa(int a[], int vt)
{
	for (int i = vt; i < sl; i++)
	{
		a[i] = a[i + 1];
	}
	sl--;
}
void xoa_du_lieu_cu(int toadox[], int toadoy[])
{
	for (int i = 0; i < sl; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		cout << " ";
	}
}
bool kt_ran_cham_tuong(int x0, int y0)
{
	if (y0 == 1 && (x0 >= 10 && x0 <= 100))
	{
		return true;
	}
	else if (y0 == 26 && (x0 >= 10 && x0 <= 100))
	{
		return true;
	}
	else if (x0 == 100 && (y0 >= 1 && y0 <= 26))
	{
		return true;
	}
	else if (x0 == 10 && (y0 >= 1 && y0 <= 26))
	{
		return true;
	}
	return false;
}
bool kt_ran_cham_duoi(int toadox[], int toadoy[])
{
	for (int i = 1; i < sl; i++)
	{
		if ((toadox[0] == toadox[i]) && (toadoy[0] == toadoy[i]))
		{
			return true;
		}
	}
	return false;
}
bool kt_gameover(int toadox[], int toadoy[])
{
	if (kt_ran_cham_tuong(toadox[0], toadoy[0]) == true || kt_ran_cham_duoi(toadox, toadoy) == true)
	{
		return true;
	}
	return false;
}
void tao_qua(int& xqua, int& yqua, int toadox[], int toadoy[])
{
	do
	{
		xqua = rand() % (99 - 11 + 1) + 11;
		yqua = rand() % (25 - 2 + 1) + 2;
	} while (kt_ran_de_qua(toadox, toadoy, xqua, yqua) == true);
	int i = rand() % (15 - 1 + 1) + 1;
	SetColor(i);
	gotoXY(xqua, yqua);
	if ((sl - 4) % 6 == 0 && (sl - 4) > 0)
	{
		cout << char(003);
	}
	else
	{
		cout << "$";
	}
	SetColor(7);
}
bool kt_ran_de_qua(int toadox[], int toadoy[], int xqua, int yqua)
{
	for (int i = 0; i < sl; i++)
	{
		if ((xqua == toadox[i]) && (yqua == toadoy[i]))
		{
			return true;
		}
	}
	return false;
}
bool kt_ran_an_qua(int x0, int y0, int xqua, int yqua)
{
	if (x0 == xqua && y0 == yqua)
	{
		return true;
	}
	return false;
}
void luu_diem_cao()
{
	ofstream myfile;
	myfile.open("diemcao.txt");
	myfile << diem;
	myfile.close();
}
void xuat_diem_cao()
{
	ifstream myfile;
	myfile.open("diemcao.txt");
	myfile >> diemcao;
	myfile.close();
}
int reset_diem()
{
	diem = 0;
	return diem;
}
int reset_sl()
{
	sl = 4;
	return sl;
}
void reset()
{
	reset_diem();
	reset_sl();
}

void end_game(int toadox[], int toadoy[])
{
	SetColor(3);
	system("cls");
	if (kt_gameover(toadox, toadoy) == true)
	{
		PlaySound(TEXT("C:\\NHAC GAME\\gameover.wav"), NULL, SND_ASYNC);
		gotoXY(40, 16);
		xuat_diem_cao();
		cout << "GAME OVER!";
		if (diemcao < diem)
		{
			PlaySound(TEXT("C:\\NHAC GAME\\newhighscore.wav"), NULL, SND_ASYNC);
			gotoXY(40, 17);
			luu_diem_cao();
			cout << "New HighScore: " << diem;
		}
		else
		{
			gotoXY(40, 17);
			cout << "Your Score: " << diem;
		}
		gotoXY(40, 19);
		cout << "Press Enter to play again/ESC to back to Menu";
		while (true)
		{
			if (_kbhit())
			{
				char c = _getch();
				if (c == 13)
				{
					reset();
					system("cls");
					Run_Game();
					break;
				}
				else if (c == 27)
				{
					reset();
					system("cls");
					Menu();
					break;
				}
			}
		}
	}

}

void Menu()
{
	ShowCur(0);
	PlaySound(TEXT("C:\\NHAC GAME\\nhacnengame.wav"), NULL, SND_ASYNC | SND_LOOP);
	SetColor(3);
	for (int i = 0; i < 20; i++)
	{
		gotoXY(40 + i, 13);
		cout << char(196);
	}
	gotoXY(40, 14);
	cout << char(002);
	gotoXY(59, 14);
	cout << char(002);
	for (int i = 0; i < 20; i++)
	{
		gotoXY(40 + i, 15);
		cout << char(196);
	}
	SetColor(11);
	gotoXY(45, 14);
	cout << "SNAKE GAME";

	//===================
	gotoXY(40, 16);
	cout << "1. Play";
	gotoXY(40, 18);
	cout << "2. Instructions";
	gotoXY(40, 20);
	cout << "3. Choose lever";
	gotoXY(40, 22);
	cout << "4. HighCore";
	gotoXY(40, 24);
	cout << "5. Exit";
	int check = 0;
	while (true)
	{
		char c;
		if (_kbhit())
		{
			c = _getch();
			if (c == '1')
			{
				for (int i = 0; i < 8; i = i + 2)
				{
					gotoXY(37, 16 + i);
					cout << "  ";
				}
				check = 1;
				gotoXY(37, 16);
				cout << "->";
				PlaySound(TEXT("C:\\NHAC GAME\\bamphim.wav"), NULL, SND_ASYNC);
			}
			else if (c == '2')
			{
				gotoXY(37, 16);
				cout << "  ";
				gotoXY(37, 20);
				cout << "  ";
				gotoXY(37, 22);
				cout << "  ";
				gotoXY(37, 24);
				cout << "  ";
				check = 2;
				gotoXY(37, 18);
				cout << "->";
				PlaySound(TEXT("C:\\NHAC GAME\\bamphim.wav"), NULL, SND_ASYNC);
			}
			else if (c == '3')
			{
				gotoXY(37, 16);
				cout << "  ";
				gotoXY(37, 18);
				cout << "  ";
				gotoXY(37, 22);
				cout << "  ";
				gotoXY(37, 24);
				cout << "  ";
				check = 3;
				gotoXY(37, 20);
				cout << "->";
				PlaySound(TEXT("C:\\NHAC GAME\\bamphim.wav"), NULL, SND_ASYNC);
			}
			else if (c == '4')
			{
				gotoXY(37, 16);
				cout << "  ";
				gotoXY(37, 18);
				cout << "  ";
				gotoXY(37, 20);
				cout << "  ";
				gotoXY(37, 24);
				cout << "  ";
				check = 4;
				gotoXY(37, 22);
				cout << "->";
				PlaySound(TEXT("C:\\NHAC GAME\\bamphim.wav"), NULL, SND_ASYNC);
			}
			else if (c == '5')
			{
				gotoXY(37, 16);
				cout << "  ";
				gotoXY(37, 18);
				cout << "  ";
				gotoXY(37, 20);
				cout << "  ";
				gotoXY(37, 22);
				cout << "  ";
				check = 5;
				gotoXY(37, 24);
				cout << "->";
				PlaySound(TEXT("C:\\NHAC GAME\\bamphim.wav"), NULL, SND_ASYNC);
			}
			else if (c == 13)
			{
				if (check == 1)
				{
					system("cls");
					Run_Game();
					break;
				}
				else if (check == 2)
				{
					system("cls");
					PlaySound(TEXT("C:\\NHAC GAME\\huongdan.wav"), NULL, SND_ASYNC);
					gotoXY(40, 16);
					cout << "#su dung phim mui ten de dieu khien ran,";
					gotoXY(40, 17);
					cout << "game se ket thuc khi ran cham tuong hoac tu can duoi.";
					gotoXY(40, 19);
					cout << "#dieu khien di chuyen ran an dolar de tich diem,";
					gotoXY(40, 20);
					cout << "cu moi 5 dolar an duoc se xuat hien Trai Tym,";
					gotoXY(40, 21);
					cout << "an duoc Trai Tym se duoc rat nhieu diem.";
					gotoXY(40, 23);
					cout << "CHUC BAN CHOI GAME VUI VE !";
					gotoXY(40, 25);
					cout << "press ESC to back to Menu";
					while (true)
					{
						if (_kbhit())
						{
							char c = _getch();
							if (c == 27)
							{
								system("cls");
								Menu();
							}
						}
					}
				}
				else if (check == 3)
				{

					system("cls");
					PlaySound(TEXT("C:\\NHAC GAME\\chonlever.wav"), NULL, SND_ASYNC);
					gotoXY(40, 16);
					cout << "1. Lever1";
					gotoXY(40, 17);
					cout << "2. Lever2";
					gotoXY(40, 18);
					cout << "3. Lever3";
					gotoXY(40, 19);
					cout << "Your choose ";
					cin >> choose_lever;
					if (choose_lever == 1 || choose_lever == 2 || choose_lever == 3)
					{
						system("cls");
						PlaySound(TEXT("C:\\NHAC GAME\\chonleverthanhcong.wav"), NULL, SND_ASYNC);
						gotoXY(40, 16);
						cout << "Choose lever success!";
						gotoXY(40, 17);
						cout << "press enter to play";
						while (true)
						{
							if (_kbhit())
							{
								char c = _getch();
								if (c == 13)
								{
									system("cls");
									Run_Game();
									break;
								}
							}
						}
						break;
					}
					else
					{
						system("cls");
						PlaySound(TEXT("C:\\NHAC GAME\\khonghople.wav"), NULL, SND_ASYNC);
						gotoXY(40, 16);
						cout << "Invalid!" << endl;
						gotoXY(40, 17);
						cout << "press ESC to back to Menu";
						while (true)
						{
							if (_kbhit())
							{
								char c = _getch();
								if (c == 27)
								{
									system("cls");
									Menu();
								}
							}
						}
					}

				}
				else if (check == 4)
				{
					system("cls");
					PlaySound(TEXT("C:\\NHAC GAME\\showdiemcao.wav"), NULL, SND_ASYNC);
					xuat_diem_cao();
					gotoXY(40, 16);
					cout << "Your HighScore: " << diemcao;
					gotoXY(40, 17);
					cout << "press ESC to back Menu";
					while (true)
					{
						if (_kbhit())
						{
							char c = _getch();
							if (c == 27)
							{
								system("cls");
								Menu();
							}
						}
					}
				}
				else if (check == 5)
				{
					break;
				}
			}
		}
	}
}
void Run_Game()
{
	int toadox[MAX], toadoy[MAX];
	ve_tuong();
	int xqua = 0, yqua = 0;
	khoi_tao_ran(toadox, toadoy);
	ve_ran(toadox, toadoy);
	srand(time(NULL));
	//================kiem tra va toa qua==============
	tao_qua(xqua, yqua, toadox, toadoy);
	int x = 50, y = 13; //toa do ban dau cua ran 
	int check = 2;
	while (kt_gameover(toadox, toadoy) == false)
	{
		//0 di xuong
		//1 di len
		//2 sang phai
		//3 sang trai
		//==========dieu khien===========
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 72 && check != 1)
				{
					//dilen
					check = 0;
				}
				else if (c == 80 && check != 0)
				{
					//dixuong
					check = 1;
				}
				else if (c == 77 && check != 3)
				{
					//sangphai
					check = 2;
				}
				else if (c == 75 && check != 2)
				{
					//sangtrai
					check = 3;
				}
			}
		}
		//=========thuc hien di chuyen==============
		if (check == 0)
		{
			y--;
		}
		else if (check == 1)
		{
			y++;
		}
		else if (check == 2)
		{
			x++;
		}
		else if (check == 3)
		{
			x--;
		}
		xoa_du_lieu_cu(toadox, toadoy);
		xu_ly_ran(toadox, toadoy, x, y, xqua, yqua);
		show_diem();
		kt_gameover(toadox, toadoy);
		if (kt_gameover(toadox, toadoy) == true)
		{
			end_game(toadox, toadoy);
		}
		if (choose_lever == 1)
		{
			Sleep(200);
		}
		else if (choose_lever == 2)
		{
			Sleep(100);
		}
		else if (choose_lever == 3)
		{
			Sleep(50);
		}
		else
		{
			Sleep(200);
		}
	}
	_getch();
}
