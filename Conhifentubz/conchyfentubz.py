import random
from tkinter import *
from tkinter import messagebox

class Country:
    ECONOMY_BASE = 10
    ECONOMY_FACTOR = 5
    CELL_BONUS = 5

    def __init__(self, name, color, capital, start_cells):
        self.name = name
        self.color = color
        self.gold = 100
        self.economy_level = 0
        self.cells = start_cells.copy()
        self.capital = capital
        self.soldiers = {cell: 0 for cell in start_cells}

    def get_income(self):
        return self.ECONOMY_BASE + self.economy_level * self.ECONOMY_FACTOR + len(self.cells) * self.CELL_BONUS

    def distribute_gold(self, soldiers_gold, economy_gold):
        soldiers_gold = min(soldiers_gold, self.gold)
        economy_gold = min(economy_gold, self.gold - soldiers_gold)
        self.gold -= (soldiers_gold + economy_gold)
        self.economy_level += economy_gold
        total_soldiers = sum(self.soldiers.values()) + soldiers_gold
        self.redistribute_soldiers(total_soldiers)

    def redistribute_soldiers(self, total_soldiers):
        num_cells = len(self.cells)
        if num_cells == 0:
            self.soldiers = {}
            return
        base = total_soldiers // num_cells
        remainder = total_soldiers % num_cells
        new_soldiers = {cell: base for cell in self.cells}
        new_soldiers[self.capital] += remainder
        self.soldiers = new_soldiers

    def get_adjacent_enemy_cells(self, all_countries):
        enemies = set()
        for cell in self.cells:
            row, col = cell
            for dr, dc in [(-1,0), (1,0), (0,-1), (0,1)]:
                nr, nc = row + dr, col + dc
                if 0 <= nr <4 and 0 <= nc <4:
                    neighbor = (nr, nc)
                    owner = None
                    for c in all_countries:
                        if neighbor in c.cells and c != self:
                            owner = c
                            break
                    if owner:
                        enemies.add((neighbor, owner))
        return list(enemies)

    def plan_attack(self, all_countries):
        targets = self.get_adjacent_enemy_cells(all_countries)
        if not targets:
            return []
        num_attacks = random.randint(1, min(3, len(targets)))
        selected = random.sample(targets, num_attacks)
        total_soldiers = sum(self.soldiers.values())
        attack_force = total_soldiers * 0.75
        per_attack = attack_force // num_attacks
        remainder = attack_force % num_attacks
        attacks = []
        for i in range(num_attacks):
            target, owner = selected[i]
            force = per_attack + (remainder if i == 0 else 0)
            attacks.append((target, owner, int(force)))
        return attacks

class Game:
    def __init__(self):
        self.countries = [
            Country("Оранжевая", "#FFA500", (0,0), [(0,0), (0,1), (1,0), (1,1)]),
            Country("Синяя", "#0000FF", (0,3), [(0,2), (0,3), (1,2), (1,3)]),
            Country("Красная", "#FF0000", (3,0), [(2,0), (2,1), (3,0), (3,1)]),
            Country("Зеленая", "#008000", (3,3), [(2,2), (2,3), (3,2), (3,3)]),
        ]
        self.player = self.countries[0]
        self.turn = 0
        self.max_turns = 100

    def next_turn(self):
        for country in self.countries:
            country.gold += country.get_income()
        attacks = []
        for country in self.countries:
            if country is self.player:
                continue
            gold = country.gold
            soldiers_gold = random.randint(0, gold)
            economy_gold = gold - soldiers_gold
            country.distribute_gold(soldiers_gold, economy_gold)
            attacks += country.plan_attack(self.countries)
        for country in self.countries:
            if country is not self.player and country.cells:
                attacks += country.plan_attack(self.countries)
        for target, defender, force in attacks:
            attacker = None
            for c in self.countries:
                if any(cell == target for cell in c.cells):
                    continue
                for cell in c.cells:
                    if (abs(cell[0] - target[0]) + abs(cell[1] - target[1])) == 1:
                        attacker = c
                        break
                if attacker:
                    break
            if not attacker:
                continue
            defender_soldiers = defender.soldiers.get(target, 0)
            if force >= 2 * defender_soldiers:
                attacker_loss = defender_soldiers
                defender_loss = defender_soldiers
                defender.cells.remove(target)
                attacker.cells.append(target)
                attacker_total = sum(attacker.soldiers.values()) - attacker_loss
                defender_total = sum(defender.soldiers.values()) - defender_loss
                attacker.redistribute_soldiers(attacker_total)
                defender.redistribute_soldiers(defender_total)
                attacker.economy_level += 1
                defender.economy_level = max(0, defender.economy_level - 1)
            else:
                attacker_loss = int(force * 0.3)
                defender_loss = int(defender_soldiers * 0.3)
                attacker_total = sum(attacker.soldiers.values()) - attacker_loss
                defender_total = sum(defender.soldiers.values()) - defender_loss
                attacker.redistribute_soldiers(attacker_total)
                defender.redistribute_soldiers(defender_total)
                if defender_soldiers - defender_loss <= 0:
                    defender.cells.remove(target)
                    attacker.cells.append(target)
                    attacker.economy_level += 1
                    defender.economy_level = max(0, defender.economy_level - 1)
        self.turn += 1
        if self.turn >= self.max_turns:
            winner = max(self.countries, key=lambda c: sum(c.soldiers.values()))
            return winner
        for c in self.countries:
            if len(c.cells) == 16:
                return c
        return None

