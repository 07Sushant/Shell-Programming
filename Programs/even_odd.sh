echo "Enter a no."
read n

if [ `expr $n % 2` -eq 0 ]
then 
	echo "$n is an even no."
else
	echo "$n is a odd no."
fi
