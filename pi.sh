#!/usr/bin/expect
set prompt {\$ $}    ; # this is a regular expression that should match the
                       # *end* of you bash prompt. Alter it as required.
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