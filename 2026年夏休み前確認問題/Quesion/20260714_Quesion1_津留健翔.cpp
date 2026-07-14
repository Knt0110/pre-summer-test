#include <iostream>
#include <cstdlib>
#include <ctime>
#include "20260714_QuesionHeader_name.h"
using namespace std;


//====================================
// メイン
//====================================
int main()
{
    //変数宣言
    int player;
    int cpu;
    int probability;

    int strike = 0;
    int ball = 0;
    int out = 0;
    int hit = 0;

    //乱数初期化
    srand((unsigned int)time(nullptr));

    //インフォメーション
    cout << "野球盤ゲームスタートです" << endl;
    cout << "プレイヤーはピッチャーとなり、この回を守り切ってください" << endl;

    do
    {
        //入力用の選択肢表示
        cout << endl;
        cout << "投げる球を選んでください" << endl;
        cout << "0:ストレート" << endl;
        cout << "1:カーブ" << endl;
        cout << "2:スライダー" << endl;
        cout << "3:シンカー" << endl;
        //入力
        player = InputCheck(PITCHING_MIN,PITCHING_MAX);

        PitchingType(player);

        //CPUの行動生成
        cpu = rand() % PROBABILITY;

        probability = rand() % PROBABILITY;

        //プレイヤーとCPUの表示が等しくなければ
        if (player != cpu)
        {
            if (probability == 0)
            {
                cout << "ボール！" << endl;
                ball++;
            }
            else
            {
                cout << "ストライク！！" << endl;
                strike++;
            }
        }
        else
        {
            strike = 0;
            ball = 0;

            if (probability == 1)
            {
                cout << "OUT!!" << endl;
                out++;
            }
            else
            {
                cout << "HIT!!" << endl;
                hit++;
            }
        }

        //ストライクorボールが一定数を超えたら
        if (strike >= STRIKE_COUNT || ball >= BALL_COUNT)
        {
            if (strike >= STRIKE_COUNT) //ストライクが一定数を超えたら
            {
                cout << "三振アウト！" << endl;
                out++;
            }
            else  //ボールが一定数を超えたら
            {
                cout << "フォアボール！" << endl;
                hit++;
            }

            //リセット  
            strike = 0;
            ball = 0;
        }

        //現在のスコア
        cout << endl;
        cout << "B : " << ball << endl;
        cout << "S : " << strike << endl;
        cout << "O : " << out << endl;
        cout << "Runner : " << hit << endl;

    } while (out < OUT_COUNT && hit < HIT_COUNT);

    Result(out);

    return 0;
}