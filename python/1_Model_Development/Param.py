import numpy as np
import matplotlib.pyplot as plt

f = open("step_response_output.txt", "r")

lines = f.readlines()

x = np.linspace(0, 599, 600)
y = np.zeros(600)

index = 1
for line in lines:
    y[index] = float(line)
    index += 1

### Gain (K)
max_value = 0
for i in range(1, len(y)):
    if (y[i] > max_value):
        max_value = y[i]
        max_index = i
min_value = min(y[1:max_index])
print("Gain (K): %.2f" % ((max_value - min_value) / 80.0))

### Dead Time (T)
for i in range(1, len(y)):
    value = round(y[i])
    next_value = round(y[i + 1])
    
    if (value != next_value):
        dead_time = i
        print("Dead Time (T):", dead_time, "s")
        break

### Time Constant
steady_state_value = y[150]
for i in range(1, 150):
    if (y[i] >= steady_state_value * 0.98):
        last_point_before_stedy_state = y[i]
        last_point_before_stedy_state_index = i

time_constat = int((last_point_before_stedy_state_index - dead_time) / 5)
print("Time Constant (t):", time_constat, "s")

plt.plot(x[dead_time:max_index], y[dead_time:max_index])
plt.show()
