import matplotlib.pyplot as plt
import csv
t=[]
x=[]
y=[]
u=[]
import os
with open('sim1.csv') as csv_file:
    csv_reader = csv.reader(csv_file,delimiter=',')
    line_count = 0
    for row in csv_reader:
        if line_count == 0:
           line_count += 1
        else:
            t.append(float(row[0]))
            x.append(float(row[1]))
            y.append(float(row[2]))
            u.append(float(row[3]))
            line_count += 1
            
fig, axs = plt.subplots(2,2) 
axs[0, 0].plot(t,x)
axs[0, 1].plot(t,y)  
axs[1, 0].plot(x,y)
axs[1, 1].plot(t,u)         
# naming the x axis 
axs[0, 0].set(xlabel='x - axis')
# naming the y axis 
axs[0, 0].set(ylabel='x - axis')
  
# giving a title to my graph 
axs[0, 0].set_title('First Graph')
  
# function to show the plot 
plt.show() 










