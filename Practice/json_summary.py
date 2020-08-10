from __future__ import division
import sys
import json
import os
import socket
import datetime

def convertTime(t):
    return datetime.datetime.utcfromtimestamp(t /1000000.0)

if len(sys.argv) < 3:
    print("Usage: convert.py input_file.json output_dir")
    exit(1)

fnInp = sys.argv[1]
outPath = sys.argv[2]
fnOut = os.path.basename(sys.argv[1])
fnOut = os.path.splitext(fnOut)[0]
fnOut = os.path.join(outPath, fnOut +'.csv')

fInp = open(fnInp, 'r')
fOut = open(fnOut, 'w')

trace = json.load(fInp)
fOut.write('Operation Name,Duration(ms),No of iteration,Duration/iteration,overall contribution %\n')
ops= set()
for event in trace['traceEvents']:
    if event['ph'] == 'X':
        ops.add(event['name']) 
print(ops)

total =0
for operation in ops:
    duration = 0
    count = 0
    avg=0.0
    for event in trace['traceEvents']:
        if event['name'] == operation:
            total+=int(event['dur'])
           
print(total)
for operation in ops:
    duration = 0
    count = 0
    avg=0
    for event in trace['traceEvents']:
        if event['name'] == operation:
            duration+=event['dur']
            count+=1
        
    avg = round(duration/count,2)
    percent = round(duration/total,4)*100
    s = operation + ','
    s += str(duration)+','
    s += str(count) + ','
    s += str(avg) + ','
    s += str(percent) + ','
    s += ',\n'
    
    fOut.write(s)

"""
for event in trace['traceEvents']:
    if event['ph'] == 'X':
        t = int(event['ts'])
        tbUtc = convertTime(t)
        teUtc = convertTime(t + int(event['dur']))
        duration=str(event['dur'])
        #argument=str(event['args'])
        s = event['name'] + ','
        #s += str(tbUtc) + ','
        #s += str(teUtc) + ','
        s += duration + ','
        s += ',\n'
        fOut.write(s)
 """       

