#script to get a binary from an assembly code

from sys import stdin

#variable to store the assembly code
assemblyCode = input()

#variable to store the options: add, sub, and, or, xor, nor, slt, lw e sw
opcode = {'add': '', 'sub': '', 'and': '', 'or': '', 'xor': '', 'nor': '', 'slt': '', 'lw': '', 'sw': ''}
rs
rt
rd
shamt
funct
address

for line in stdin:
    if line == '': #If an empty string is read then stop the loop
        break
    #Process to make the binary
    for line in options:
        #Return option
        print(option[line])
