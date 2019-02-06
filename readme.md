# Timely Changing Value

## A simple value class for making animations and such

For any given number, tell it in the constructor how long should it take to 
change, than assign to it another number. Reading the number during the change 
period will result a linear interpolated value, and the assignment is only 
finished after the change period is over.

See the tests for usage, it's quite simple.

It can be used instead of double and float values seamlessly.

Possible enhancements: 
- going generic in the value type
- instead of linear interpolation use any function (splines, yesss)

Have fun!
