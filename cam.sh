#!/bin/bash
while true
do
   raspistill -o image.jpg
   #sleep 60
   a=$(grep -o -E '[0-9]+' a.txt)
   b=$(grep -o -E '[0-9]+' b.txt)
   c=$(grep -o -E '[0-9]+' c.txt)
   d=$(grep -o -E '[0-9]+' d.txt)
   echo $a
   echo $b
   echo $c
   echo $d

   if [ $a -gt 20 ] && [ $b -lt 5 ] && [ $c -lt 5 ] && [ $d -lt 5 ]
    then
     gpio -g write 4 0
     #gpio -g write 23 1
     #gpio -g write 24 1
     #gpio -g write 25 1 
     sleep 5
     gpio -g write 4 0
     gpio -g write 18 1
     gpio -g write 23 1
     gpio -g write 24 1
     gpio -g write 25 1 
     sleep 5

   elif [ $a -le 5 ] && [ $b -ge 20 ] && [ $c -le 5 ] && [ $d -le 5 ]
     then
     gpio -g write 17 1
     gpio -g write 18 1
     gpio -g write 24 1
     gpio -g write 25 1 
     sleep 5
     gpio -g write 17 0
     gpio -g write 18 1
     gpio -g write 23 1
     gpio -g write 24 1
     gpio -g write 25 1 
     sleep 5

   elif [ $a -le 5 ] && [ $b -le 5 ] && [ $c -ge 20 ] && [ $d -le 5 ]
     then
     gpio -g write 22 1
     gpio -g write 18 1
     gpio -g write 23 1
     gpio -g write 25 1 
     sleep 5
     gpio -g write 22 0
     gpio -g write 18 1
     gpio -g write 23 1
     gpio -g write 24 1
     gpio -g write 25 1 
     sleep 5

   elif [ $a -le 5 ] && [ $b -le 5 ] && [ $c -le 5 ] && [ $d -ge 20 ]
     then
     gpio -g write 27 1
     gpio -g write 18 1
     gpio -g write 23 1
     gpio -g write 24 1 
     sleep 5
     gpio -g write 22 0
     gpio -g write 18 1
     gpio -g write 23 1
     gpio -g write 24 1
     gpio -g write 25 1 
     sleep 5
    
   fi
   
done