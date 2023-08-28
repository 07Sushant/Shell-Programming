echo "Enter a no. :"
read a
echo "Enter another no. :"
read b
echo "List of operations available : 1.)Addition  2.)Subtraction  3.)Multiplication"
echo "Enter your choice : "
read c

if [ "$c" -eq 1 ]
then 
    echo "Sum : "$(( a + b ))
fi

if [ "$c" -eq 2 ]
then 
    echo "Difference : "$(( a - b ))
fi

if [ "$c" -eq 3 ]
then 
    echo "Product : "$(( a * b ))
fi
