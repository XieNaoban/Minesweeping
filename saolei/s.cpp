#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int o(int i)//防止超出数组范围
{
	if (i < 0) return 10;
	else return i;
}
void xianshi(char p[][11])//显示棋盘
{
	system("cls");
	cout << "-------------------------------------------------------------------------------\n"
		<< "|                    0   1   2   3   4   5   6   7   8   9                    |\n";
	for (int i = 0;i < 9;i++)
	{
		cout << "|                  " << i;
		for (int j = 0;j < 9;j++) cout << ' ' << p[i][j] << " |";
		cout << ' ' << p[i][9] << ' ' << i << "                  |\n"
			<< "|                   ---+---+---+---+---+---+---+---+---+---                   |\n";
	}
	cout << "|                  9";
	for (int j = 0;j < 9;j++) cout << ' ' << p[9][j] << " |";
	cout << ' ' << p[9][9] << " 9                  |\n"
		<< "|                    0   1   2   3   4   5   6   7   8   9                    |\n"
		<< "|                                                                             |\n"
		<< "-------------------------------------------------------------------------------\n";
}
int panduan(char p[][11], char cx, char cy, int &x, int &y, char &lei)
{
	switch (cx)
	{
	case '0': x = 0;break;
	case '1': x = 1;break;
	case '2': x = 2;break;
	case '3': x = 3;break;
	case '4': x = 4;break;
	case '5': x = 5;break;
	case '6': x = 6;break;
	case '7': x = 7;break;
	case '8': x = 8;break;
	case '9': x = 9;break;
	default: cout << "错误：数据不合法。\n";return 0;
	}
	switch (cy)
	{
	case '0': y = 0;break;
	case '1': y = 1;break;
	case '2': y = 2;break;
	case '3': y = 3;break;
	case '4': y = 4;break;
	case '5': y = 5;break;
	case '6': y = 6;break;
	case '7': y = 7;break;
	case '8': y = 8;break;
	case '9': y = 9;break;
	default: cout << "错误：数据不合法。\n";return 0;
	}
	if (lei == 'o' || lei == 'O') return 1;
	else if (p[y][x] != ' '&&p[y][x] != 'P') { cout << "错误：数据不合法。\n";return 0; }
	return 1;
}
void kaiju(int a[11][11])
{
	int tx, ty;
	for (int i = 1;i <= 10;i++)
	{
		tx = rand() % 10, ty = rand() % 10;
		while (a[ty][tx] != 0) { tx = rand() % 10; ty = rand() % 10; }
		a[ty][tx] = 9;
	}
	for (int j = 0;j < 10;j++)
		for (int i = 0;i < 10;i++)
		{
			if (a[j][i] == 9) continue;
			if (a[o(j - 1)][o(i - 1)] == 9) a[j][i]++;
			if (a[o(j - 1)][o(i)] == 9) a[j][i]++;
			if (a[o(j - 1)][o(i + 1)] == 9) a[j][i]++;
			if (a[o(j)][o(i - 1)] == 9) a[j][i]++;
			if (a[o(j)][o(i + 1)] == 9) a[j][i]++;
			if (a[o(j + 1)][o(i - 1)] == 9) a[j][i]++;
			if (a[o(j + 1)][o(i)] == 9) a[j][i]++;
			if (a[o(j + 1)][o(i + 1)] == 9) a[j][i]++;
		}
}
void kong(int pp[][11], char p[][11], int x, int y)
{
	if (p[y][x] == ' ' && x != 10 && y != 10 && p[y][x] != 'P')
	{
		if (pp[y][x] == 0)
		{
			p[y][x] = '0';
			kong(pp, p, o(x - 1), o(y - 1));
			kong(pp, p, x, o(y - 1));
			kong(pp, p, x + 1, o(y - 1));
			kong(pp, p, o(x - 1), y);
			kong(pp, p, x + 1, y);
			kong(pp, p, o(x - 1), y + 1);
			kong(pp, p, x, y + 1);
			kong(pp, p, o(x + 1), o(y + 1));
		}
		else p[y][x] = (char)(48 + pp[y][x]);
	}
}
void zhongjian(int pp[][11], char p[][11], int x, int y)
{
	if (p[y][x] != ' ' &&
		(pp[o(y - 1)][o(x - 1)] != 9 || (p[o(y - 1)][o(x - 1)] == 'P'&&pp[o(y - 1)][o(x - 1)] == 9)) &&
		(pp[o(y - 1)][x] != 9 || (p[o(y - 1)][x] == 'P'&&pp[o(y - 1)][x] == 9)) &&
		(pp[o(y - 1)][x + 1] != 9 || (p[o(y - 1)][x + 1] == 'P'&&pp[o(y - 1)][x + 1] == 9)) &&
		(pp[y][o(x - 1)] != 9 || (p[y][o(x - 1)] == 'P'&&pp[y][o(x - 1)] == 9)) &&
		(pp[y][x + 1] != 9 || (p[y][x + 1] == 'P'&&pp[y][x + 1] == 9)) &&
		(pp[y + 1][o(x - 1)] != 9 || (p[y + 1][o(x - 1)] == 'P'&&pp[y + 1][o(x - 1)] == 9)) &&
		(pp[y + 1][x] != 9 || (p[y + 1][x] == 'P'&&pp[y + 1][x] == 9)) &&
		(pp[y + 1][x + 1] != 9 || (p[y + 1][x + 1] == 'P'&&pp[y + 1][x + 1] != 9)))
	{
		if (p[o(y - 1)][o(x - 1)] == ' ') kong(pp, p, o(x - 1), o(y - 1));
		if (p[o(y - 1)][x] == ' ') kong(pp, p, x, o(y - 1));
		if (p[o(y - 1)][x + 1] == ' ') kong(pp, p, x+1, o(y - 1));
		if (p[y][o(x - 1)] == ' ') kong(pp, p, o(x-1), y);
		if (p[y][x + 1] == ' ') kong(pp, p,x+1, y);
		if (p[y + 1][o(x - 1)] == ' ') kong(pp, p, o(x - 1), y+1);
		if (p[y + 1][x] == ' ') kong(pp, p, x, y + 1);
		if (p[y + 1][x + 1] == ' ') kong(pp, p, x + 1, y + 1);
	}
}

