#---------  lec 3 ----------
# author: Ebrahim Mostafa

#------------------------------------------------ Task 1 ------------------------------------------------
#Using PyAutoGUI 1. Using “Pyautogui” to open Emails and change Emails from unread to read
import pyautogui
import time
import webbrowser

webbrowser.open('https://mail.google.com/mail/u/0/#all') # Opens Gmail;
time.sleep(5) 

pyautogui.moveTo(1550, 350, duration=1)  # Move to the Select all button
pyautogui.click()  # Click on the Inbox tab
time.sleep(3)

pyautogui.moveTo(1250, 350, duration=1)  # Move to the Read all button
pyautogui.click()  # Click on the Inbox tab
time.sleep(3)

pyautogui.moveTo(1550, 350, duration=1)  # Move to the Select all button
pyautogui.click()  # Click on the Inbox tab
time.sleep(3)

pyautogui.hotkey('alt', 'tab',duration=1)  # Presses Alt+Tab to switch windows
time.sleep(1)  # Optional: Wait for 1 second after switching windows
print("All messages have been read. ")


#------------------------------------------------ Task 2 ------------------------------------------------
#Write a Python program to get the command-line arguments

import sys

# Print the name of the script
print(f"Script name: {sys.argv[0]}")

# Print the number of command-line arguments
print(f"Number of arguments: {len(sys.argv)}")

# Print the arguments passed
print("Arguments passed:")

# Loop through the arguments (excluding the script name)
for i in range(1, len(sys.argv)):
    print(f"Argument {i}: {sys.argv[i]}")


