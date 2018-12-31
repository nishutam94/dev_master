#!/usr/bin/env bash
NAME="Nishant"
echo "$NAME"
echo $NAME
echo "${NAME}!"

get_name()
{
 echo "NISHANT"
}

echo $(get_name)

#if ["$NAME1"]; then
# echo "Strng is empty";
#elif ["$NAME"]; then
# echo "Strng is not empty";
#f

for i in {1..10..3}; 
do
 echo "$i"
done

arg_function()
{
  echo "$1"
 
}

arg_function "Nishant"

echo ${arg_function}
arrays=('Neha' 'Nishant' 'mammi' 'Papa')


for i in "${arrays[@]}";
do 
 echo $i
done
echo ${arrays[2]}

echo "enter the number"
read nu
echo "$nu"
q=`expr $nu % 2`

if [ $q -eq 0 ];
then 
	echo "This is even"
else
	echo "this is odd"
fi




