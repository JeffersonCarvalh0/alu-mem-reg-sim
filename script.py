#script to get a binary from an assembly code

from sys import stdin

#variables to store the binaries
funct = {'add': '100000', # decimal 32, R instruction
         'sub': '100010', # decimal 34, R instruction
         'and': '100100', # decimal 36, R instruction
         'or': '100101', # decimal 37, R instruction
         'xor': '100110', # decimal 38, R instruction
         'nor': '100111', # decimal 39, R instruction
         'slt': '101010', # decimal 42, R instruction
         'addi': '001000', # decimal 8, I instruction
         'lw': '100011', # decimal 35, I instruction
         'sw': '101011' # decimal 43, I instruction
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

# line = input("Put your line code here: ") # Coment this line if you do not need any tests

# Uncoment this line after tests
for line in stdin:
    if line == '': #If an empty string is read then stop the loop
        break
    
# if(True):   # Coment this line if you do not need any tests
    #Process to take the binary
    opcode = line.split(' ')[0]
    if(opcode in ('add', 'addi', 'sub', 'and', 'or', 'slt')):
        instructionR = line.split(' ')
        if(instructionR[0] == 'add'):
            opcode = '000000'
            rs = registers[instructionR[1]]
            rt = registers[instructionR[2]]
            rd = registers[instructionR[3]]
            shamt = '00000'
            funct = funct[instructionR[0]]
            print("Seu binário eh: "+opcode+rs+rt+rd+shamt+funct)
        if(instructionR[0] == 'sub'):
            opcode = '000000'
            rs = registers[instructionR[1]]
            rt = registers[instructionR[2]]
            rd = registers[instructionR[3]]
            shamt = '00000'
            funct = funct[instructionR[0]]
            print("Seu binário eh: "+opcode+rs+rt+rd+shamt+funct)
        if(instructionR[0] == 'and'):
            opcode = '000000'
            rs = registers[instructionR[1]]
            rt = registers[instructionR[2]]
            rd = registers[instructionR[3]]
            shamt = '00000'
            funct = funct[instructionR[0]]
            print("Seu binário eh: "+opcode+rs+rt+rd+shamt+funct)
        if(instructionR[0] == 'or'):
            opcode = '000000'
            rs = registers[instructionR[1]]
            rt = registers[instructionR[2]]
            rd = registers[instructionR[3]]
            shamt = '00000'
            funct = funct[instructionR[0]]
            print("Seu binário eh: "+opcode+rs+rt+rd+shamt+funct)
        if(instructionR[0] == 'xor'):
            opcode = '000000'
            rs = registers[instructionR[1]]
            rt = registers[instructionR[2]]
            rd = registers[instructionR[3]]
            shamt = '00000'
            funct = funct[instructionR[0]]
            print("Seu binário eh: "+opcode+rs+rt+rd+shamt+funct)
        if(instructionR[0] == 'nor'):
            opcode = '000000'
            rs = registers[instructionR[1]]
            rt = registers[instructionR[2]]
            rd = registers[instructionR[3]]
            shamt = '0000'
            funct = funct[instructionR[0]]
            print("Seu binário eh: "+opcode+rs+rt+rd+shamt+funct)
        if(instructionR[0] == 'slt'):
            opcode = '000000'
            rs = registers[instructionR[1]]
            rt = registers[instructionR[2]]
            rd = registers[instructionR[3]]
            shamt = '00000'
            funct = funct[instructionR[0]]
            print("Seu binário eh: "+opcode+rs+rt+rd+shamt+funct)
    else:
        instructionI = line.split(' ')
        if(instructionI[0] == 'addi'):
            opcode = funct[instructionI[0]]
            rs = registers[instructionR[1]]
            rt = registers[instructionR[2]]
            address = instructionR[3]
            print("Seu binário eh: "+opcode+rs+rt+address)
        if(instructionI == 'lw'):
            opcode = funct[instructionI[0]]
            rs = registers[instructionR[1]]
            rd = registers[instructionR[2]]
            address = instructionI[3]
            print("Seu binário eh: "+opcode+rs+rt+address)
        if(instructionI == 'sw'):
            opcode = funct[instructionI[0]]
            rs = registers[instructionR[1]]
            rd = registers[instructionR[2]]
            address = instructionI[3]
            print("Seu binário eh: "+opcode+rs+rt+address)
