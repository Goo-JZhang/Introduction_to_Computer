#pragma once

#ifndef GAME_CONFIGURE_H
#define GAME_CONFIGURE_H

//
#define HISTORY_LENGTH 20

// 每次见面博弈的次数
#define MAX_TURN 25


// 决策枚举
enum Decision {
	COOPERATION = 'c',
	BETRAYAL = 'b',
};

enum Decision g00_naive(int len, int my_id, const char my_decisions[], int opp_id, const char opp_decisions[], const char opp_history_decisions[HISTORY_LENGTH][MAX_TURN], const char opp_opp_history_decisions[HISTORY_LENGTH][MAX_TURN]);
enum Decision g00_tricker(int len, int my_id, const char my_decisions[], int opp_id, const char opp_decisions[], const char opp_history_decisions[HISTORY_LENGTH][MAX_TURN], const char opp_opp_history_decisions[HISTORY_LENGTH][MAX_TURN]);
enum Decision g00_philosopher(int len, int my_id, const char my_decisions[], int opp_id, const char opp_decisions[], const char opp_history_decisions[HISTORY_LENGTH][MAX_TURN], const char opp_opp_history_decisions[HISTORY_LENGTH][MAX_TURN]);
enum Decision g00_stubborn(int len, int my_id, const char my_decisions[], int opp_id, const char opp_decisions[], const char opp_history_decisions[HISTORY_LENGTH][MAX_TURN], const char opp_opp_history_decisions[HISTORY_LENGTH][MAX_TURN]);
enum Decision g00_imitator(int len, int my_id, const char my_decisions[], int opp_id, const char opp_decisions[], const char opp_history_decisions[HISTORY_LENGTH][MAX_TURN], const char opp_opp_history_decisions[HISTORY_LENGTH][MAX_TURN]);
enum Decision g35_uncertainImitator(int len,
	int my_id,
	const char* my_decisions,
	int opp_id,
	const char* opp_decisions,
	const char opp_history_decisions[HISTORY_LENGTH][MAX_TURN],
	const char opp_opp_history_decisions[HISTORY_LENGTH][MAX_TURN]);
// |             | COOPERATION | BETRAYAL |
// |-------------|-------------|----------|
// | COOPERATION | 3,3         | -1,5     |
// | BETRAYAL    | 5,-1        | -3,-3    |
#define T 5	// Temptation	背叛诱惑
#define S -1	// Suckers	受骗支付
#define R 3	// Reward	合作报酬
#define P -3	// Punishment	双方背叛惩罚

#endif //GAME_CONFIGURE_H
