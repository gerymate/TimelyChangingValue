# TimelyChangingValue

## A simple value class for making animations and such

For any given numeric type, tell it in the constructor how long should it take
to change, than assign to it another value. Reading the value during the
change period will give a linear interpolated result, and the assignment is
only finished after the change period is over.

See the test(s) for usage, it's quite simple.

It can be used instead of double and float values seamlessly.

Possible enhancements: 
- add the time provider as an optional template parameter (for real testability)
- instead of linear interpolation use any function (splines, yesss)

Have fun!
