echo "Enter a no. : "
read n

a=0
b=1
i=0

echo "Term 1 =0"
echo "Term 2 =1"

while [ $i -lt `expr $n - 2` ]
do
	sum=`expr $a + $b`
		a=$b
		b=$sum 
i=`expr $i + 1`
echo "Term `expr $i + 2` = $sum"
done

