"""HelloWorld controller."""

# You may need to import some classes of the controller module. Ex:
#  from controller import Robot, Motor, DistanceSensor
from controller import Robot, Motor, DistanceSensor
from math import pi, sin
# create the Robot instance.
robot = Robot()

# get the time step of the current world.
TIME_STEP = 32
MAX_SPEED = 6.28 # rad/s

# You should insert a getDevice-like function in order to get the
# instance of a device of the robot. Something like:
left_motor = robot.getDevice('left wheel motor')
right_motor = robot.getDevice('right wheel motor')
left_motor.setPosition(float("inf"))
right_motor.setPosition(float("inf"))
left_motor.setVelocity(0.0)
right_motor.setVelocity(0.0)
motor_speed = 0.25 * MAX_SPEED

wh_radius = 0.021 # r
dist_btw_wh = 0.052 # 2l
lin_vel = wh_radius * motor_speed # linear velocity
rot_vel = (2 * lin_vel)/dist_btw_wh # rotational velocity


sq_len = 0.1
dur_onesq = sq_len/lin_vel
time_drive = 4 * dur_onesq

start_time = robot.getTime()

# Main loop:
# - perform simulation steps until Webots is stopping the controller
while robot.step(TIME_STEP) != -1:
    current_time = robot.getTime()
    if (current_time - start_time) < time_drive:
        left_motor.setVelocity(motor_speed)
        right_motor.setVelocity(motor_speed)
        print("moving")
    else:
        left_motor.setVelocity(0.0)
        right_motor.setVelocity(0.0)
        print("stop")

# Enter here exit cleanup code.