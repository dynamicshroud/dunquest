# test so i can randomly generate room

import random

# inner room
ix = random.randint(3, 23) - 2
iy = random.randint(3, 13) - 2
# walls
ox = ix + 2
oy = iy + 2

# random player position
px = random.randint(0, ox)
py = random.randint(0, oy)


print(("."*ix+"\n")*iy) # flooring

print(("#"*ox+"\n")*oy) # walls

if px == ox:
    print("ox collision")
elif py == oy:
    print("oy collision")
else:
    print("no collision")
print("px = %d and py = %d" % (px,py))
print("ix = %d and iy = %d" % (ix,iy))
print("ox = %d and iy = %d" % (ox,oy))