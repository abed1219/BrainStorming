import cv2
import face_recognition

video_capture = cv2.VideoCapture(0)

known_faces = []
known_names = []

previous_face_locations = []
previous_face_encodings = []

while True:
    ret, frame = video_capture.read()

    rgb_frame = frame[:, :, ::-1]

    face_locations = face_recognition.face_locations(rgb_frame)
    face_encodings = face_recognition.face_encodings(rgb_frame, face_locations)

    for (top, right, bottom, left), face_encoding in zip(face_locations, face_encodings):
        matches = face_recognition.compare_faces(known_faces, face_encoding)

        if True in matches:
            first_match_index = matches.index(True)
            name = known_names[first_match_index]
        else:
            name = input("Please enter a name for this new face: ")
            known_faces.append(face_encoding)
            known_names.append(name)

        cv2.rectangle(frame, (left, top), (right, bottom), (0, 255, 0), 2)
        
        cv2.putText(frame, name, (left, top - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

    previous_face_locations = face_locations
    previous_face_encodings = face_encodings

    cv2.imshow('Video', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

video_capture.release()
cv2.destroyAllWindows()

