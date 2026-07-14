#pragma once

//定数
const int PITCHING_MIN = 0;
const int PITCHING_MAX = 3;
const int PROBABILITY = 4;

const int STRIKE_COUNT = 3;
const int BALL_COUNT = 4;
const int OUT_COUNT = 3;
const int HIT_COUNT = 4;

enum PitchType
{
	Straight,
	Curve,
	Slider,
	Sinker
};

//グローバル関数

/// <summary>
/// 行動を表示する関数
/// </summary>
/// <param name="pitching"></param>
void PitchingType(int pitching);

/// <summary>
/// 勝敗表示関数
/// </summary>
/// <param name="out"></param>
void Result(int out);

/// <summary>
/// 入力チェック関数
/// </summary>
/// <param name="min"></param>
/// <param name="max"></param>
/// <returns></returns>
int InputCheck(int min, int max);

