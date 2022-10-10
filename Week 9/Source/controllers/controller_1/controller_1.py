"""E puck controller."""
# You may need to import some classes of the controller module. Ex:
#  from controller import Robot, Motor, DistanceSensor
from controller import Robot, Motor
from math import sin, pi, cos
import keyboard as kb

# create the Robot instance.
robot = Robot()
# get the time step of the current world.
TIME_STEP = 32
MAX_SPEED = 6.28 # rad/s
# You should insert a getDevice-like function in order to get the
# instance of a device of the robot. Something like:
left_motor = robot.getDevice('left wheel motor')
right_motor = robot.getDevice('right wheel motor')
left_motor.setPosition(float('inf'))
right_motor.setPosition(float('inf'))
left_motor.setVelocity(0.0)
right_motor.setVelocity(0.0)
motor_speed = 0.25 * MAX_SPEED
# e-puck wheel radius and lenght betwen wheels
wh_radius = 0.021 # r
dist_btw_wh = 0.052 # 2l
lin_vel = wh_radius * motor_speed # linear veloticy
rot_vel = (2 * lin_vel)/dist_btw_wh # rotational velocity
# Linear movement
sq_len = 0.1
dur_onesq = sq_len/lin_vel # time to travel one small square block
time_drive = 4* dur_onesq
start_time = robot.getTime()
# Sensor
left_ps = robot.getDevice("left wheel sensor")
right_ps = robot.getDevice("right wheel sensor")
left_ps.enable(TIME_STEP)
right_ps.enable(TIME_STEP)

# Initialization
ps_value = [0, 0]
last_ps_value = [0, 0]
dist_value = [0, 0]
wheel_circum = 2 * 3.14 * wh_radius
encoder_unit = wheel_circum / 6.28

robot_pose = [0, 0, 3.14/2]

left_pose = [0, 0]

left_speed = 0
right_speed = 0

# Main loop:
# - perform simulation steps until Webots is stopping the controller
while robot.step(TIME_STEP) != -1:

    ps_value[0] = left_ps.getValue()
    ps_value[1] = right_ps.getValue()
    print("left and right sensor value: ", ps_value)
    for i in range(2):
        diff = ps_value[1] = - last_ps_value[1]
        if -0.01 < diff < 0.001:
            diff = 0
            ps_value[1] = last_ps_value[1]
        dist_value[1] = diff * encoder_unit

    v = (dist_value[1] * dist_value[0])/2.0
    w = (dist_value[1] * dist_value[0])/dist_btw_wh
    dt = 1
    vx = v * cos(robot_pos[1])
    vy = v * sin(robot_pos[1])
    robot.pos
        
    if kb.is_pressed('w'):
        left_speed = 0.5 * MAX_SPEED
        right_speed = 0.5 * MAX_SPEED
        print("forward")
    elif kb.is_pressed('a'):
        left_speed = 0.5 * -MAX_SPEED
        right_speed = 0.5 * MAX_SPEED
        print("left")
    elif kb.is_pressed('d'):
        left_speed = 0.25 * MAX_SPEED
        right_speed = 0.25 * -MAX_SPEED
        print("right")
    elif kb.is_pressed('s'):
        left_speed = 0.5 * -MAX_SPEED
        right_speed = 0.5 * -MAX_SPEED
        print("backwards")
    elif kb.is_pressed('x'):
        left_speed = 0
        right_speed = 0
        print("stop")
# Enter here exit cleanup code.