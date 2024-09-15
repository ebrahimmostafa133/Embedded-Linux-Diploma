#---------  lec 2 ----------
# author: Ebrahim Mostafa

#------------------------------------------------ Task 3 ------------------------------------------------
#Using PyAutoGUI
import pyautogui
import time

#- To open vscode
def open_vscode():
    # Simulate pressing the Windows key to open the Start menu
    pyautogui.press('win')
    time.sleep(1)

    # Type 'Visual Studio Code' to search for VS Code
    pyautogui.write('Visual Studio Code')
    time.sleep(2)

    # Press Enter to open VS Code
    pyautogui.press('enter')
    time.sleep(5)  # Wait for VS Code to open

#- install clangd from extension
#- install c++ testmate from extension
#- install c++ helper from extension
#- install cmake from extension
#- install cmake tools from extension

def install_extension(extension_name):
    # Open the extensions view
    pyautogui.hotkey('ctrl', 'shift', 'x')
    time.sleep(2)

    # Click on the search bar in the extensions tab
    pyautogui.hotkey('ctrl', 'f')
    time.sleep(1)

    # Type the extension name
    pyautogui.write(extension_name)
    time.sleep(2)

    # Press Enter to search
    pyautogui.press('enter')
    time.sleep(2)

    # Click on the Install button
    # i will wait 5 sec until i do it manually
    time.sleep(5)
    
    time.sleep(5)  # Wait for installation to complete
    
extensions = [
        'clangd',                    # Clangd
        'catch2-test-adapter',       # C++ TestMate
        'cpp-helper',                # C++ Helper
        'cmake',                     # CMake
        'cmake-tools'                # CMake Tools
    ]

open_vscode()
    # Install each extension
for extension in extensions:
    install_extension(extension)

print("All extensions have been installed.")