class GameGUI:
    def __init__(self, master):
        self.master = master
        self.game = Game()
        self.setup_ui()

    def setup_ui(self):
        self.grid_frame = Frame(self.master)
        self.grid_frame.grid(row=0, column=0)
        self.cells = []
        for row in range(4):
            row_cells = []
            for col in range(4):
                cell = Label(self.grid_frame, text="0", width=10, height=5, relief="ridge")
                cell.grid(row=row, column=col)
                row_cells.append(cell)
            self.cells.append(row_cells)
        control_frame = Frame(self.master)
        control_frame.grid(row=0, column=1)
        Label(control_frame, text="Золото на солдат").pack()
        self.soldiers_entry = Entry(control_frame)
        self.soldiers_entry.pack()
        Label(control_frame, text="Золото на экономику").pack()
        self.economy_entry = Entry(control_frame)
        self.economy_entry.pack()
        self.end_turn_btn = Button(control_frame, text="Окончить ход", command=self.end_turn)
        self.end_turn_btn.pack()
        info_frame = Frame(self.master)
        info_frame.grid(row=1, column=0, columnspan=2)
        self.info_text = Text(info_frame, width=80, height=10)
        self.info_text.pack()
        self.update_display()

    def update_display(self):
        for row in range(4):
            for col in range(4):
                cell = (row, col)
                for country in self.game.countries:
                    if cell in country.cells:
                        soldiers = country.soldiers.get(cell, 0)
                        self.cells[row][col].config(
                            text=f"{country.name}\n{soldiers}",
                            bg=country.color,
                            fg="white" if country.color in ["#0000FF", "#FF0000", "#008000"] else "black"
                        )
                        break
        self.info_text.delete(1.0, END)
        for country in self.game.countries:
            text = f"{country.name}: Золото={country.gold}, Экономика={country.economy_level}, Солдаты={sum(country.soldiers.values())}\n"
            self.info_text.insert(END, text)
        self.info_text.insert(END, f"Ход: {self.game.turn}/{self.game.max_turns}")

    def end_turn(self):
        try:
            soldiers = int(self.soldiers_entry.get())
            economy = int(self.economy_entry.get())
        except:
            soldiers = 0
            economy = self.game.player.gold
        soldiers = max(0, min(self.game.player.gold, soldiers))
        economy = max(0, min(self.game.player.gold - soldiers, economy))
        self.game.player.distribute_gold(soldiers, economy)
        winner = self.game.next_turn()
        if winner:
            messagebox.showinfo("Победа!", f"Победила {winner.name}!")
            self.master.quit()
        else:
            self.update_display()

if __name__ == "__main__":
    root = Tk()
    root.title("Конхифентубз")
    gui = GameGUI(root)
    root.mainloop()
