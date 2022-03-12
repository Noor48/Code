import matplotlib.pyplot as plt
x1 = [0, 0.02, 0.04, 0.08, 0.12, 0.16, 0.2]
y1 = [0.0005, 0.052, 0.0905, 0.1675, 0.2485, 0.3225, 0.4035]

fig,ax=plt.subplots(figsize=plt.rcParams["figure.figsize"][::-1])
fig.subplots_adjust(left=0.1, right=0.875, top=0.9,bottom=0.125)

ax.scatter(y1, x1)

ax.set_ylabel("x", rotation=90)
ax.yaxis.tick_right()
ax.yaxis.set_label_position("right")
ax.set_xlabel("y", rotation=180)
ax.invert_xaxis()

plt.setp(ax.get_xticklabels(), rotation=90, va="top", ha="center")
plt.setp(ax.get_yticklabels(), rotation=90, va="center", ha="left")

ax.text(-0.05,0.5,"y-x scatter", ha="center", va="center",
        transform=ax.transAxes, rotation=90)


plt.show()