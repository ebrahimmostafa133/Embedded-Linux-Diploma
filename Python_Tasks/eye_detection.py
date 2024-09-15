import cv2
import time
import os
from playsound import playsound  # for playing sound when drowsiness is detected

# Get the current directory of the Python script
script_dir = os.path.dirname(os.path.abspath(__file__))

# Define the path to the sound file within the same folder
sound_file_path = os.path.join(script_dir, 'warning_sound.mp3')

# Load Haar cascade classifiers for face and eye detection
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')
eye_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_eye.xml')

# Constants to define drowsiness
EYE_CLOSED_FRAMES = 20  # Number of consecutive frames with closed eyes to detect drowsiness
CLOSED_EYE_TIME = 3  # Seconds of closed eyes to trigger a warning

# Variable to track closed-eye frames
closed_eye_frames = 0

# Start the video capture
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    # Convert the frame to grayscale (required for Haar cascades)
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Detect faces
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)

    # Loop through all detected faces
    for (x, y, w, h) in faces:
        # Draw a rectangle around the face
        cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)

        # Region of interest (ROI) for detecting eyes
        roi_gray = gray[y:y + h, x:x + w]
        roi_color = frame[y:y + h, x:x + w]

        # Detect eyes within the face region
        eyes = eye_cascade.detectMultiScale(roi_gray)

        if len(eyes) == 0:
            closed_eye_frames += 1
        else:
            closed_eye_frames = 0

        # If eyes are closed for enough consecutive frames, trigger a warning
        if closed_eye_frames >= EYE_CLOSED_FRAMES:
            cv2.putText(frame, "WARNING: Drowsiness detected!", (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
            playsound(sound_file_path)  # Play a sound to alert the user
            closed_eye_frames = 0  # Reset the frame counter

    # Display the resulting frame
    cv2.imshow('Drowsiness Detection', frame)

    # Break the loop if the user presses 'q'
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the video capture object and close the display window
cap.release()
cv2.destroyAllWindows()
