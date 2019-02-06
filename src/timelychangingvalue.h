#ifndef TIMELYCHANGINGVALUE_H
#define TIMELYCHANGINGVALUE_H

#include <chrono>

class TimelyChangingValue
{
    double currentValue;
    double targetValue;
    std::chrono::microseconds changeDuration;
    double startValue;
    std::chrono::steady_clock::time_point startTime;
public:
    TimelyChangingValue(double theTargetValue, 
        std::chrono::microseconds theChangeDuration = std::chrono::milliseconds(500));
    operator double();
    TimelyChangingValue& operator= (double theNewTargetValue);
};

#endif // TIMELYCHANGINGVALUE_H
