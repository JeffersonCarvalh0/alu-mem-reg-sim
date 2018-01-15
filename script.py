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

line = input("Put your line code here: ") # Coment this line if you do not need any tests

# Uncoment this line after tests
#for line in stdin:
#    if line == '': #If an empty string is read then stop the loop
#        break
    
if(True):   # Coment this line if you do not need any tests
    #Process to take the binary
    opcode = line.split(' ')[0]
    # if(True):   # Coment this line if you do not need any tests
    #Process to take the binary
    instruction = line.split()
    opcode = instruction[0]
    if(opcode in ('add', 'sub', 'and', 'or', 'slt')):
        opcode = '000000'
        rd = registers[instruction[1]]
        rs = registers[instruction[2]]
        rt = registers[instruction[3]]
        shamt = '00000'
        funct = funct[instruction[0]]
        print("Seu binário eh: "+opcode+rs+rt+rd+shamt+funct)
    else:
        opcode = funct[instruction[0]]
        rt = registers[instruction[1]]
        rs = registers[instruction[2]]
        address = (bin(int(instruction[3])).split('b'))[1].zfill(16)
        print("Seu binário eh: "+opcode+rs+rt+address)     
