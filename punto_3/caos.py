import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt('caos.txt')

x = datos[0,:]
y = datos[1,:]

plt.figure()
plt.plot(x,y)
plt.title('q2 vs p2')
plt.xlabel('q2')
plt.ylabel('p2')
plt.show()
plt.savefig('caos.pdf')
