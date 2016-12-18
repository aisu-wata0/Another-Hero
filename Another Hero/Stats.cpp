#include "StdAfx.h"

void Stats::levelUp() {
	hp_ = (long)round(hp_*1.48);
	mp_ = (long)round(mp_*1.48);
	str_ = (long)round(str_*1.48);
	def_ = (long)round(def_*1.48);
	int_ = (long)round(int_*1.48);
	res_ = (long)round(res_*1.48);
	agi_ = (long)round(agi_*1.48);
}
