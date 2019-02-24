# collide pt. 2
import random

# inner room
ix = random.randint(3, 23) - 2
iy = random.randint(3, 13) - 2

# player pos
x = random.randint(0, ix+2)
y = random.randint(0, iy+2)


        
print("position: %d - %d" % (x,y))
print("wx: %d - wy: %d - ix: %d - iy: %d" % (ix+2, iy+2, ix, iy))