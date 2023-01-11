#!/usr/bin/python3
import os, random

alpha = ['a', 'b', 'c']
it = 0
while True:
    it += 1
    if it % 100 == 0:
        print("Testing tests #" + str(it))

    s = ''.join(random.choices(alpha, k=random.randint(3, 20)))
    with open('/tmp/orig', 'w') as f:
    	f.write(s + "\n")
    	f.close()
    os.system("echo '1' > /tmp/enc")
    os.system("python3 E.py < /tmp/orig >> /tmp/enc")
    os.system("python3 F.py < /tmp/enc > /tmp/dec")

    th = open('/tmp/dec').readlines()[0].strip()
    if s != th:
    	print("Original:", s)
    	print("Got     :", th)
    	exit()
