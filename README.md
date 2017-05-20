
## Control of locomotion of robot through rosserial (REMOTE).

part-1 ]   
1.Install arduino ide and ROS on the Raspi.
2.Now unzip the ros.zip and add the ros_lib in arduino libraries.
3.Extract the rosserial.zip inside workspace/src (say catkin_ws/src) .

part-2 ]

1.Connect the arduino to raspi and upload the two ino files,attatched above.

2.Now it's time to fire roscore on the terminal.(If you are familiar eith ROS then go ahead otherwise visit the ROS tutorial and learn )

3.Open a new terminal and type $  rosrun rosserial_python serial_node.py /dev/<portName>
##portName you will find in ide.  // If connected the proceed to step 4

4.rostopic pub <topic name> std_msgs/String <"string">
##Try to find the <topic name> and <string> by understanding the ino files.
5.Enjoy the success.
_______________________________________________________________________________________________________________________________
NOTE: Use ssh for remote control over raspi because it would be better to move the bot freely.

Expected outcome: Say if we type "F" then bot will start moving forward. 
