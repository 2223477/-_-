import matplotlib.pyplot as plt

# читаем все значения в одну строку
with open("main/output.txt") as f:
    line = f.readline()  # берём первую (и единственную) строку
    T = list(map(float, line.split()))

# создаём координаты x
N = len(T) - 1
a = 0.0
b = 6.0
x = [a + i*(b-a)/N for i in range(N+1)]

plt.plot(x, T, marker='o')
plt.xlabel("x")
plt.ylabel("T")
plt.title("Распределение температуры вдоль стержня")
plt.grid(True)
plt.show()

