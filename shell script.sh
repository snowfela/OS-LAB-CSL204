:'AIM: To implement the following programs using shell script
        a) To print normal calculator.
        b) To check leap year or not.
        c) To sort a set of numbers using for loop.
        d) To find factorial using function.
        e) To print floyd’s triangle.
            1
            2 3
            4 5 6
            7 8 9 10
            ...
'
____________________________________________________________
# (a) To print normal calculator
read -p "Enter the numbers: " a b
sum=$(($a+$b))
diff=$(($a-$b))
product=$(($a*$b))
div=$(($a/$b))
echo "Sum = $sum"
echo "Difference = $diff"
echo "Product = $product"
echo "Quotient = $div"

#output:
Enter the numbers: 10 5
Sum = 15
Difference = 5
Product = 50
Quotient = 2
____________________________________________________________
# (b) To check leap year or not
read -p "Enter the year: " y
if ((($y%4==0) && ($y%100!=0) || ($y%400==0)))
	then echo "Leap Year"
else
	echo "Not Leap Year"
fi

#output:
Enter the year: 2004
Leap Year
____________________________________________________________
# (c) To sort a set of numbers using for loop.
read -a arr -p "Enter the elements of array: " 
i=0
for n in ${arr[*]};
do 
	i=$((i+1))
done
echo "Original Array  ${arr[*]}"
for ((k = 0; k<i; k++))
do
    for((l = 0; l<i-k-1; l++))
    do
        if [ ${arr[l]} -gt ${arr[$((l+1))]} ]
        then  #swap
            temp=${arr[l]}
            arr[$l]=${arr[$((l+1))]}  
            arr[$((l+1))]=$temp
        fi
    done
done
echo "Sorted Array  ${arr[*]}"

#output:
Enter the elements of array: 5 3 1 7 8
Original Array  5 3 1 7 8
Sorted Array  1 3 5 7 8
____________________________________________________________
# (d) To find factorial using function.
fact(){
	read -p "Enter the number: " n
	f=1
	for((i=1; i<=n; i++))
	do f=$((f*i))
	done
	echo "Factorial = $f"
}
fact 

#output:
Enter the number: 5
Factorial = 120
____________________________________________________________
#(e) To print floyd’s triangle.
read -p"Enter the value of n: " n
num=1
for((i=1; i<=n; i++))
do
  for((j=1; j<=i; j++))
  do
    echo -n "$num "
    num=$((num + 1))
  done
  echo
done

#output:
Enter the value of n: 5
1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15 
