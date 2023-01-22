import matplotlib.pyplot as plt
import numpy as np

positions = np.loadtxt("Data/HW1_curve_pos.csv", delimiter=',', dtype=float)
frame_num = np.linspace(0,positions.shape[0]-1, 300, dtype=int)

for i in frame_num:
    fig, ax1 = plt.subplots()
    fig.set_size_inches(8,8)
    
    ax1.plot(positions[0,:], positions[i,:])

    plt.savefig('Frames/frame_'+str(i+1).rjust(6, '0'))
    plt.close()
