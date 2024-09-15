#---------  lec 2 ----------
# author: Ebrahim Mostafa

#------------------------------------------------ Task 2 ------------------------------------------------
#Get your public IP https://api.ipify.org/?format=json
#Get your location https://ipinfo.io/<YOUR_IP>/geo

import requests

def get_public_ip():
    # Get the public IP address
    response = requests.get("https://api.ipify.org/?format=json")
    ip_data = response.json()
    return ip_data['ip']

def get_location(ip_address):
    # Get the location information for the provided IP address
    response = requests.get(f"https://ipinfo.io/{ip_address}/geo")
    location_data = response.json()
    return location_data

# Fetch the public IP address
ip_address = get_public_ip()
print(f"Your public IP address is: {ip_address}")

# Fetch location information based on the public IP address
location_data = get_location(ip_address)
print("Your location details based on IP:")
for key, value in location_data.items():
    print(f"{key.capitalize()}: {value}")


