import numpy as np
import matplotlib.pyplot as plt


def main():
    xs = np.linspace(-1.5, 0.5, num=10000)
    ys = np.linspace(-1.0, 1.0, num=10000)
    xs, ys = np.meshgrid(xs, ys)
    zs = ys*0j

    bound = 100
    extent = zs.astype(dtype = int)

    for i in range(0, np.shape(zs)[0]):
        for j in range(0, np.shape(zs)[1]):
            for e in range(0, 100):
                zs[i, j] = zs[i, j]**2 + (xs[i, j] + ys[i, j]*1j)
                if abs(zs[i, j]) > bound:
                    extent[i, j] = e
                    break
    
#    for e in range(0, 100):
#        zs = zs*zs + (xs + ys*1j)

    intensities = np.abs(zs)

    fig, ax = plt.subplots()
    c = ax.pcolormesh(xs, ys, extent, cmap='RdBu')
    ax.set_title('Mandelbrot')
    ax.axis([xs.min(), xs.max(), ys.min(), ys.max()])
    fig.colorbar(c, ax=ax)
    plt.show()

    

if __name__ == "__main__":
    main()