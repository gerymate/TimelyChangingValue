#ifndef TIMELYCHANGINGVALUE_H
#define TIMELYCHANGINGVALUE_H

#include <chrono>

template <class T>
class TimelyChangingValue
{
    T currentValue;
    T startValue;
    T targetValue;
    std::chrono::steady_clock::time_point startTime;
    std::chrono::microseconds changeDuration;
public:
    TimelyChangingValue(T initialValue, 
        std::chrono::microseconds changeDuration = std::chrono::milliseconds(500));
    operator T();
    TimelyChangingValue<T>& operator= (T newTargetValue);
};


template <class T>
TimelyChangingValue<T>::TimelyChangingValue(T initialValue, 
    std::chrono::microseconds changeDuration)
    : targetValue{initialValue}, changeDuration{changeDuration}
{
    currentValue = targetValue;
}

template <class T>
TimelyChangingValue<T>& TimelyChangingValue<T>::operator=(T newTargetValue)
{
    targetValue = newTargetValue;
    startValue = currentValue;
    startTime = std::chrono::steady_clock::now();
    return *this;
}

template <class T>
TimelyChangingValue<T>::operator T()
{
    if (currentValue != targetValue)
    {
	std::chrono::steady_clock::time_point now 
        { std::chrono::steady_clock::now() };
	if (now >= startTime + changeDuration)
	{
	    currentValue = targetValue;
	} else {
	    std::chrono::microseconds timeElapsed = 
            std::chrono::duration_cast<std::chrono::microseconds>(
                now - startTime
                );
	    currentValue = startValue + ( 
		    ((double)timeElapsed.count() / changeDuration.count())
                * (targetValue - startValue)
            );
	}
    }
    return currentValue;
}


#endif // TIMELYCHANGINGVALUE_H
