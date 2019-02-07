#ifndef TIMELYCHANGINGVALUE_H
#define TIMELYCHANGINGVALUE_H

#include <chrono>

class TimelyChangingValue
{
    double currentValue;
    double startValue;
    double targetValue;
    std::chrono::steady_clock::time_point startTime;
    std::chrono::microseconds changeDuration;
public:
    TimelyChangingValue(double initialValue, 
        std::chrono::microseconds changeDuration = std::chrono::milliseconds(500));
    operator double();
    TimelyChangingValue& operator= (double newTargetValue);
};

#endif // TIMELYCHANGINGVALUE_H
