#!/usr/bin/expect

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
