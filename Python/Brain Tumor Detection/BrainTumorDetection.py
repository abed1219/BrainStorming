import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

import tensorflow as tf
from tensorflow import keras
from keras import layers
from keras.models import Sequential
from keras.layers import Conv2D, MaxPooling2D, Dense, Flatten
from keras.metrics import BinaryAccuracy, Precision, Recall
import warnings
warnings.filterwarnings("ignore")
tf.keras.backend.clear_session()


data = keras.utils.image_dataset_from_directory("Brain Dataset/brain_tumor_dataset")
batch = data.as_numpy_iterator().next()

fig, ax = plt.subplots(3, 5, figsize=(15,10))
ax = ax.flatten()
for idx, img in enumerate(batch[0][:15]):
    ax[idx].imshow(img.astype(int))
    ax[idx].title.set_text(batch[1][idx])

data = data.map(lambda x, y: (x / 255, y))

batch = data.as_numpy_iterator().next()

print("Minimum value of the scaled data:", batch[0].min())
print("Maximum value of the scaled data:", batch[0].max())


print("There are", len(data), "batches in our data")


train_size = int(len(data)*0.6)
val_size = int(len(data)*0.2)+1
test_size = int(len(data)*0.2)+1

print("Train Size:", train_size)
print("Validation Size:", val_size)
print("Test Size:", test_size)

print("Sum of Train, Validation and Test sizes is equal to:", train_size + val_size + test_size)

train = data.take(train_size)
val = data.skip(train_size).take(val_size)
test = data.skip(train_size + val_size).take(test_size)


batch = data.as_numpy_iterator().next()


data_augmentation = Sequential([
    layers.RandomFlip("horizontal_and_vertical", input_shape=(256,256,3)),
    layers.RandomZoom(0.1),
    layers.RandomContrast(0.1),
    layers.RandomRotation(0.2)
])

image = batch[0]


# plt.figure(figsize=(10, 10))
# for i in range(9):
#     augmented_image = data_augmentation(image)
#     ax = plt.subplot(3, 3, i + 1)
#     plt.imshow(augmented_image[0])
#     plt.axis("off")

model = Sequential([
    data_augmentation,
    Conv2D(16, (3, 3), 1, activation="relu", padding="same"),
    Conv2D(16, (3, 3), 1, activation="relu", padding="same"),
    MaxPooling2D(),
    Conv2D(32, (5, 5), 1, activation="relu", padding="same"),
    Conv2D(32, (5, 5), 1, activation="relu", padding="same"),
    MaxPooling2D(),
    Conv2D(16, (3, 3), 1, activation="relu", padding="same"),
    Conv2D(16, (3, 3), 1, activation="relu", padding="same"),
    MaxPooling2D(),

    Flatten(),
    Dense(128, activation="relu"),
    Dense(1, activation="sigmoid")
])

model.compile(optimizer="adam", loss=keras.losses.BinaryCrossentropy(), metrics=["accuracy"])

model.summary()


history = model.fit(train, epochs=15, validation_data=val)


fig, ax = plt.subplots(2, 1, figsize=(10,8))

ax[0].plot(history.history["loss"], label="Train")
ax[0].plot(history.history["val_loss"], label="Validation")
ax[0].title.set_text("Loss")
ax[0].legend()

ax[1].plot(history.history["accuracy"], label="Train")
ax[1].plot(history.history["val_accuracy"], label="Validation")
ax[1].title.set_text("Accuracy")
ax[1].legend()

plt.show()

bin_acc = BinaryAccuracy()
recall = Recall()
precision = Precision()

for batch in test.as_numpy_iterator():
    X, y = batch
    yhat = model.predict(X)
    bin_acc.update_state(y, yhat)
    recall.update_state(y, yhat)
    precision.update_state(y, yhat)

print("Accuracy:", bin_acc.result().numpy(), "\nRecall:", recall.result().numpy(), "\nPrecision:", precision.result().numpy())






# Manual Testing

# batch = test.as_numpy_iterator().next()
#
#
# img, label = batch[0][15], batch[1][15]
# plt.imshow(img)
# if label==1:
#     plt.title("Brain with Tumor")
# else:
#     plt.title("Brain with No Tumor")
# plt.show()
#
# y_hat = model.predict(np.expand_dims(img, 0))
#
# if y_hat < 0.5:
#     print("No tumor detected")
# else:
#     print("Tumor detected")