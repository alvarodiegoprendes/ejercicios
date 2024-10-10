""" 
import speech_recognition as sr
import whisper

# obtain audio from the microphone
r = sr.Recognizer()
with sr.Microphone() as source:
    print("Say something!")
    audio = r.listen(source)

# recognize speech using whisper
try:
    print("Whisper thinks you said " + r.recognize_whisper(audio, language="spanish"))
except sr.UnknownValueError:
    print("Whisper could not understand audio")
except sr.RequestError as e:
    print("Could not request results from Whisper")

 """

""" model = whisper.load_model("tiny")
result = model.transcribe(audio)
print(result["text"])
 """
import speech_recognition as sr

r = sr.Recognizer()
m = sr.Microphone()

try:
    print("A moment of silence, please...")
    with m as source: r.adjust_for_ambient_noise(source)
    print("Set minimum energy threshold to {}".format(r.energy_threshold))
    while True:
        print("Say something!")
        with m as source: audio = r.listen(source)
        print("Got it! Now to recognize it...")
        try:
            # recognize speech using whisper
            value = r.recognize_whisper(audio)

            print("You said {}".format(value))
        except sr.UnknownValueError:
            print("Oops! Didn't catch that")
        except sr.RequestError as e:
            print("Uh oh! Couldn't request results from whisper; {0}".format(e))
except KeyboardInterrupt:
    pass