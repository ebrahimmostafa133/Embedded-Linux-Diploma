#---------  lec 4 ----------
# author: Ebrahim Mostafa

#------------------------------------------------ Task 1 ------------------------------------------------
#Write python code to generate Init function of GPIO for AVR

def generate_init_function(filename):
    
    ddr_value = 0
    # Iterate over each bit from 0 to 7
    for bit in range(8):
        mode = input(f"Please enter Bit {bit} mode (in/out): ").strip().lower()
        
        if mode == "out":
            ddr_value |= (1 << bit)  # Set the bit to 1 for 'out'
        elif mode == "in":
            ddr_value &= ~(1 << bit)  # Ensure the bit is 0 for 'in'
        else:
            print("Invalid input. Please enter 'in' or 'out'.")
            return  # Exit the function if input is invalid
        
    # Convert the final ddr_value to binary string format suitable for C code
    ddr_binary = format(ddr_value, '#010b')  

    # Generate the C function code
    c_code = f"""void Init_PORTA_DIR(void)
{{
    DDRA = {ddr_binary};  // Set data direction register for PORTA
}}
"""

    # Write the generated C function to the specified file
    with open(filename, 'w') as c_file:
        c_file.write(c_code)
    print(f"Generated C function has been written to {filename}")

# Execute the function to write to a C file
generate_init_function('Init_PORTA_DIR.c')

