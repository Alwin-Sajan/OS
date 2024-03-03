# !/bin/bash
 
 echo "CALCULATOR"
 echo "Enter the number:"
 read a
 read b
 echo "M  E  N  U"
 echo "1)Addition 2)Subtraction 3)Multiplication 4)Division"
 echo "Enter the operation:"
 read op
 case $op in
  1)
    echo -n "The sum of $a & $b are:"
    c= expr $a + $b
    ;;
  2)
    echo -n "The remainder of $a & $b are:"
    d= expr $a - $b
    ;;
  3)
    echo -n "The product of $a & $b are:"
    e= expr $a \* $b
    ;;
  4)
    echo -n "The division of $a & $b are:"
    f= expr $a / $b
    ;;
  *)
   echo "!! Invalid Option !!"
  ;;
 esac
