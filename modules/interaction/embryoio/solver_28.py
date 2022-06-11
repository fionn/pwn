#!/usr/bin/env python3

import glob
import subprocess

challenge_file = glob.glob("/challenge/embryoio_level*")[0]

cmd = [challenge_file]
p = subprocess.run(cmd, env={})
