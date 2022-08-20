#include <stdio.h>
#include <limits.h>
#include "configure.h"

enum Decision g35_uncertainImitator(int len,
	int my_id,
	const char* my_decisions,
	int opp_id,
	const char* opp_decisions,
	const char opp_history_decisions[HISTORY_LENGTH][MAX_TURN],
	const char opp_opp_history_decisions[HISTORY_LENGTH][MAX_TURN])
{
	int sum = 0;
	int i = 0, j = 0;
	int turn = 20;//有效（信息未损失）的轮次数
	int Bopp[20], Boop[20];//对手每轮的BETRAYAL数和对手的对手每轮的BETRAYAL数（-1代表信息丢失）
	int Baveopp;//对手每轮BETRAYAL数的平均值
	for (i = 0; i <= 19; i++)
	{
		int j = 0;
		Bopp[i] = 0;
		Boop[i] = 0;
		if (opp_history_decisions[i][0] == 'm')
		{
			Bopp[i] = -1;
			Boop[i] = -1;
			turn--;
		}
		else
		{
			for (j = 2; j <= 24; j++)
			{
				if (opp_history_decisions[i][j] == 'b')
				{
					Bopp[i]++;
				}
				if (opp_opp_history_decisions[i][j] == 'b')
				{
					Boop[i]++;
				}
			}
		}
	}
	for (i = 0; i <= 19; i++)
	{
		sum = sum + Bopp[i];
	}
	Baveopp = (turn == 0) ? 0 : (sum / turn);
	int count = 0;//统计社会上（对手的对手20人）倾向于BETRAYAL的人的个数
	int allcount = 20;//统计有效人数
	for (i = 0; i <= 19; i++)
	{
		if (Boop[i] >= 11)
		{
			count++;
		}
		else if (Boop[i] == -1)
		{
			allcount--;
		}
		else NULL;
	}
	int threshold = 0;//门槛值，若社会上倾向于BETRAYAL的人多，则我更倾向于利己复读机，提高门槛值，反之亦然。
	if (count >= allcount / 2)
	{
		threshold = 18;
	}
	else
	{
		threshold = 12;
	}
	if (Baveopp >= threshold)//对手BETRAYAL倾向高于门槛值时，做损人复读机
	{
		bool find = false;
		int min_score = INT_MAX;
		int min_decision_idx = 0;
		for (int i = 0; i < HISTORY_LENGTH; i++)
		{
			int score = 0;
			for (int j = 0; j < MAX_TURN; j++)
			{
				if (opp_history_decisions[i][j] == COOPERATION && opp_opp_history_decisions[i][j] == COOPERATION)
				{
					score += 3;
				}
				else if (opp_history_decisions[i][j] == COOPERATION && opp_opp_history_decisions[i][j] == BETRAYAL)
				{
					score -= 1;
				}
				else if (opp_history_decisions[i][j] == BETRAYAL && opp_opp_history_decisions[i][j] == COOPERATION)
				{
					score += 5;
				}
				else
				{
					score -= 3;
				}
			}
			if (score < min_score)
			{
				min_score = score;
				min_decision_idx = i;
				find = true;
			}
		}
		if (find)
		{
			if (opp_opp_history_decisions[min_decision_idx][len] == 'c')
				return COOPERATION;
			else
				return BETRAYAL;
		}
		else
		{
			int nc_four = 0, nB = 0; // nc_four前四次对方背叛次数，nB对方在己方上一次合作情况下背叛次数 （对方占便宜次数） 
			if (len == 0)
			{
				return COOPERATION;
			}//第一次合作 
			else if (len < 3)
			{
				if (opp_decisions[len - 1] == COOPERATION) return COOPERATION; //2，3次复读 
				else return BETRAYAL;
			}
			else if (len == 3)//第四次允许在某种情况下尽量合作 
			{
				if (opp_decisions[1] == COOPERATION && opp_decisions[0] == BETRAYAL && opp_decisions[2] == BETRAYAL)return COOPERATION;
				else
				{
					if (opp_decisions[len - 1] == COOPERATION) return COOPERATION;
					else return BETRAYAL;
				}
			}
			else
			{
				for (int i = 0; i < 4; i++)
				{
					if (opp_decisions[len - 1 - i] == COOPERATION)nc_four++;
				}
				for (int i = 0; i < len - 1; i++)
				{
					if (opp_decisions[len - 1 - i] == BETRAYAL && my_decisions[len - 2 - i] == COOPERATION)nB++;
				}

				if (len < 24 || (len == 24 && nc_four != 4))
				{
					if (nB >= 2)return BETRAYAL;//  占便宜两次以上拒绝合作（也有可能是哲学家类型的） 
					else
					{
						if (opp_decisions[len - 1] == COOPERATION) return COOPERATION;
						else return BETRAYAL;
					}
				}
				else { return BETRAYAL; }// 最后一次可以敲诈一下
			}
		}
	}
	else//反之则做利己复读机
	{
		bool find = false;
		int max_score = -INT_MAX;
		int max_decision_idx = 0;
		for (int i = 0; i < HISTORY_LENGTH; i++)
		{
			int score = 0;
			for (int j = 0; j < MAX_TURN; j++)
			{
				if (opp_history_decisions[i][j] == COOPERATION && opp_opp_history_decisions[i][j] == COOPERATION)
				{
					score += 3;
				}
				else if (opp_history_decisions[i][j] == COOPERATION && opp_opp_history_decisions[i][j] == BETRAYAL)
				{
					score += 5;
				}
				else if (opp_history_decisions[i][j] == BETRAYAL && opp_opp_history_decisions[i][j] == COOPERATION)
				{
					score -= 1;
				}
				else
				{
					score -= 3;
				}
			}
			if (score > max_score)
			{
				max_score = score;
				max_decision_idx = i;
				find = true;
			}
		}
		if (find)
		{
			if (opp_opp_history_decisions[max_decision_idx][len] == 'c')
				return COOPERATION;
			else
				return BETRAYAL;
		}
		else
		{
			int nc_four = 0, nB = 0; // nc_four前四次对方背叛次数，nB对方在己方上一次合作情况下背叛次数 （对方占便宜次数） 
			if (len == 0)
			{
				return COOPERATION;
			}//第一次合作 
			else if (len < 3)
			{
				if (opp_decisions[len - 1] == COOPERATION) return COOPERATION; //2，3次复读 
				else return BETRAYAL;
			}
			else if (len == 3)//第四次允许在某种情况下尽量合作 
			{
				if (opp_decisions[1] == COOPERATION && opp_decisions[0] == BETRAYAL && opp_decisions[2] == BETRAYAL)return COOPERATION;
				else
				{
					if (opp_decisions[len - 1] == COOPERATION) return COOPERATION;
					else return BETRAYAL;
				}
			}
			else
			{
				for (int i = 0; i < 4; i++)
				{
					if (opp_decisions[len - 1 - i] == COOPERATION)nc_four++;
				}
				for (int i = 0; i < len - 1; i++)
				{
					if (opp_decisions[len - 1 - i] == BETRAYAL && my_decisions[len - 2 - i] == COOPERATION)nB++;
				}

				if (len < 24 || (len == 24 && nc_four != 4))
				{
					if (nB >= 2)return BETRAYAL;//  占便宜两次以上拒绝合作（也有可能是哲学家类型的） 
					else
					{
						if (opp_decisions[len - 1] == COOPERATION) return COOPERATION;
						else return BETRAYAL;
					}
				}
				else { return BETRAYAL; }// 最后一次可以敲诈一下 
			}
		}
	}
}