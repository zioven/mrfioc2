/*************************************************************************\
* Copyright (c) 2015 Paul Scherrer Institute (PSI), Villigen, Switzerland
* Copyright (c) 2022 Cosylab d.d., Ljubljana, Slovenia
* mrfioc2 is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution.
\*************************************************************************/
#ifndef DELAYMODULERP_H
#define DELAYMODULERP_H

#include "evr/delay.h"

#include "mrmGpio.h"


class EVRMRM;

class DelayModuleRP : public DelayModuleEvr
{
public:
    DelayModuleRP(const std::string&, EVRMRM*, unsigned int);
	virtual ~DelayModuleRP();

    /**
     * @brief setDelay0 Sets the delay of the output 0 in the module
     * @param val Delay in range of 0ns - 8.686ns. If the value is greater it will be set to maximum range value, if it is smaller it will be set to minimum range value.
     */
    virtual void setDelay0(double val) OVERRIDE FINAL;
    /**
     * @brief getDelay0 Returns the last set delay for the output 0 in the module
     * @return The delay in [ns]
     */
    virtual double getDelay0() const OVERRIDE FINAL;

    /**
     * @brief setDelay1 Sets the delay of the output 1 in the module
     * @param val Delay in range of 0ns - 8.686ns. If the value is greater it will be set to maximum range value, if it is smaller it will be set to minimum range value.
     */
    virtual void setDelay1(double val) OVERRIDE FINAL;
    /**
     * @brief getDelay1R eturns the last set delay for the output 1 in the module
     * @return  The delay in [ns]
     */
    virtual double getDelay1() const OVERRIDE FINAL;

    /**
     * @brief setState Sets the enabled state of the delay module. If disabled, the module will output logic low on both ouputs.
     * @param enabled True for enabled and false for disabled
     */
    virtual void setState(bool enabled) OVERRIDE FINAL;
    /**
     * @brief enabled Checks if the module is enabled or not.
     * @return True if the module is enabled, false othwerwise.
     */
    virtual bool enabled() const OVERRIDE FINAL;

    //void set(bool a, bool b, epicsUInt16 c, epicsUInt16 d){setDelay(a,b,c,d);}

private:
    EVRMRM* evr_;
    const unsigned int N_;
    epicsUInt16 dly0_, dly1_;

    // There is no locking needed, but methods must be present since there are virtual in mrf::Object class
    virtual void lock() const OVERRIDE FINAL {}
    virtual void unlock() const OVERRIDE FINAL {}
};

#endif // DELAYMODULERP_H
