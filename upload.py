#!/usr/bin/env python3
import sys
import subprocess

print('Upload script executing...')

program = True
if len(sys.argv) > 3 and sys.argv[2] == 'direct':
    program = False

if program:
    print('Programming with arduino as isp')
    subprocess.call(['platformio', 'run', '-t', 'program', '-e', 'uno_programmer'])
else:
    print('Uploading to arduino directly')
    subprocess.call(['platformio', 'run', '-t', 'upload', '-e', 'uno'])
