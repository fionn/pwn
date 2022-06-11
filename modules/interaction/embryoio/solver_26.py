#!/usr/bin/env python3

import glob
import subprocess

challenge_file = glob.glob("/challenge/embryoio_level*")[0]

redir_file = "/tmp/twlqgh"
with open(redir_file, "w") as fd:
    fd.write("exezdrqn")

cmd = [challenge_file]
p = subprocess.run(cmd, stdin=open(redir_file))
print(p)
