red=`tput setaf 1`
green=`tput setaf 2`
yellow=`tput setaf 3`
idont=`tput setaf 6`

(make fclean -C ../ && make -C ../) > /dev/null
for i in {1..100}; do  echo "$yellow================= ${idont}TEST $i ${yellow}=================================";
    ARG="$(python3 random.numbers.py $1 | tr '\n' ' ' > ./test_files/test_$i.txt; cat ./test_files/test_$i.txt)";
if [ "$( ../push_swap $ARG | ./checker_Mac $ARG)" = "OK" ] ; then 
    echo "${green}R -->[OK]\nN --> $(../push_swap $ARG | wc -l | awk '{printf $1}')"
else
    echo "${red}R -->[KO]\nN ${red}--> $(../push_swap $ARG | wc -l | awk '{printf $1}')"
fi
line=$(../push_swap $ARG | wc -l | awk '{printf $1}')
sum=`expr $sum + $line`
done;
mean=`expr $sum / $i`
echo "$mean"
echo "${yellow}=================  ${red}END ${yellow}================================="
