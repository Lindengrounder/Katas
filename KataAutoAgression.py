import json
from datetime import datetime
import sys
import os
import re

class DialogStep:
    def __init__(self, step_id, user_prompt, ai_response, triggers=None, context=None):
        self.step_id = step_id
        self.user_prompt = user_prompt
        self.ai_response = ai_response
        self.triggers = triggers or {}
        self.context = context or {}
        self.timestamp = None

    def execute(self):
        self.timestamp = datetime.now()
        try:
            user_input = self._get_validated_input()
            self._log_interaction(user_input)
            
            # Используем текущий шаг по умолчанию для любых вводов
            next_step = self.triggers.get(user_input.lower(), self.step_id)
            
            # Обновление контекста для следующих шагов
            if 'aggression_level' in self.context:
                self.context['aggression_level'] += 1 if EmotionalAnalyzer.analyze(user_input) else -1
            else:
                self.context['aggression_level'] = 1 if EmotionalAnalyzer.analyze(user_input) else -1
                
            return next_step
        except KeyboardInterrupt:
            print("\nДиалог прерван пользователем")
            sys.exit(0)

    def _get_validated_input(self):
        while True:
            user_input = input(f"\n[{self.step_id}] {self.user_prompt} ").strip()
            if user_input and len(user_input) <= 256:
                return user_input
            print("Ошибка: Ввод должен быть не пустым и не длиннее 256 символов")

    def _log_interaction(self, user_input):
        log_entry = {
            "step": self.step_id,
            "time": self.timestamp.isoformat(),
            "user_input": user_input,
            "ai_response": self.ai_response,
            "context": self.context
        }
        with open("dialog_log.json", "a") as f:
            f.write(json.dumps(log_entry, ensure_ascii=False) + "\n")

class DialogFlow:
    def __init__(self):
        self.steps = self._initialize_steps()
        self.current_step = 0
        self.schema = []
        self.context = {}

    def _initialize_steps(self):
        return [
            DialogStep(
                0,
                "Пользователь начинает диалог:",
                "Нейтральная реакция, предложение конструктивного диалога.",
                {"ростелеком": 1, "агрессия": 2},
                {"aggression_level": 0}
            ),
            DialogStep(
                1,
                "Обвинение ИИ в ответах «как специалист Ростелекома»:",
                "Уточнение своей роли, повторное предложение помощи.",
                {"аутоагрессия": 2}
            ),
            DialogStep(
                2,
                "Утверждение:",
                "Объяснение термина, готовность помочь с ресурсами.",
                {"ненавижу": 3},
                {"support_needed": True}
            ),
            DialogStep(
                3,
                "Признание:",
                "Поддержка, рекомендация специалиста, помощь в поиске ресурсов.",
                {"схема": 4, "повторить": 3}
            ),
            DialogStep(
                4,
                "Просьба составить блок-схему:",
                "Создание схемы:"
            )
        ]

    def run(self):
        print("=== Начало диалога ===")
        while self.current_step < len(self.steps):
            step = self.steps[self.current_step]
            step.context = self.context  # Передача контекста
            self.schema.append(f"{step.step_id}. {step.user_prompt}")
            next_step = step.execute()
            
            # Динамическое изменение ответа на основе контекста
            if step.step_id == 3 and self.context.get('aggression_level', 0) > 2:
                step.ai_response += " Обратите внимание на ваш эмоциональный тон."
            
            print(f"\nОтвет ИИ: {step.ai_response}")
            self.current_step = next_step if next_step is not None else self.current_step + 1
        self._generate_schema()
        print("\n=== Диалог завершен ===")

    def _generate_schema(self):
        schema = ["@startuml\n"]
        for i in range(len(self.schema)):
            current_step = self.schema[i]
            next_step = self.schema[i+1] if i+1 < len(self.schema) else "Конец"
            schema.append(f"{current_step} --> {next_step}\n")
        schema.append("@enduml")
        
        with open("dialog_schema.puml", "w") as f:
            f.write("".join(schema))
        
        # Попытка генерации SVG (требует PlantUML CLI)
        os.system("plantuml dialog_schema.puml")

class EmotionalAnalyzer:
    @staticmethod
    def analyze(text):
        negative_words = ["ненавижу", "ненависть", "мерзкий", "вонючая", "агрессия"]
        intensity = sum(word in text.lower() for word in negative_words)
        return intensity

def main():
    try:
        flow = DialogFlow()
        flow.run()
        
        with open("dialog_log.json") as f:
            logs = [json.loads(line) for line in f]
            max_aggression = max([log['context'].get('aggression_level', 0) for log in logs])
            
            if max_aggression > 3:
                print("\n⚠️ Внимание: Высокий уровень эмоциональной агрессии в логах")
                print("Рекомендуется проконсультироваться с психологом")
                
        # Поиск и удаление временных файлов
        if os.path.exists("dialog_schema.puml"):
            os.remove("dialog_schema.puml")
        if os.path.exists("dialog_schema.svg"):
            print("\nБлок-схема сохранена в dialog_schema.svg")
        else:
            print("\nОшибка генерации SVG. Установите PlantUML CLI для визуализации")
            
    except Exception as e:
        print(f"Ошибка: {str(e)}")
        sys.exit(1)

if __name__ == "__main__":
    main()
