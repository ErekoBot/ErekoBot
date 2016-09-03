import matplotlib.pyplot as plt

plt.plot([10, 30, 62.5, 125, 250, 500, 750, 1000],[99.1, 100, 99.5, 99.3, 99.4, 99.8, 100, 100])
plt.ylabel('porcentagem de entrega')
plt.xlabel('tempo em milissegundos')
plt.axis([0, 1000, 95, 105])
plt.show()