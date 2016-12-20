#pragma once

class Stats
{
	//std::list<Buff> buffs;
	// void applyBuffs();

public:

	// level 1 stats
	long start_hp_;
	long start_mp_;
	long start_str_;
	long start_def_;
	long start_int_;
	long start_res_;
	long start_agi_;

	// current level stats
	long base_hp_;
	long base_mp_;
	long base_str_;
	long base_def_;
	long base_int_;
	long base_res_;
	long base_agi_;


	// current battle stats
	long hp_;
	long mp_;
	long str_;
	long def_;
	long int_;
	long res_;
	long agi_;

	void levelUp();
};
