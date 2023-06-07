import numpy as np
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors

x = np.linspace(0, 1, 500)
y = np.sin(4 * np.pi * x) * np.exp(-5 * x)

fig, ax = plt.subplots()

# Define a colormap for the zebra-like pattern
colors = ['white', 'black'] * 100
cmap = mcolors.LinearSegmentedColormap.from_list('CustomMap', colors, len(colors))

# Use 'fill_between' to fill the area under the curve
im = ax.fill_between(x, y, color='black')

# Apply the colormap
im.set_zorder(3)
ax.imshow(np.ones_like(y.reshape(-1,1))*np.linspace(0, 1, len(y)),
           extent=[x.min(),x.max(),y.min(),y.max()], aspect='auto',
           cmap=cmap, zorder=0)

plt.show()
