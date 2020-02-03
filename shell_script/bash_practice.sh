#!/usr/bin/env bash

echo "--------varibale declearation---------"

NAME="Nishan"
echo "$NAME"
echo $NAME
echo "${NAME}!"
echo ${NAME}!

echo "-----------get name function-----------"
get_name()
{
 echo "get name function called"
}
echo $(get_name)


echo "----------simple for loop--------------"
for i in {1..10..2}; 
do
 echo "$i"
done


echo "-----------function with arguments----------"
arg_function()
{
  echo "$1"
  echo "$2"
 
}
arg_function "argument1" "argument2"
echo ${arg_function}


echo "--------------Arreys-------------------"
arrays=('value1' 'value2' 'value3' 'value4')
for i in "${arrays[@]}";
do 
 echo $i
done
echo ${arrays[2]}


echo "-------------Read and if else -----------"
echo "enter the number"
#read nu
nu=2 
echo "$nu"
q=`expr $nu % 2`
if [ $q -eq 0 ]
then 
	echo "This is even"
else
	echo "this is odd"
fi


echo "-------------print all the file name -----------"
for i in *
do
echo  $i
done


echo "------------- while -----------"
i=5
while [ $i != 0 ] 
do
 echo -n "$i"
 i=`expr $i - 1`
done

echo "------------- case -----------"
case $NAME in 
	 Nishant) 
           echo "Hi nishant"
           NAME="bye"
           ;;
         bye)
           echo "Bye"
           ;;
          *)         
           echo "dont know what are you saying"
           ;;
esac           


echo "------------- variable -----------"
echo $0


echo "------------- grep -----------"
grep "^${USER}:" /etc/passwd 
grep "^${USER}:" /etc/passwd | cut -d: -f5

grep "^${USER}:" /etc/passwd | cut -d: -f7
grep "^${USER}:" /etc/passwd | cut -d/ -f3




echo "------------- find  -----------"
#find . -name "*.sh" -print | grep "*_practice*"
find . -name "*.sh" 
