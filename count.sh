#!/bin/bash

while true

do
   
# pscp -pw LIGHTCONE pi@192.168.1.3:/home/pi/image.jpg /mnt/c/Users/"Mohan Prabhakar"/Downloads
 
 
./darknet detect cfg/yolo.cfg yolo.weights /mnt/c/Users/"Mohan Prabhakar"/Downloads/image.jpg > /mnt/c/Users/"Mohan Prabhakar"/Downloads/as.txt
 
  grep -c '\<\(bus\|car\)\>' /mnt/c/Users/"Mohan Prabhakar"/Downloads/as.txt > /mnt/c/Users/"Mohan Prabhakar"/Downloads/a.txt
  
  pscp -pw LIGHTCONE /mnt/c/Users/"Mohan Prabhakar"/Downloads/a.txt pi@192.168.1.3:/home/pi

  sleep 5

done
