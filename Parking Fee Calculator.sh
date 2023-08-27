#!/bin/bash
echo "_______________________________________"

echo "Welcome to the Parking Fare Calculator"
echo "_______________________________________"

echo "Choose vehicle type:"

echo "1.Bike"

echo "2.jeep"

echo "3.bicycle"

echo "4.car"



read x



case $x in

    1)time=10;;                 
    2)time=20;;
    3)time=5;;
    4)time=30;;*)
   echo "Sorry you can't afford vehicle "
   exit 1;;
   
   esac    
   echo "For how long you want to park the vehicle:"
read hours
total=$((time * hours))
echo "Total parking fare: $total"
                                                                                        
                                                                                        
