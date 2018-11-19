# -*- coding: utf-8 -*-
"""
Created on Mon Nov  5 13:54:28 2018

@author: psz
"""
import numpy as np

i = 0
bytes_read = open("addlarge.bin", "rb").read()
instructions_nr = int(len(bytes_read)/4)
instructions = np.empty(instructions_nr,dtype = int)
for b in bytes_read:
    
    instructions[int(i/4)] += b << (4-i%4)*8
    i += 1
    
if instructions[0] == 0x37:
    print("they are equal")
