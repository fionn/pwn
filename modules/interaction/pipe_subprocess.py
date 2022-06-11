import subprocess

with subprocess.Popen(["grep", "pwn"], stdin=subprocess.PIPE, stdout=subprocess.PIPE) as p_1:
    p_0 = subprocess.run(["/challenge/embryoio_level49"], stdout=p_1.stdin, check=True)
    assert p_1.stdin is not None
    assert p_1.stdout is not None
    p_1.stdin.flush()
    p_1.stdin.close()

    print(p_1.stdout.read().decode())

p_0 = subprocess.Popen("echo ljkkbyxf && sleep 1", shell=True, stdout=subprocess.PIPE)
p_1 = subprocess.Popen(["cat"], stdin=p_0.stdout, stdout=subprocess.PIPE)
p_2 = subprocess.run(["/challenge/embryoio_level52"], stdin=p_1.stdout, capture_output=True)

print(p_2.stdout.decode())
