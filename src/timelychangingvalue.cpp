#include "TimelyChangingValue.h"

using namespace std::chrono;

TimelyChangingValue::TimelyChangingValue(double theTargetValue, std::chrono::microseconds theChangeDuration)
    : targetValue{theTargetValue}, changeDuration{theChangeDuration}
{
    currentValue = targetValue;
}

TimelyChangingValue& TimelyChangingValue::operator=(double theNewTargetValue)
{
    targetValue = theNewTargetValue;
    startValue = currentValue;
    startTime = steady_clock::now();
    return *this;
}

TimelyChangingValue::operator double()
{
    if (currentValue != targetValue)
    {
	steady_clock::time_point now { steady_clock::now() };
	if (now >= startTime + changeDuration)
	{
	    currentValue = targetValue;
	} else {
	    microseconds timeElapsed = duration_cast<microseconds>( now - startTime );
	    currentValue = startValue + ( 
		((double)timeElapsed.count() / changeDuration.count()) 
		* (targetValue - startValue) );
	}
    }
    return currentValue;
}
