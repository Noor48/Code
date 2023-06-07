import numpy as np
import matplotlib.pyplot as plt

def pair_correlation_function(x, y):
    """
    Compute the pair correlation function.
    """
    n = len(x)
    g = np.zeros(n)

    for i in range(n):
        dx = x - x[i]
        dy = y - y[i]
        distances = np.sqrt(dx**2 + dy**2)
        hist, _ = np.histogram(distances, bins=50, range=(0, np.max(distances)))
        g[:len(hist)] += hist

    g /= n

    return g

def fourier_transform_pair_correlation(x, y):
    """
    Compute the Fourier transform of the pair correlation function.
    """
    g = pair_correlation_function(x, y)
    g_fourier = np.fft.fft(g)

    return g_fourier

# Generate random points
np.random.seed(0)
n_points = 100
x = np.random.uniform(0, 10, n_points)
y = np.random.uniform(0, 10, n_points)

# Compute the Fourier transform of the pair correlation function
g_fourier = fourier_transform_pair_correlation(x, y)

# Plot the pair correlation function and its Fourier transform
fig, axs = plt.subplots(2, 1, figsize=(8, 6))

# Pair correlation function plot
g = pair_correlation_function(x, y)
axs[0].plot(g)
axs[0].set_xlabel('Distance')
axs[0].set_ylabel('Pair Correlation')
axs[0].set_title('Pair Correlation Function')

# Fourier transform plot
freqs = np.fft.fftfreq(len(g_fourier))
power_spectrum = np.abs(g_fourier)**2
axs[1].plot(freqs, power_spectrum)
axs[1].set_xlabel('Frequency')
axs[1].set_ylabel('Power Spectrum')
axs[1].set_title('Fourier Transform of Pair Correlation Function')

plt.tight_layout()
plt.show()
