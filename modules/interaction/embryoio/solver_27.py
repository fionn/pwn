#!/usr/bin/env python3

import glob
import subprocess

challenge_file = glob.glob("/challenge/embryoio_level*")[0]

redir_file = "/tmp/wagjap"
with open(redir_file, "w") as fd:
    fd.write("")

cmd = [challenge_file]
p = subprocess.run(cmd, stdout=open(redir_file, "w"))

with open(redir_file) as fd:
    print(fd.read())
