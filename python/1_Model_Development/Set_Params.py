import tclab
import numpy as np
import time
import matplotlib.pyplot as plt

# Connect to Arduino
a = tclab.TCLab()

# Get Version
print(a.version)

# Turn LED on
print('LED On')
a.LED(100)

# Run time in minutes
run_time = 10.0

# Number of cycles
loops = int(60.0 * run_time)
tm = np.zeros(loops)

# Temperature (K)
Tsp1 = np.ones(loops) * 23.0 # set point (degC)
T1 = np.ones(loops) * a.T1 # measured T (degC)

# step test (0 - 100%)
Q1 = np.ones(loops) * 0.0

# pulse tests
Q1[10:]  = 80.0
Q1[180:] = 0.0
Q1[360:] = 0.0
Q1[500:] = 0.0

# Create output log
f = open("step_response_output.txt", "w+")

print('Running Main Loop. Ctrl-C to end.')
print('  Time     Q1      T1     ')
print('{:6.1f} {:6.2f} {:6.2f}'.format(tm[0], Q1[0], T1[0]))

# Create plot
plt.figure()
plt.ion()
plt.show()

# Main Loop
start_time = time.time()
prev_time = start_time
try:
    for i in range(1,loops):
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
                    
        # Read temperatures in Kelvin 
        T1[i] = a.T1

        # Write temperature on output
        f.write("%.2f\n" % T1[i])

        ###############################
        ### CONTROLLER or ESTIMATOR ###
        ###############################

        # Write output (0-100)
        a.Q1(Q1[i])

        # Print line of data
        print('{:6.1f} {:6.2f} {:6.2f}'.format(tm[i], \
                                               Q1[i], \
                                               T1[i]))

        # Plot
        plt.clf()
        ax=plt.subplot(2,1,1)
        ax.grid()
        plt.plot(tm[0:i],T1[0:i],'ro',MarkerSize=3,label=r'$T_1$')
        plt.ylabel('Temperature (degC)')
        plt.legend(loc='best')
        ax=plt.subplot(2,1,2)
        ax.grid()
        plt.plot(tm[0:i],Q1[0:i],'r-',LineWidth=3,label=r'$Q_1$')
        plt.ylabel('Heaters')
        plt.xlabel('Time (sec)')
        plt.legend(loc='best')
        plt.draw()
        plt.pause(0.05)

    f.close()
        
# Allow user to end loop with Ctrl-C           
except KeyboardInterrupt:
    # Disconnect from Arduino
    a.Q1(0)
    print('Shutting down')
    a.close()
    
# Make sure serial connection still closes when there's an error
except:           
    # Disconnect from Arduino
    a.Q1(0)
    print('Error: Shutting down')
    a.close()
    raise
