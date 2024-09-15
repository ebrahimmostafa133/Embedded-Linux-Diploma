#---------  lec 1 ----------
# author: Ebrahim Mostafa

#------------------------------------------------ Task 1 #------------------------------------------------

# Write a Python program to count the number 4 in a given list.
x = [1, 2, 3, 4, 5, 6, 7, 8, 4, 4]
count_of_fours = x.count(4)  # This counts the number of 4s in the list
print(f"Number of 4s in the list: {count_of_fours}")

#-----------------------------------------------------------------------------

#Write a Python program to test whether a passed letter is a vowel or not.
vowel_letter =['a','i','o','u','e']
x= input("enter any letter: ").lower();
if x in vowel_letter:
    print("this is a vowel letter")
else:
    print("this is not vowel letter")

#-----------------------------------------------------------------------------

# Write a python program to access environment variables. -->PATH  -->os

import os
path = os.getenv('PATH')
print("The PATH environment variable is:")
print(path)

#-----------------------------------------------------------------------------

#------------------------------------------------ Task 2 #------------------------------------------------

#Write a Python program which accepts the radius of a circle from the user and compute the area.
import math
radius = float(input("Enter the radius to determine the Area of the circle: "))

# Calculate the area using the formula π * r^2
area = math.pi * math.pow(radius, 2)
print("The area of the circle is", area, "cm²")

#------------------------------------------------ Task 3 #------------------------------------------------
import calendar

# Input the year and month
year = int(input("Enter the year: "))
month = int(input("Enter the month (1-12): "))

# Print the calendar for the given month and year
print(calendar.month(year, month))
#-----------------------------------------------------------------------------