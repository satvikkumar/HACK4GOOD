#!/usr/bin/expect
for {set i 1} {$i < 3} {incr i 1} {

set prompt {\$ $};    
spawn bash

expect -re $prompt
send "raspistill -o image.jpg\r"
expect eof

expect -re $prompt
send "ssh satvik@10.10.1.91\r"
expect "satvik@10.10.1.91's password:"
send "satvik\r"
expect eof

spawn sftp satvik@10.10.1.91
expect "satvik@10.10.1.91's password:"
send "satvik\n"
expect "sftp>"
send "cd /home/satvik/yolo-9000/darknet/data\n"
expect "sftp>"
send "put /home/pi/image.jpg\n"
expect "sftp>"
send "get /home/seq.txt\n"
send "exit\n"
}
