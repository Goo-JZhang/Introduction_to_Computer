#include <stdio.h>
#include "configure.h"

// 合作
enum Decision g00_naive(int len,
						int my_id,
						const char *my_decisions,
						int opp_id,
						const char *opp_decisions ,
						const char opp_history_decisions[HISTORY_LENGTH][MAX_TURN],
						const char opp_opp_history_decisions[HISTORY_LENGTH][MAX_TURN])
{
	return COOPERATION;
}

