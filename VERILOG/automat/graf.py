import networkx as nx
import matplotlib.pyplot as plt

# Последовательность переходов состояний
states = [",", "K", "H", "Y", "F", "J", "Y", "G", "D", "H", "Y", "M", "J", "G", "C", "F", "J", "H"]

# Создание направленного графа
G = nx.DiGraph()

# Добавление ребер в граф на основе переходов состояний
for i in range(len(states) - 1):
    G.add_edge(states[i], states[i + 1])

# Визуализация графа
plt.figure(figsize=(8, 6))
pos = nx.spring_layout(G)  # Позиционирование узлов графа
nx.draw(G, pos, with_labels=True, node_color='lightblue', edge_color='gray', node_size=2000, font_size=10, font_weight='bold', arrows=True)
plt.title("Граф переходов состояний")
plt.show()
