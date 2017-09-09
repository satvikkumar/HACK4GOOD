# HACK4GOOD
RVCE Hackathon 
Problem Statement :- To have live traffic re-direction via street cams and image processing

With the ever increasing number of vehicles on the road , traditional methods of traffic signals fail to serve the need to avoid traffic congestion and effective flow.
Thus , our project aims at providing a solution to this exponential problem.

With the help of image processing , machine learning , IOT and cloud computing , we were able to come up with a unique solution.

ReciverArdu.py :- For NRF (long range communication) b/w the signal and Ambulance . 

Index.html :- map gui interface showing live images of traffic junction with predicted traffic densities 

pi.sh :- takes the image of the traffic and sends it to cloud server (PESU in this case) and gets processed data from server , sends it to pi for sequencing of signal

ser.sh :- takes the image from pi , detects the density of vehicles , process the image , send signal sequence to pi based on density of traffic

traffic_light.ino :- the sequence we plan to use for normal operation , yet to design dynamic operation signal sequencing

Pi1.py :- Meant for the dynamic operation of the signal based on vehichle density

Sequence.py :- Finds the Maximum Density of the 4 roads at that signal junction.
