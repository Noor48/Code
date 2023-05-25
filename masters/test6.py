import numpy as np
import matplotlib.pyplot as plt

# Load data for the lines
data1 = np.loadtxt('BRET.DAT')

# Extract x and y values for each line
x1, y1 = data1[:, 0], data1[:, 1]
x2, y2 = data1[:, 0], data1[:, 2]

# Plot the lines
plt.plot(x1, y1, label='V11')
plt.plot(x2, y2, label='V22',linestyle='dotted',color="green")

# Add labels to the lines
labels = ['V11', 'V22']
positions = [(x1[20], y1[10]), (x2[3], y2[3])]  # Positions of the labels on each line

for label, position in zip(labels, positions):
    plt.text(*position, label, ha='left', va='center')

# Set labels for x-axis and y-axis
plt.xlabel('(R)(au)')
plt.ylabel('V(R)(au)')

# Display the plot with a legend
plt.legend()
plt.show()
plt.plot(x1, y1, label='V11')
plt.plot(x2, y2, label='V22',linestyle='dotted',color="green")

# Add labels to the lines
labels = ['V11', 'V22']
positions = [(x1[20], y1[10]), (x2[3], y2[3])]  # Positions of the labels on each line

for label, position in zip(labels, positions):
    plt.text(*position, label, ha='left', va='center')

# Set labels for x-axis and y-axis
plt.xlabel('(R)(au)')
plt.ylabel('V(R)(au)')

# Display the plot with a legend
plt.legend()
plt.savefig("plot.png")
