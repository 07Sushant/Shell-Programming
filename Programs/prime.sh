echo "Enter a number : "
read a
f=0

if [ $a -eq 2 ]; then
  echo "2 is a prime number"
else
  for (( i=2; i <= a/2; i++ ))
  do
    if [ $(( a % i )) -eq 0 ]; then
      f=1
      break
    fi
  done
  
if [ $f -eq 0 ]; then
  echo $a "is a prime number."
else
  echo $a "is not a prime number."
fi
fi

