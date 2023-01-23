import matplotlib.pyplot as plt
import numpy as np

positions = np.loadtxt("Data/HW1_curve_pos.csv", delimiter=',', dtype=float)
frame_num = np.linspace(0,positions.shape[0]-1, 300, dtype=int)

n=0
for i in frame_num:
    fig, ax1 = plt.subplots()
    fig.set_size_inches(8,8)
    

    ax1.plot(positions[0,:], positions[i,:])
    ax1.set_ylim(-5, 5)

    plt.savefig('Frames/frame_'+str(n+1).rjust(6, '0'))
    n += 1
    plt.close()

# Make a movie!
# ffmpeg -framerate 30 -i frame_%06d.png movie.mp4
