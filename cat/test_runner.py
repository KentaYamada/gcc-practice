# -*-coding: utf-8 -*-
import subprocess

target = "./cat "
files = ["./sample.txt", ""]
i = 1
for file in files:
    cmd = target + file
    expected = subprocess.call(cmd, shell=True)
    if expected == 0:
        print("test case no.{0} succeeded.".format(i))
    else:
        print("test case no.{0} failed.".format(i))
    i = i + 1
