echo "Enter a number: "
read p
echo "Enter another number: "
read q
let "a=$p+$q"
b=`expr $p+$q`
echo "Sum using let is : $a"
echo "Sum using Expr is : $b"
