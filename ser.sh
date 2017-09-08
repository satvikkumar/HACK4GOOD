#!/bin/bash

while true

do

cd /home/satvik/yolo-9000/darknet
   
./darknet detector test cfg/combine9k.data cfg/yolo9000.cfg ../yolo9000-weights/yolo9000.weights data/image.jpg > /home/satvik/data.txt

grep -c '\<\(bus\|car\)\>' /home/satvik/data.txt > /home/satvik/num.txt

  sleep 5

done
