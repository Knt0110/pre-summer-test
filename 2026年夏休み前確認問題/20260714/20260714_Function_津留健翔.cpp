#include <iostream>
#include <ctime>
#include <cstdlib>
#include "20260714_Header_津留健翔.h"
using namespace std;

void Game()
{
	//変数宣言&配列
	int box[SysNum::BOX];
	int playerScore = 0, cpuScore = 0;
	int playerInput, cpuInput;


	//乱数初期化
	srand((unsigned int)time(NULL));

	//ランダムな数字を10個
	for (int i = 0; i < SysNum::BOX; i++)
	{
		box[i] = rand() % SysNum::RAND_NUM;
		//cout << box[i] << endl; //確認用
	}

	//入力
	playerInput = InputCheck(SysNum::NUM_MIN,SysNum::NUM_MAX);

}

int InputCheck(int min, int max)
{
	//変数宣言
	int num{ 0 };
	//入力
	cout << "1～10の番号を選択してください" << endl;
	while (true)
	{
		cin >> num;
		if (num < min || num > max)
		{
			cout << "入力範囲外です。再度入力してください。" << endl;
		}
		else
		{
			break;
		}
	}
	return num;
}