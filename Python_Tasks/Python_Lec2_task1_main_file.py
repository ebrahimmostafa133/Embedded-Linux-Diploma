#---------  lec 2 ----------
# author: Ebrahim Mostafa

#------------------------------------------------ Task 1 ------------------------------------------------
#1-Make your module that contain favourite websites and have function called Firefox take url and open website
#2- then make main file and print menu of sites for user and let him choice


#---------  main file ----------


from Python_Lec2_task_my_sites import favorite_sites, open_with_chrome

def display_menu():
    print("Choose a website to open:")
    for key, (name, _) in favorite_sites.items():
        print(f"{key}. {name}")
display_menu()
choice = int(input("Enter the number of your choice: "))
if choice in favorite_sites:
    _, url = favorite_sites[choice]
    open_with_chrome(url)
else:
    print("Invalid choice.")