#include <stdio.h>
#include "configure.h"

// 与谁都不合作
enum Decision g00_tricker(	int len,
							int my_id,
							const char *my_decisions,
							int opp_id,
							const char *opp_decisions ,
							const char opp_history_decisions[HISTORY_LENGTH][MAX_TURN],
							const char opp_opp_history_decisions[HISTORY_LENGTH][MAX_TURN])
{
	return BETRAYAL;
}

