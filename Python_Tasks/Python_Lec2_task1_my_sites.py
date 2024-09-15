#---------  lec 2 ----------
# author: Ebrahim Mostafa


#---------  module file ----------
import webbrowser

# Dictionary of favorite websites
favorite_sites = {
    1: ("LinkedIn", "https://www.linkedin.com/in/ebrahim-mostafa-315756243"),
    2: ("FaceBook", "https://www.facebook.com/ibrahim.mostafa.5836"),
    3: ("GitHub", "https://github.com/ebrahimmostafa133")
}

# Function to open a website using Google Chrome
def open_with_chrome(url):
    chrome_path = "C:/Program Files/Google/Chrome/Application/chrome.exe %s"
    webbrowser.get(chrome_path).open(url)