# Определение состояний автомата Мура
states = {
    'q0': {
        'transitions': {'V': 'q1', 'S': 'q2', 'K': 'q3', 'Y': 'q4'},
        'output': None
    },
    'q1': {  # V
        'transitions': {'E': 'q5'},
        'output': 'T'
    },
    'q2': {  # S
        'transitions': {'O': 'q6'},
        'output': 'S'
    },
    'q3': {  # K
        'transitions': {'O': 'q7'},
        'output': 'P'
    },
    'q4': {  # Y
        'transitions': {'A': 'q8'},
        'output': 'S'
    },
    'q5': {  # VE
        'transitions': {'T': 'q9'},
        'output': 'E'
    },
    'q6': {  # SO
        'transitions': {'P': 'q10'},
        'output': 'A'
    },
    'q7': {  # KO
        'transitions': {'R': 'q11'},
        'output': 'L'
    },
    'q8': {  # YA
        'transitions': {'S': 'q12'},
        'output': 'O'
    },
    'q9': {  # VET
        'transitions': {'E': 'q13'},
        'output': 'P'
    },
    'q10': {  # SOP
        'transitions': {'L': 'q14'},
        'output': 'L'
    },
    'q11': {  # KOR
        'transitions': {'E': 'q15'},
        'output': 'U'
    },
    'q12': {  # YAS
        'transitions': {'L': 'q16'},
        'output': 'N'
    },
    'q13': {  # VETE
        'transitions': {'R': 'q17'},
        'output': 'L'
    },
    'q14': {  # SOPL
        'transitions': {'O': 'q18'},
        'output': 'K'
    },
    'q15': {  # KORE
        'transitions': {'N': 'q19'},
        'output': 'T'
    },
    'q16': {  # YASL
        'transitions': {'I': 'q20'},
        'output': 'I'
    },
    'q17': {  # VETER (конец)
        'transitions': {},
        'output': 'O'
    },
    'q18': {  # SOPLO (конец)
        'transitions': {},
        'output': 'I'
    },
    'q19': {  # KOREN (конец)
        'transitions': {},
        'output': 'O'
    },
    'q20': {  # YASLI (конец)
        'transitions': {},
        'output': 'K'
    },
}

def moore_machine(input_word):
    current_state = 'q0'
    output = []
    for char in input_word:
        if char not in states[current_state]['transitions']:
            return None  # Нет перехода для символа
        current_state = states[current_state]['transitions'][char]
        state_output = states[current_state]['output']
        if state_output is not None:
            output.append(state_output)
    return ''.join(output)

# Тестирование
test_cases = {
    'VETER': 'TEPLO',
    'SOPLO': 'SALKI',
    'KOREN': 'PLUTO',
    'YASLI': 'SONIK'
}

for input_word, expected_output in test_cases.items():
    result = moore_machine(input_word)
    print(f'Input: {input_word}, Output: {result}, Expected: {expected_output}, '
          f'{"OK" if result == expected_output else "Error"}')
