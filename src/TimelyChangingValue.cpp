#include "TimelyChangingValue.h"

using namespace std::chrono;

TimelyChangingValue::TimelyChangingValue(double initialValue, 
    std::chrono::microseconds changeDuration)
    : targetValue{initialValue}, changeDuration{changeDuration}
{
    currentValue = targetValue;
}

TimelyChangingValue& TimelyChangingValue::operator=(double newTargetValue)
{
    targetValue = newTargetValue;
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
	    microseconds timeElapsed = duration_cast<microseconds>(now - startTime);
	    currentValue = startValue + ( 
		    ((double)timeElapsed.count() / changeDuration.count()) * 
            (targetValue - startValue)
            );
	}
    }
    return currentValue;
}
