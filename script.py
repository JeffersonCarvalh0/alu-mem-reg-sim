#script to get a binary from an assembly code

from sys import stdin

#variables to store the binaries
funct = {'add': '00100000', # decimal 32, R instruction
         'sub': '00100010', # decimal 34, R instruction
         'and': '00100100', # decimal 36, R instruction
         'or': '00100101', # decimal 37, R instruction
         'xor': '00100110', # decimal 38, R instruction
         'nor': '00100111', # decimal 39, R instruction
         'slt': '00101010', # decimal 42, R instruction
         'addi': '00001000', # decimal 8, I instruction
         'lw': '00100011', # decimal 35, I instruction
         'sw': '00101011' # decimal 43, I instruction
          }

registers = {'t0':'01000', #$t0 decimal 8
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

for line in stdin:
    if line == '': #If an empty string is read then stop the loop
        break

    #Process to take the binary
    opcode = line.split(' ')[0]
    if(opcode in ('add', 'addi', 'sub', 'and', 'or', 'slt')):
        instructionR = line.split(' ')
        if(instrutionR[0] == 'add'):
            opcode = '000000'
            rs = registers[instructionR[1]]
            rt = registers[instructionR[2]]
            rd = registers[instructionR[3]]
            shamt = '00000'
            funct = funct[instructionR[0]]
        if(instrutionR[0] == 'sub'):
            opcode = '000000'
            rs = registers[instructionR[1]]
            rt = registers[instructionR[2]]
            rd = registers[instructionR[3]]
            shamt = '00000'
            funct = funct[instructionR[0]]
        if(instrutionR[0] == 'and'):
            opcode = '000000'
            rs = registers[instructionR[1]]
            rt = registers[instructionR[2]]
            rd = registers[instructionR[3]]
            shamt = '00000'
            funct = funct[instructionR[0]]
        if(instrutionR[0] == 'or'):
            opcode = '000000'
            rs = registers[instructionR[1]]
            rt = registers[instructionR[2]]
            rd = registers[instructionR[3]]
            shamt = '00000'
            funct = funct[instructionR[0]]
        if(instrutionR[0] == 'xor'):
            opcode = '000000'
            rs = registers[instructionR[1]]
            rt = registers[instructionR[2]]
            rd = registers[instructionR[3]]
            shamt = '00000'
            funct = funct[instructionR[0]]
        if(instrutionR[0] == 'nor'):
            opcode = '000000'
            rs = registers[instructionR[1]]
            rt = registers[instructionR[2]]
            rd = registers[instructionR[3]]
            shamt = '00000'
            funct = funct[instructionR[0]]
        if(instrutionR[0] == 'slt'):
           opcode = '000000'
            rs = registers[instructionR[1]]
            rt = registers[instructionR[2]]
            rd = registers[instructionR[3]]
            shamt = '00000'
            funct = funct[instructionR[0]]
    else:
        instructionI = line.split(' ')
        if(instrutionR[0] == 'addi'):
            opcode = funct[instructionI[0]]
            rs = registers[instructionR[1]]
            rt = registers[instructionR[2]]
            address = instructionR[3]
        if(instructionI = 'lw'):
            opcode = funct[instructionI[0]]
            rs = registers[instructionR[1]]
            rd = registers[instructionR[2]]
            address = instructionI[3]
        if(instructionI = 'sw'):
            opcode = funct[instructionI[0]]
            rs = registers[instructionR[1]]
            rd = registers[instructionR[2]]
            address = instructionI[3]
