#include "StdAfx.h"
#include "stats.h"

void Stats::levelUp() 
{
	hpl = (long)round(hpl*1.48);
	mpl = (long)round(mpl*1.48);
	strl = (long)round(strl*1.48);
	defl = (long)round(defl*1.48);
	intl = (long)round(intl*1.48);
	resl = (long)round(resl*1.48);
	agil = (long)round(agil*1.48);
}
