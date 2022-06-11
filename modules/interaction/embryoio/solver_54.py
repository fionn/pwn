#!/usr/bin/env python3

import glob
import subprocess

challenge_file = glob.glob("/challenge/embryoio_level*")[0]

with subprocess.Popen(["cat"], stdin=subprocess.PIPE, stdout=subprocess.PIPE) as p_1:
    p_0 = subprocess.run([challenge_file], stdout=p_1.stdin, check=True)
    assert p_1.stdin is not None
    assert p_1.stdout is not None
    p_1.stdin.flush()
    p_1.stdin.close()

    print(p_1.stdout.read().decode())
