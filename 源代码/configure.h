#pragma once

#ifndef GAME_CONFIGURE_H
#define GAME_CONFIGURE_H

//
#define HISTORY_LENGTH 20

// ÿ�μ��沩�ĵĴ���
#define MAX_TURN 25


// ����ö��
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
#define T 5	// Temptation	�����ջ�
#define S -1	// Suckers	��ƭ֧��
#define R 3	// Reward	��������
#define P -3	// Punishment	˫�����ѳͷ�

#endif //GAME_CONFIGURE_H
