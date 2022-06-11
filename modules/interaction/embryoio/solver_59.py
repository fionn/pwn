#!/usr/bin/env python3

import glob
import subprocess

challenge_file = glob.glob("/challenge/embryoio_level*")[0]

p_0 = subprocess.Popen("echo mjzdkktr && sleep 1", shell=True, stdout=subprocess.PIPE)
p_1 = subprocess.Popen(["rev"], stdin=p_0.stdout, stdout=subprocess.PIPE)
p_2 = subprocess.Popen(["rev"], stdin=p_1.stdout, stdout=subprocess.PIPE)
p_3 = subprocess.run([challenge_file], stdin=p_2.stdout, capture_output=True)

print(p_3.stdout.decode())
