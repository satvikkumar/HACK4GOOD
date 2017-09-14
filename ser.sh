#!/usr/bin/expect
for {set i 1} {$i < 3} {incr i 1} {

set prompt {\$ $};

spawn bash
expect "satvik@pes:~$ "
send "cd /home/satvik/darknet\r"

expect "satvik@pes:~$ "
send "./darknet detector test cfg/coco.data cfg/yolo.cfg yolo.weights data/image1.jpg"
expect "satvik@pes:~$ "
send "cp /home/satvik/darknet/predictions.png /home/satvik/predictions1.png\r"

expect "satvik@pes:~$ "
send "./darknet detector test cfg/coco.data cfg/yolo.cfg yolo.weights data/image2.jpg"
expect "satvik@pes:~$ "
send "cp /home/satvik/darknet/predictions.png /home/satvik/predictions2.png\r"

expect "satvik@pes:~$ "
send "./darknet detector test cfg/coco.data cfg/yolo.cfg yolo.weights data/image3.jpg"
expect "satvik@pes:~$ "
send "cp /home/satvik/darknet/predictions.png /home/satvik/predictions3.png\r"

expect "satvik@pes:~$ "
send "./darknet detector test cfg/coco.data cfg/yolo.cfg yolo.weights data/image4.jpg"
expect "satvik@pes:~$ "
send "cp /home/satvik/darknet/predictions.png /home/satvik/predictions4.png\r"

expect "satvik@pes:~$ "
send "grep -c '\<\(bus\|car\)\>' /home/satvik/data1.txt > /home/satvik/num.txt\r"

expect "satvik@pes:~$ "
send "grep -c '\<\(bus\|car\)\>' /home/satvik/data2.txt >> /home/satvik/num.txt\r"

expect "satvik@pes:~$ "
send "grep -c '\<\(bus\|car\)\>' /home/satvik/data3.txt >> /home/satvik/num.txt\r"

expect "satvik@pes:~$ "
send "grep -c '\<\(bus\|car\)\>' /home/satvik/data4.txt >> /home/satvik/num.txt\r"
 
spawn lftp

expect "lftp :~> "
send "set ssl:verify-certificate no\r"
expect "lftp :~> "
send "lftp ftp://epiz_20655524@ftp.epizy.com\r"
expect "Password: "
send "Saps007\r"
expect "lftp epiz_20655524@ftp.epizy.com:~> "
send "cd htdocs/images\r"

expect "lftp epiz_20655524@ftp.epizy.com:/htdocs/images> "
send "put /home/satvik/predictions1.png\r"

expect "lftp epiz_20655524@ftp.epizy.com:/htdocs/images> "
send "put /home/satvik/predictions2.png\r"

expect "lftp epiz_20655524@ftp.epizy.com:/htdocs/images> "
send "put /home/satvik/predictions3.png\r"

expect "lftp epiz_20655524@ftp.epizy.com:/htdocs/images> "
send "put /home/satvik/predictions4.png\r"

expect "lftp epiz_20655524@ftp.epizy.com:/htdocs/images> "
send "cd htdocs/data\r"
expect "lftp epiz_20655524@ftp.epizy.com:/htdocs/data> "
send "put /home/satvik/num.txt\r"
expect "lftp epiz_20655524@ftp.epizy.com:/htdocs/data> "
send "exit"
}
