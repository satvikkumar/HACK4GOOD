# HACK4GOOD
RVCE Hackathon 


ReciverArdu :- For NRF (long range communication) b/w the signal and Ambulance (still in progress)

Index :- map gui interface showing live images of traffic junction

pi :- takes the image of the traffic and sends it to cloud server (PESU in this case) and gets processed data from server , sends it to pi for sequencing of signal

ser :- takes the image from pi , detects the density of vehicles , process the image , send signal sequence to pi based on density of traffic

traffic.ino :- the sequence we plan to use for normal operation , yet to design dynamic operation signal sequencing
