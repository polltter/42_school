#!/bin/bash
arc=$(uname -a)
pcpu=$(lscpu | grep "Socket" | cut -d " " -f 24)
vCPU=$(cat /proc/cpuinfo|grep processor|wc -l)
uMem=$(free --mega | grep Mem | awk '{print $3}')
tMem=$(free --mega | grep Mem | awk '{print $2}')
perMem=$(free --mega | grep Mem | awk '{printf "%.2f", $3/$2*100}')
uDisk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{uD+=$3} END {print uD}')
tDisk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{tD+=$2} END {print tD}')
pDisk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{uD+=$3} {tD+=$2} END {printf "%.0f", uD/tD*100}')
pCpu=$(uptime | awk '{printf "%.1f%%", $(NF-2)}')
lb=$(who -b | awk '{print $3 " " $4}')
lvmc=$(lsblk | grep "lvm" | wc -l)
lvmif=$(if [ $lvmc -eq 0 ]; then echo no; else echo yes; fi)
#install net-tools
tcpcon=$(cat /proc/net/sockstat{,6} | awk '$1 == "TCP:" {print $3}')
ul=$(users | wc -w)
IP=$(hostname -I)
MAC=$(ip link show | awk '$1 == "link/ether" {print $2}')
sudologs=$(journctl _COMM=sudo | grep COMMAND | wc -l)

wall "#Architecture: $arc
#CPU physical: $pcpu
#vCPU: $vCPU
#Memory Usage: $uMem/${tMem}MB (${perMem}%)
#Disk Usage: $uDisk/${tDisk}Gb (${pDisk}%)
#CPU load: $pCpu
#Last Boot: $lb
#LVM use: $lvmif
#Connections TCP: $tcpcon ESTABLISHED
#User log: $ul
#Network: $MAC
#Sudo: $sudologs cmd"
