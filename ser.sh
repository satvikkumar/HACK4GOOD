#!/usr/bin/expect
for {set i 1} {$i < 3} {incr i 1} {

set prompt {\$ $};
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
send "put /home/satvik/yolo-9000/darknet/data/image.jpg\r"

spawn bash
expect "satvik@pes:~$ "
send "cd /home/satvik/yolo-9000/darknet\r"
expect "satvik@pes:~$ "
send "./darknet detector test cfg/combine9k.data cfg/yolo9000.cfg ../yolo9000-weights/yolo9000.weights /home/satvik/yolo-9000/darknet/data/horses.jpg > /home/satvik/data.txt\r"
expect "satvik@pes:~$ "
send "grep -c '\<\(bus\|car\)\>' /home/satvik/data.txt >> /home/satvik/num.txt\r"
 
spawn lftp

expect "lftp :~> "
send "set ssl:verify-certificate no\r"
expect "lftp :~> "
send "lftp ftp://epiz_20655524@ftp.epizy.com\r"
expect "Password: "
send "Saps007\r"
expect "lftp epiz_20655524@ftp.epizy.com:~> "
send "cd htdocs/data\r"
expect "lftp epiz_20655524@ftp.epizy.com:/htdocs/data> "
send "put /home/satvik/num.txt\r"
expect "lftp epiz_20655524@ftp.epizy.com:/htdocs/data> "
send "exit"
}
