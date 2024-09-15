#---------  lec 6 ----------
# author: Ebrahim Mostafa

#------------------------------------------------ Task 2 ------------------------------------------------
#Write a program that asks the user to type a word and return him its reverse
from tkinter import *

def Enter_Word():
    input_word = word.get()
    reversed_word = input_word[::-1]
    result_label.config(text=reversed_word)

root = Tk()
root.title("Reverse Word")

Label(root, text="Enter a word:").grid(row=0, column=0)

word = Entry(root)
word.grid(row=0, column=1)

result_label = Label(root, text="")
result_label.grid(row=1, column=1)

btn = Button(root, text="Reverse", command=Enter_Word)
btn.grid(row=2, column=1)

mainloop()
