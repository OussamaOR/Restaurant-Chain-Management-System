import matplotlib.pyplot as plt

# Sample data
x = [1, 2, 3, 4, 5]
y = [2, 3, 5, 7, 11]

# Plotting a simple line chart
plt.plot(x, y, label='Prime Numbers')

# Adding labels and title
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Prime Numbers Plot')

# Adding a legend
plt.legend()

# Display the plot
plt.show()
