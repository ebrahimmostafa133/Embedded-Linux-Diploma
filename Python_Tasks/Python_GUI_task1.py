import tkinter

# Initialize the main window
m = tkinter.Tk()
m.title("Task1")
m.geometry("300x300")

# Define functions to print names
def print_ebrahim():
    print("Ebrahim")

def print_mostafa():
    print("Mostafa")

def print_mohamed():
    print("Mohamed")

def print_madbouly():
    print("Madbouly")

# Create buttons and assign commands
button1 = tkinter.Button(m, text='button1', command=print_ebrahim)
button1.grid(row=0, column=1)

button2 = tkinter.Button(m, text='button2', command=print_mostafa)
button2.grid(row=1, column=0)

button3 = tkinter.Button(m, text='button3', command=print_mohamed)
button3.grid(row=1, column=2)

button4 = tkinter.Button(m, text='button4', command=print_madbouly)
button4.grid(row=2, column=1)

m.mainloop()
