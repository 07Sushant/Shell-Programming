echo " Enter the no. to print the table of : "
read a
for (( i=1; i<=10; i++ ))
do
let "b = $i*$a"
echo $b
done
