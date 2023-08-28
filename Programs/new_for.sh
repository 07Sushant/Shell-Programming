echo "Enter a no."
read a
for i in 1...10
echo [ `expr $a\*$i ]
done
