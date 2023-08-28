echo "Enter a no."
read a
i=1
while [ $i -le 10 ]
do
	echo `expr $a \* $i`
	i=`expr $i + 1`
done


