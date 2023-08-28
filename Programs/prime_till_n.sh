echo "Enter the value of n : "
read n
i=0
while [ $i -lt $n ]
do
	if [ $i -ge 2 ]
	then
		if [ $i -eq 2 ]
		then
			echo "2 "
		else
			j=2
			flag=1 
			while [ $j -lt $i ]
			do
				if [ `expr $i % $j` -eq 0 ]
				then 
					flag=0
					break
				fi
			j=`expr $j + 1`
			done
			if [ $flag -eq 1 ]
			then
			echo "$i "
			fi
		fi
	fi
	i=`expr $i + 1`
done
	
	
		
			
