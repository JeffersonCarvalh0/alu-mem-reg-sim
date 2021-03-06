#! /usr/bin/python3
# encoding: utf-8

# script to get a binary from an assembly code

from sys import stdin
from subprocess import Popen, PIPE
import io

#variables to store the binaries
rType = {
    'add': '100000', # decimal 32, R instruction
    'sub': '100010', # decimal 34, R instruction
    'and': '100100', # decimal 36, R instruction
    'or': '100101', # decimal 37, R instruction
    'xor': '100110', # decimal 38, R instruction
    'nor': '100111', # decimal 39, R instruction
    'slt': '101010', # decimal 42, R instruction
}

iType = {
    'addi': '001000', # decimal 8, I instruction
    'lw': '100011', # decimal 35, I instruction
    'sw': '101011' # decimal 43, I instruction
}

registers = {'zero':'00000', #$zero decimal 0
             't0':'01000', #$t0 decimal 8
             't1':'01001', #$t1 decimal 9
             't2':'01010', #$t2 decimal 10
             't3':'01011', #$t3 decimal 11
             't4':'01100', #$t4 decimal 12
             't5':'01101', #$t5 decimal 13
             't6':'01110', #$t6 decimal 14
             't7':'01111', #$t7 decimal 15
             's0':'10000', #$s0 decimal 16
             's1':'10001', #$s1 decimal 17
             's2':'10010', #$s2 decimal 18
             's3':'10011', #$s3 decimal 19
             's4':'10100', #$s4 decimal 20
             's5':'10101', #$s5 decimal 21
             's6':'10110', #$s6 decimal 22
             's7':'10111', #$s7 decimal 23
             't8':'11000', #$t8 decimal 24
             't9':'11001', #$t9 decimal 25
             }

# line = input("Put your line code here: ") # Coment this line if you do not need any tests

# Uncoment this line after tests

binary = io.StringIO()
for line in stdin:
    if line == '': #If an empty string is read then stop the loop
        break

# if(True):   # Coment this line if you do not need any tests
    #Process to take the binary
    instruction = line.split()
    operation = instruction[0]
    if(operation in rType.keys()):
        opcode = '000000'
        rd = registers[instruction[1]]
        rs = registers[instruction[2]]
        rt = registers[instruction[3]]
        shamt = '00000'
        funct = rType[instruction[0]]
        binary.write(opcode+rs+rt+rd+shamt+funct+'\n')
    else:
        opcode = iType[instruction[0]]
        rt = registers[instruction[1]]
        rs = registers[instruction[2]]
        address = bin(int(instruction[3]))[2:].zfill(16)
        binary.write(opcode+rs+rt+address+'\n')

with Popen(['./main'], stdin=PIPE, stdout=PIPE, universal_newlines=True) as datapath:
    output = datapath.communicate(input=binary.getvalue())[0]
    print(output)

binary.close()
