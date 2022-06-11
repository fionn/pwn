#!/usr/bin/env python3

import glob
import subprocess

challenge_file = glob.glob("/challenge/embryoio_level*")[0]

with subprocess.Popen(["rev"], stdin=subprocess.PIPE, stdout=subprocess.PIPE) as p_2:
    with subprocess.Popen(["rev"], stdin=subprocess.PIPE, stdout=p_2.stdin) as p_1:
        p_0 = subprocess.run([challenge_file], stdout=p_1.stdin)
        p_1.stdin.flush()
        p_1.stdin.close()

    p_2.stdin.flush()
    p_2.stdin.close()

    print(p_2.stdout.read().decode())
