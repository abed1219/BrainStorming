import time
from turtle import color 

def countdown(time_sec):
     while time_sec:
            mins,secs = divmod(time_sec,60)
            timeformat = '{:02d}: {:02d}'.format(mins,secs)
            print(timeformat,end = '\r')
            time.sleep(1)
            time_sec -= 1
     print("Timer Ended!")
countdown(100)

# import turtle

# colors = ['yellow','white','green', 'red','cyan' , 'blue']
# t = turtle. Turtle()
# screen = turtle.Screen()
# screen. bgcolor('Black')
# t. speed(30)
# for i in range(100):
#      t.color(colors[i%6])
#      t.fd(i*5)
#      t.left(100)
#      t. width(2)