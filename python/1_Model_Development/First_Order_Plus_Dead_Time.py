import numpy as np
import matplotlib.pyplot as plt
import tclab
import time

n = 120  # Number of second time points (2 min)
tm = np.zeros(n) # Time values

# data
lab = tclab.TCLab()
T1 = [lab.T1]
Q1 = np.zeros(n)
Q1[30:] = 70.0

# Create Figure
plt.figure()
plt.ion()
plt.show()

# Main Loop
start_time = time.time()
prev_time = start_time
try:
    for i in range(1, n):
        
        # Sleep time
        sleep_max = 1.0
        sleep = sleep_max - (time.time() - prev_time)
        if sleep>=0.01:
            time.sleep(sleep)
        else:
            time.sleep(0.01)

        # Record time and change in time
        t = time.time()
        dt = t - prev_time
        prev_time = t
        tm[i] = t - start_time

        lab.Q1(Q1[i])
        time.sleep(1)
        print(lab.T1)
        T1.append(lab.T1)
        
        plt.clf()
        ax = plt.subplot(2,1,1)
        ax.grid()
        plt.plot(tm[0:i],T1[0:i],'r-',label=r'$T_1$')
        plt.ylabel(r'Temp ($^oC$)')
        plt.legend(loc='best')
        ax = plt.subplot(2,1,2)
        ax.grid()
        plt.plot(tm[0:i],Q1[0:i],'b-',label=r'$Q_1$')
        plt.ylabel(r'Heater (%)')
        plt.xlabel('Time (sec)')
        plt.legend(loc='best')
        plt.draw()
        plt.pause(0.05)

    lab.close()

except:
    # Disconnect from Arduino
    lab.Q1(0)
    print('Shutting down')
    lab.close()
    raise
