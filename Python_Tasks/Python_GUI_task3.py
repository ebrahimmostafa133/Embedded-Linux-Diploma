#---------  lec 6 ----------
# author: Ebrahim Mostafa

#------------------------------------------------ Task 3 ------------------------------------------------
#Create a graphical application in Python Tkinter that asks the user to enter two integers and displays their sum

from tkinter import *

def calculate_result():
    try:
        m = int(entry_m.get())
        n = int(entry_n.get())

        if operation.get() == "sum":
            result = m + n
            result_text = f"The Sum is: {m} + {n} = {result}"
        elif operation.get() == "sub":
            result = m - n
            result_text = f"The Subtraction is: {m} - {n} = {result}"
        
        result_label.config(text=result_text)
    except ValueError:
        result_label.config(text="Please enter valid integers!")

root = Tk()
root.title("Simple Calculator")

Label(root, text="Enter the value of M:").grid(row=0, column=0)
entry_m = Entry(root)
entry_m.grid(row=0, column=1)

Label(root, text="Enter the value of N:").grid(row=1, column=0)
entry_n = Entry(root)
entry_n.grid(row=1, column=1)

operation = StringVar()
operation.set("sum")  

Radiobutton(root, text="Sum", variable=operation, value="sum").grid(row=2, column=0, sticky=W)
Radiobutton(root, text="Subtraction", variable=operation, value="sub").grid(row=3, column=0, sticky=W)

result_label = Label(root, text="")
result_label.grid(row=4, column=1)

btn = Button(root, text="Validate", command=calculate_result)
btn.grid(row=5, column=1)

mainloop()
