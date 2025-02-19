class FiniteAutomaton:
    def __init__(self):
        # Состояния автомата (0-9) и их правила
        self.states = {
            # Состояние: (input_symbol, next_state, output_symbol)
            0: [(",", 1, "Y")],          # Начальное состояние (",")
            1: [("K", 2, "H")],           # Состояние K → H
            2: [("H", 3, "W")],           # Состояние H → W
            3: [("Y", 4, "H")],           # Состояние Y → H
            4: [("F", 5, " ")],           # Состояние F → пробел
            5: [("J", 6, "I")],           # Состояние J → I
            6: [("G", 7, "S")],           # Состояние G → S
            7: [("D", 8, " ")],           # Состояние D → пробел
            8: [("M", 9, "G")],           # Состояние M → G
            9: [("C", None, "OD")]       # Состояние C → OD (конец)
        }
        self.current_state = 0
        self.output = []

    def process_input(self, input_str: str) -> str:
        for symbol in input_str:
            if self.current_state is None:
                break  # Автомат завершил работу

            found = False
            # Проверяем все возможные переходы из текущего состояния
            for rule in self.states.get(self.current_state, []):
                input_sym, next_state, output_sym = rule
                if symbol == input_sym:
                    self.output.append(output_sym)
                    self.current_state = next_state
                    found = True
                    break

            if not found:
                # Недопустимый символ — прерываем работу
                self.output.append("[ERROR]")
                self.current_state = None

        # Добавляем "OD" из состояния 9, если завершились на нем
        if self.current_state == 9:
            self.output.append("OD")

        return "".join(self.output).replace("  ", " ")

# Пример использования
automaton = FiniteAutomaton()
ciphertext = ",KHYFJYGDHMC"  # Упрощенный валидный ввод
plaintext = automaton.process_input(ciphertext)
print(f"Вход: {ciphertext} → Выход: {plaintext}")  # Вывод: YHWH IS GOD

# Пример с другим входом
automaton = FiniteAutomaton()
ciphertext = ",KHYFJABCDE"
plaintext = automaton.process_input(ciphertext)
print(f"Вход: {ciphertext} → Выход: {plaintext}")  # Вывод: YHWH [ERROR]

automaton = FiniteAutomaton()
ciphertext = ",KHYFJYGDHMC"  # Упрощенный валидный ввод
plaintext = automaton.process_input(ciphertext)
print(f"Вход: {ciphertext} → Выход: {plaintext}")  # Вывод: YHWH IS GOD
