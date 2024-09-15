
from gtts import gTTS
import speech_recognition as sr
from playsound import playsound
import os 
import pyautogui
import webbrowser
from datetime import datetime
from datetime import date
import locale
import pywhatkit
from time import sleep
import wikipedia
from googletrans import Translator
import pyjokes 
import requests
class Alexa:
    __recognizer = sr.Recognizer()
    wikipedia.set_lang("ar")
    translator = Translator()
    # Set the locale to Arabic (Egypt)
    locale.setlocale(locale.LC_ALL, 'ar_EG.UTF-8')
    def __Open_Terminal(self):
        self.Speak("حاضر يا كبير")
        pyautogui.hotkey("ctrl","alt","t")
        
    def __Open_GitHub(self):
        self.Speak("حاضر يا كبير")
        webbrowser.open_new_tab("https://github.com/")

    def __Open_MyYoutubeChannel(self):
        self.Speak("حاضر يا كبير")
        webbrowser.open_new_tab("https://www.youtube.com/")

    def __Open_ChatGpt(self):
        self.Speak("حاضر يا كبير")
        webbrowser.open_new_tab("https://chatgpt.com/")

    def __Time_now(self):
        # Get the current time
        current_time = datetime.now().time()
        # Format the time as an Arabic string
        arabic_time = current_time.strftime('%I:%M:%S %p').replace('ص', 'صباحاً').replace('م', 'مساءً')
        Alexa.Speak(arabic_time)        

    def __Date_Today(self):
        # Get the current date
        today = datetime.now()
        # Format the date as an Arabic string
        arabic_date = today.strftime('%d %B %Y')        
        Alexa.Speak(arabic_date) 

    def __Whoami(self):
        Alexa.Speak("انت احسن لاعب في العالم")   

          
    def __Open_youtube_video(self,text):
        pywhatkit.playonyt(text)
        sleep(6)
        pyautogui.click(300,300)
        pyautogui.press('enter')     

    def __Search_In_Google(self,text):
        self.Speak("حاضر يا كبير")
        text= " ".join(text.split()[3:])
        pywhatkit.search(text)

    def __Bye_Alexa(self):
        Alexa.Speak("باي باي يا بنزيما")  
        exit()

    def __TakeScreenShot(self):
        self.Speak("حاضر يا حبيبي")
        pyautogui.click("prtscr")

    def __DollarPriceinEGP(self):
        currency_Api_key="235fd4efba806bae608a35d794d42e7a" 
        data = requests.get('http://data.fixer.io/api/latest?access_key='+currency_Api_key).json()
        DollarInEGP=round(data["rates"]["EGP"]/data["rates"]["USD"],2)
        self.Speak(f"الدولار دلوقتي عامل {DollarInEGP} جنيها")

    def __WeatherNow(self):
        city_name = "Cairo"
        # API endpoint and request parameters
        api_key = "fae4e4336c31fe86cbbcc17161fec8e5"
        url = f"http://api.openweathermap.org/data/2.5/weather?q={city_name}&appid={api_key}&units=metric"
        response = requests.get(url)
        Weather = response.json()
        Weather_Description_En =Weather["weather"][0]["description"]
        try:
            # Translate the text from English to Arabic
            translation = self.translator.translate(Weather_Description_En, dest="ar")
            Weather_Description_ar = translation.text
        except Exception as e:
            # Handle any exceptions that occur during translation
            print(f"An error occurred during translation: {e}")
        Weather_Description_ar = None  # or some default value
        Temperature= Weather["main"]["temp"]
        Humidity=Weather["main"]["humidity"]
        self.Speak(f"حالة الطقس الأن {Weather_Description_ar}, و تبلغ درجة الحرارة الأن {Temperature} درجة , ايضا تبلغ درجة الرطوبة {Humidity} في المئة")

    def __AdhanTiming(self,text):
        api_endpoint = "https://api.aladhan.com/v1/timings"
        latitude = 30.0626  # Your latitude
        longitude = 31.2497  # Your long
        today = date.today().strftime("%Y-%m-%d")
        params = {
            "latitude": latitude,
            "longitude": longitude,
            "date": today,
        }
        response = requests.get(api_endpoint, params=params)
        data = response.json()
        if(self.__search_words_in_string(["الشروق"],text)):
            shrouq = data["data"]["timings"]["Sunrise"]
            self.Speak(f"موعد الشروق الساعة {shrouq} صباحا")
        elif (self.__search_words_in_string(["الظهر"],text)):
            Alduhr = data["data"]["timings"]["Dhuhr"]
            self.Speak(f"موعد صلاة الظهر الساعة {Alduhr}")
        elif (self.__search_words_in_string(["العصر"],text)):
            Alasr = data["data"]["timings"]["Asr"]
            self.Speak(f"موعد صلاة العصر الساعة {Alasr}")
        elif (self.__search_words_in_string(["المغرب"],text)):
            maghrib = data["data"]["timings"]["Maghrib"]
            self.Speak(f"موعد صلاة المغرب الساعة {maghrib}")
        elif (self.__search_words_in_string(["العشاء"],text)):
            Isha = data["data"]["timings"]["Isha"]
            self.Speak(f"موعد صلاة العشاء الساعة {Isha}")
        elif (self.__search_words_in_string(["الفجر"],text)):
            Fajr = data["data"]["timings"]["Fajr"]
            self.Speak(f"موعد صلاة الفجر الساعة {Fajr} صباحا")
        else:
            Alexa.Speak(" مفهمتش قول تاني")   

    def Recognize_Speech(self,lang="ar-EG"):
        with sr.Microphone() as source:
            print("Talk")
            self.__recognizer.adjust_for_ambient_noise(source)
            audio_text = self.__recognizer.listen(source)
            print("Time over, thanks")
            try:
                # using google speech recognition
                mytext= self.__recognizer.recognize_google(audio_text, language=lang)
                print(mytext)
            except:
                print("Sorry, I did not get that")
                mytext = '0'            
        return mytext
    
    def Speak(self,text):
        myobj = gTTS(text=text, lang="ar", slow=False)
        # Saving the converted audio in a mp3 file named
        # welcome 
        myobj.save("audio.mp3")
        # for playing note.mp3 file
        playsound("audio.mp3")
        os.remove("audio.mp3")
    def __search_words_in_string(self,words_list,str):
        Text_found  = [word for word in words_list if word in str]
        return (len(Text_found)!=0)
    
    def Respond_to_Speech(self,text):
        if (self.__search_words_in_string(["جديده","ترمنال","ترمينال"],text)):
            self.__Open_Terminal()
        elif(self.__search_words_in_string(["هاب","هب","git","hub","جيت"],text)):
            self.__Open_GitHub()
        elif(self.__search_words_in_string(["يوتيوب","قناتي","youtube","تيوب"],text)):
            self.__Open_MyYoutubeChannel()    
        elif(self.__search_words_in_string(["شات","جي بي تي"],text)):
            self.__Open_ChatGpt()       
        elif (self.__search_words_in_string(["الساعه"],text)):
            self.__Time_now()        
        elif (self.__search_words_in_string(["انهارده يوم","النهارده يوم","انهاردا يوم"," النهاردا يوم","تاريخ","يوم"],text)):
            self.__Date_Today()   
        elif (self.__search_words_in_string(["صباح","الخير"],text)):
            Alexa.Speak("صباح الخير يا بنزيما") 
        elif (self.__search_words_in_string(["اسمي"],text)):
            self.__Whoami()
        elif (self.__search_words_in_string(["باي يا"],text)):
            self.__Bye_Alexa()
        elif (self.__search_words_in_string(["قران","شغلي"],text)):
            self.__Open_youtube_video(text)
        elif(self.__search_words_in_string(["جوجل","سيرش"],text)):
            self.__Search_In_Google(text)
        elif(self.__search_words_in_string(["سكرين","شوت","خدي"],text)):
            self.__TakeScreenShot()

        elif (self.__search_words_in_string(["دولار","سعر"],text)):
              self.__DollarPriceinEGP()

        elif (self.__search_words_in_string(["الطقس","الجو","الحراره"],text)):
              self.__WeatherNow()

        elif(self.__search_words_in_string(["اذان","صلاه","الشروق"],text)):
                self.__AdhanTiming(text)

        else:
            Alexa.Speak(" مفهمتش قول تاني")    
       



Alexa = Alexa()

