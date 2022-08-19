/*************************************************************************\
* Copyright (c) 2022 Cosylab d.d., Ljubljana, Slovenia
* mrfioc2 is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution.
\*************************************************************************/

#include "delayModuleRP.h"

#include <drvem.h>
#include <evrRegMap.h>

#define MAX_DELAY (8.686)

static inline epicsUInt32 delay2Int(double val) {
    if(val < 0) val = 0;
    if(val > MAX_DELAY) val = MAX_DELAY;
    return val / MAX_DELAY * 1023.0;
}

static inline double int2Delay(epicsUInt32 val) {
    return val * MAX_DELAY / 1023.0;
}

DelayModuleRP::DelayModuleRP(const std::string& n, EVRMRM* o, unsigned int idx)
    : DelayModuleEvr(n)
    ,evr_(o)
    ,N_(idx)
{
}

DelayModuleRP::~DelayModuleRP()
{
}

void DelayModuleRP::setDelay0(double val)
{
	WRITE32(evr_->base, RTMDLY(2 * N_), delay2Int(val));
}

double DelayModuleRP::getDelay0() const
{
	return int2Delay(READ32(evr_->base, RTMDLY(2 * N_)));
}

void DelayModuleRP::setDelay1(double val)
{
	WRITE32(evr_->base, RTMDLY(2 * N_ + 1), delay2Int(val));
}

double DelayModuleRP::getDelay1() const
{
	return int2Delay(READ32(evr_->base, RTMDLY(2 * N_ + 1)));
}

void DelayModuleRP::setState(bool) {

}

bool DelayModuleRP::enabled() const {
    return true;
}
