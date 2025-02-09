#Что делает этот код:
#    Класс Player:
#        Хранит информацию об игроке: имя, является ли он человеком, население, достижения и города.
#        Методы для проверки и установки достижений.
#    Класс City:
#        Хранит информацию о городе: имя, владелец, здания и юниты.
#    Класс Game:
#        Управляет игрой: хранит игроков, отслеживает ходы и проверяет достижения.
#    Логика игры:
#        В каждом ходу проверяются достижения, связанные с населением и постройками в городах.
#        Если достижение выполнено, выводится сообщение в консоль.
#    Пример использования:
#        Создаются два игрока, два города, добавляются здания и юниты.
#        Симулируется несколько ходов игры.
class Player:
    def __init__(self, name, is_human=True):
        self.name = name
        self.is_human = is_human
        self.population = 0
        self.feats = set()
        self.cities = []

    def is_feat_accomplished(self, feat):
        return feat in self.feats

    def set_feat_accomplished(self, feat, accomplished=True):
        if accomplished:
            self.feats.add(feat)
        else:
            self.feats.discard(feat)

    def add_city(self, city):
        self.cities.append(city)

    def get_real_population(self):
        return self.population


class City:
    def __init__(self, name, owner):
        self.name = name
        self.owner = owner
        self.buildings = []
        self.units = []

    def add_building(self, building):
        self.buildings.append(building)

    def add_unit(self, unit):
        self.units.append(unit)


class Game:
    def __init__(self):
        self.players = []
        self.turn = 0

    def add_player(self, player):
        self.players.append(player)

    def next_turn(self):
        self.turn += 1
        print(f"\n--- Turn {self.turn} ---")
        for player in self.players:
            self.check_population_feats(player)
            for city in player.cities:
                self.check_city_feats(city)

    def check_population_feats(self, player):
        population = player.get_real_population()
        if population >= 1000000 and not player.is_feat_accomplished("1 Million Population"):
            player.set_feat_accomplished("1 Million Population")
            print(f"{player.name} has reached 1 million population!")

    def check_city_feats(self, city):
        if len(city.units) > 0 and not city.owner.is_feat_accomplished("First Unit"):
            city.owner.set_feat_accomplished("First Unit")
            print(f"{city.owner.name} has built their first unit in {city.name}!")

        if len(city.buildings) > 0 and not city.owner.is_feat_accomplished("First Building"):
            city.owner.set_feat_accomplished("First Building")
            print(f"{city.owner.name} has built their first building in {city.name}!")


# Пример использования
if __name__ == "__main__":
    # Создаем игру
    game = Game()

    # Создаем игроков
    player1 = Player("Alice", is_human=True)
    player2 = Player("Bob", is_human=False)

    # Добавляем игроков в игру
    game.add_player(player1)
    game.add_player(player2)

    # Создаем города
    city1 = City("Metropolis", player1)
    city2 = City("Smalltown", player2)

    # Добавляем города игрокам
    player1.add_city(city1)
    player2.add_city(city2)

    # Игроки строят здания и юниты
    city1.add_building("Granary")
    city1.add_unit("Warrior")
    city2.add_building("Monument")

    # Устанавливаем население
    player1.population = 1200000
    player2.population = 500000

    # Симулируем несколько ходов
    for _ in range(3):
        game.next_turn()
