# KataPassGen14.py
# 11/01/2025 - протестирована на онлайн компиляторе JDoodle.com

import random
from random import choice
from string import ascii_uppercase

def test():
    cs = random.randint(2,9)
    symbolsL = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    symbolsS = 'abcdefghijklmnopqrstuvwxyz'
    symbolsN = '1234567890'
    symbols = '-+=*?!%@_'
    rand1 = (''.join(choice(symbols) for i in range(cs)))
    rand2 = (''.join(choice(symbolsL) for i in range(cs)))
    rand3 = (''.join(choice(symbolsS) for i in range(cs)))
    rand4 = (''.join(choice(symbolsN) for i in range(cs)))
    print (rand1) 
    print (rand2)
    print (rand3)
    print (rand4)

test()