int main()
{
	system("mode con cols=80 lines=33");
	system("cls");
	cout << "-------------------------------------------------------------------------------\n"
		<< "|                    0   1   2   3   4   5   6   7   8   9                    |\n"
		<< "|                  0   |   |   |   |   |   |   |   |   |   0                  |\n"
		<< "|                   ---+---+---+---+---+---+---+---+---+---                   |\n"
		<< "|                  1   |   |   |   |   |   |   |   |   |   1                  |\n"
		<< "|                   ---+---+---+---+---+---+---+---+---+---                   |\n"
		<< "|                  2   |   |   |   |   |   |   |   |   |   2                  |\n"
		<< "|                   ---+---+---+---+---+---+---+---+---+---                   |\n"
		<< "|                  3   |   |   |   |   |   |   |   |   |   3                  |\n"
		<< "|                   ---+---+---+---+---+---+---+---+---+---                   |\n"
		<< "|                  4   |   |   |   |   |   |   |   |   |   4                  |\n"
		<< "|                   ---+---+---+---+---+---+---+---+---+---                   |\n"
		<< "|                  5   |   |   |   |   |   |   |   |   |   5                  |\n"
		<< "|                   ---+---+---+---+---+---+---+---+---+---                   |\n"
		<< "|                  6   |   |   |   |   |   |   |   |   |   6                  |\n"
		<< "|                   ---+---+---+---+---+---+---+---+---+---                   |\n"
		<< "|                  7   |   |   |   |   |   |   |   |   |   7                  |\n"
		<< "|                   ---+---+---+---+---+---+---+---+---+---                   |\n"
		<< "|                  8   |   |   |   |   |   |   |   |   |   8                  |\n"
		<< "|                   ---+---+---+---+---+---+---+---+---+---                   |\n"
		<< "|                  9   |   |   |   |   |   |   |   |   |   9                  |\n"
		<< "|                    0   1   2   3   4   5   6   7   8   9                    |\n"
		<< "|                                                                             |\n"
		<< "-------------------------------------------------------------------------------\n"
		<< "输入P x y 模拟插下小旗\n输入I x y 模拟点下去\n输入O x y 模拟探测。\n";
	char cx = '0', cy = '0';
	int x = 0, y = 0;//玩家下的子
	char lei = 0;
	int jieju = 0;//1:玩家赢 2:玩家输
	char p[11][11];//显示的
	int pp[11][11] = { 0 };//表示的
	srand((unsigned)time(0));
	for (int i = 0;i < 11;i++)
		for (int j = 0;j < 11;j++)
			p[i][j] = ' ';
	kaiju(pp);
	while (!jieju)
	{
		while (1)
		{
			cout << "Player> ";
			cin >> lei;
			if (lei == 'R' || lei == 'r') {
				cout << "重新开局？再次输入R 确定，输入其他继续当前游戏。";
				cin >> lei;
				if (lei == 'R' || lei == 'r')
					main();
			}
			cin >> cx >> cy;
			if (lei == 'x'&&cx == 'j'&&cy == 'f')
			{
				int tpp[11][11];
				char tp[11][11];
				for (int i = 0;i < 11;i++)
					for (int j = 0;j < 11;j++)
						tpp[j][i] = pp[j][i];
				for (int i = 0;i < 11;i++)
					for (int j = 0;j < 11;j++)
						tp[i][j] = ' ';
				for (int i = 0;i < 10;i++)
					for (int j = 0;j < 10;j++)
						if (tpp[j][i] == 9) tp[j][i] = '*';
				xianshi(tp);
			}
			if (panduan(p, cx, cy, x, y, lei)) break;
		}
		if (lei != 'P' && lei != 'p')
		{
			if (lei != 'o' && lei != 'O')
			{
				if (pp[y][x] == 9)
				{
					p[y][x] = '*';
					xianshi(p);
					jieju = 2;
				}
				else if (pp[y][x] != 0 && pp[y][x] != 9)
				{
					p[y][x] = (char)(pp[y][x] + 48);
					xianshi(p);
				}
				else
				{
					kong(pp, p, x, y);
					xianshi(p);
				}
			}
			else
			{
				zhongjian(pp, p, x, y);
				xianshi(p);
			}
		}
		else
		{
			if (p[y][x] == ' ') p[y][x] = 'P';
			else p[y][x] = ' ';
			xianshi(p);
		}
		int temp = 0;
		for (int i = 0;i < 10;i++)
			for (int j = 0;j < 10;j++)
				if (p[i][j] == ' ' || p[i][j] == 'P') temp++;
		if (temp == 10) jieju = 1;
	}
	if (jieju == 1) cout << "You win!\n";
	else cout << "You fail!\n";
	cout << "输入R再玩一局；输入其他结束。\n";
	char r;
	cin >> r;
	if (r == 'R' || r == 'r') main();
	return 0;
}