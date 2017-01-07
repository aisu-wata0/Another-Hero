#include "stdAfx.h"
#include "stats.h"

void Stats::levelUp() 
{
	base_hp_ = (long)round(base_hp_*1.5);
	base_mp_ = (long)round(base_mp_*1.5);
	base_str_ = (long)round(base_str_*1.5);
	base_def_ = (long)round(base_def_*1.5);
	base_int_ = (long)round(base_int_*1.5);
	base_res_ = (long)round(base_res_*1.5);
	base_agi_ = (long)round(base_agi_*1.5);

	// applyBuffs();
}

//void Stats::applyBuffs() {
//
//}
