from Alexa_module import Alexa

Alexa.Speak("إزايك يا بنزيما")

while True:
    text =Alexa.Recognize_Speech()
    Alexa.Respond_to_Speech(text)