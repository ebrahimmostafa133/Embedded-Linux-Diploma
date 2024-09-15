#---------  lec 4 ----------
# author: Ebrahim Mostafa

#------------------------------------------------ Task 2 ------------------------------------------------
#Python program to parse header file and read all prototypes of function
# and insert it into excel sheet with unique ID start with IDX0

import re
import pandas as pd
import openpyxl

def parse_header_and_write_to_excel(header_file_path, excel_file_path):
    # Regular expression to match function prototypes
    function_pattern = re.compile(r'^\w+[\w\s\*]+\w+\(.*?\);', re.MULTILINE)

    # List to store function prototypes
    function_prototypes = []

    # Read the header file and find all function prototypes
    with open(header_file_path, 'r') as file:
        content = file.read()
        function_prototypes = function_pattern.findall(content)

    # Prepare data for the Excel sheet
    data = {
        'Unique ID': [f'IDX{i:03d}' for i in range(len(function_prototypes))],
        'Function Prototype': function_prototypes
    }

    # Create a DataFrame
    df = pd.DataFrame(data)

    # Write the DataFrame to an Excel sheet
    df.to_excel(excel_file_path, index=False)

    print(f"Function prototypes have been written to {excel_file_path}")

# Input header file path and output excel file path
header_file_path = r"D:\benzema_benzema\System\2 MCAL\MUART\MUART_interface.h"
excel_file_path = r"D:\Embedded Linux\1.Python\Python_tasks\MUART_function_prototypes.xlsx"

# Execute the function
parse_header_and_write_to_excel(header_file_path, excel_file_path)


