import sys
import RPi.GPIO as GPIO
import time

temp = (sys.stdin.read())
a1 = (temp.split(' '))

a1[0] = int(a1[0])
a1[1] = int(a1[1])

running = True;
while running:
	R1 = 17
	G1 = 18
	R2 = 14
	G2 = 15
	R3 = 22
	G3 = 23
	R4 = 24
	G4 = 25

	GPIO.setmode(GPIO.BCM)
	GPIO.setwarnings(False)
	GPIO.setup(R1,GPIO.OUT)
	GPIO.setup(R2,GPIO.OUT)
	GPIO.setup(G1,GPIO.OUT)
	GPIO.setup(G2,GPIO.OUT)
	GPIO.setup(R3,GPIO.OUT)
	GPIO.setup(R4,GPIO.OUT)
	GPIO.setup(G3,GPIO.OUT)
	GPIO.setup(G4,GPIO.OUT)


	if(a1[0]==1):
    		GPIO.output(G1,GPIO.HIGH)
    		GPIO.output(G2,GPIO.LOW)
    		GPIO.output(G3,GPIO.LOW)
    		GPIO.output(G4,GPIO.LOW)
    		GPIO.output(R1,GPIO.LOW)
    		GPIO.output(R2,GPIO.HIGH)
    		GPIO.output(R3,GPIO.HIGH)
    		GPIO.output(R4,GPIO.HIGH)
    		
	end

	if(a1[0]==2):
    		GPIO.output(G1,GPIO.LOW)
    		GPIO.output(G2,GPIO.HIGH)
    		GPIO.output(G3,GPIO.LOW)
    		GPIO.output(G4,GPIO.LOW)
    		GPIO.output(R1,GPIO.HIGH)
    		GPIO.output(R2,GPIO.LOW)
    		GPIO.output(R3,GPIO.HIGH)
    		GPIO.output(R4,GPIO.HIGH)
    		
	end

	if(a1[0]==3):
    		GPIO.output(G1,GPIO.LOW)
    		GPIO.output(G2,GPIO.LOW)
    		GPIO.output(G3,GPIO.HIGH)
    		GPIO.output(G4,GPIO.LOW)
    		GPIO.output(R1,GPIO.HIGH)
    		GPIO.output(R2,GPIO.HIGH)
    		GPIO.output(R3,GPIO.LOW)
    		GPIO.output(R4,GPIO.HIGH)
    		
	end

	if(a1[0]==4):
    		GPIO.output(G1,GPIO.LOW)
    		GPIO.output(G2,GPIO.LOW)
    		GPIO.output(G3,GPIO.LOW)
    		GPIO.output(G4,GPIO.HIGH)
    		GPIO.output(R1,GPIO.HIGH)
    		GPIO.output(R2,GPIO.HIGH)
    		GPIO.output(R3,GPIO.HIGH)
    		GPIO.output(R4,GPIO.LOW)
    		
	end
     time.sleep(a1*1.5)
	
    running = False
end

sys.exit()






