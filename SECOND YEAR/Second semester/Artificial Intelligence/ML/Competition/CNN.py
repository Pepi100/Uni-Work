import numpy as np
from PIL import Image 
from PIL import ImageFilter
import matplotlib.pyplot as plt 
import time


import tensorflow as tf
from tensorflow.keras import layers, models
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.callbacks import ReduceLROnPlateau
from tensorflow.keras.preprocessing.image import ImageDataGenerator


# train
trainImages = []
trainLabels = []

readFile = open("/kaggle/input/unibuc-dhc-2023/train.csv",'r')
pair = readFile.readline() #trecem peste prima linie
pair = readFile.readline()
while pair:
    pair = pair.split(",")
    image = Image.open("/kaggle/input/unibuc-dhc-2023/train_images/" + pair[0])
    imageArray = np.asarray(image) 
    image.close()
    trainImages.append(imageArray) # adaug imaginea in vectorul corespunzator
    trainLabels.append(int(pair[1])) # adaug labelul pozei in vectorul corespunzator
    pair = readFile.readline()
        
        
# validation
validationImages = []
validationLabels = []

readFile = open("/kaggle/input/unibuc-dhc-2023/val.csv",'r')
pair = readFile.readline() #trecem peste prima linie
pair = readFile.readline()
while pair:
    pair = pair.split(",")
    image = Image.open("/kaggle/input/unibuc-dhc-2023/val_images/" + pair[0])
    imageArray = np.asarray(image) 
    image.close()
    validationImages.append(imageArray) # adaug imaginea in vectorul corespunzator
    validationLabels.append(int(pair[1])) # adaug labelul pozei in vectorul corespunzator
    pair = readFile.readline()
        

        
# test


testImages = []
testImageNames = []
        
readFile = open("/kaggle/input/unibuc-dhc-2023/test.csv",'r')
pair = readFile.readline() #trecem peste prima linie
pair = readFile.readline()
while pair:
    pair = pair.rstrip("\n")
    image = Image.open("/kaggle/input/unibuc-dhc-2023/test_images/" + pair)
    imageArray = np.asarray(image) 
    image.close()
    testImageNames.append(pair)
    testImages.append(imageArray) 
    pair = readFile.readline()
    

# arr = np.array(trainImages)
# print(arr.shape)
# print("test")
# print(testImageNames[2])

        
        
trainImages = np.stack(trainImages, axis=0)
validationImages = np.stack(validationImages, axis=0)
trainLabels = np.stack(trainLabels, axis=0)
validationLabels = np.stack(validationLabels, axis=0)

trainImages = trainImages/255
validationImages = validationImages/255
        
        
testImages = np.stack(testImages, axis=0)
testImages = testImages/255

megaTrain = np.concatenate((trainImages, validationImages),axis=0)
megaTrainLabels = np.concatenate((trainLabels, validationLabels),axis=0)


# Useful functions
def validate(model, validationImages, validationLabels):
    
    # Convert validation labels to numpy array
    validationLabels = np.array(validationLabels)
    
    # Evaluate the model
    loss, accuracy = model.evaluate(validationImages, validationLabels)
    
    print("Validation Loss:", loss)
    print("Validation Accuracy:", accuracy)
    
    
def createSubmission(model, testImages):
    predicted = model.predict(testImages)
    predicted_classes = np.argmax(predicted, axis=1) #get predicted classes
    f = open("submissionFinal.csv", "w")
    f.write("Image,Class\n") #print initial line
    for i in range(len(testImages)):
        string = str(testImageNames[i]).rstrip('\n') + "," + str(predicted_classes[i]).rstrip('\n') + "\n"
        f.write(string)
    f.close()

# dropoutlayer 40 epoch without = 68
# dropout 0.25 4 epoch = 67.5
# dropout 0.69 4 epoch = 73.6

# dropout 69 80 epoch = 76
# dropout 75 80 epoch = 75
# dropout 72 80 epoch = 76.4
# dropout 55 80 epoch = 75
# dropout 65 80 epoch = 73
# dropout 31 80 epoch = 69

# dropout 72 after dense 0.748
# dropout before and after 50+25 = 0.746
# dropout before and after 72+25 = 0.7849
# dropout before and after 72+25 120 epochs = 0.796
# dropout before and after 72+25 40 epochs = .778

# batch normalization
#  III => 0.623
#  all -> 0,763
# all + relu -> 0.72
# all 120 - 0.75



model = models.Sequential()
model.add(layers.Conv2D(32, (3, 3), activation='gelu', input_shape=(64, 64, 3)))
model.add(layers.BatchNormalization())
model.add(layers.MaxPooling2D((2, 2)))
model.add(layers.Conv2D(64, (3, 3), activation='relu'))#relu
model.add(layers.BatchNormalization())
model.add(layers.MaxPooling2D((2, 2)))
model.add(layers.Conv2D(128, (3, 3), activation='gelu')) #gelu
model.add(layers.BatchNormalization())
model.add(layers.MaxPooling2D((2, 2)))
model.add(layers.Dropout(0.72))
model.add(layers.Flatten())
model.add(layers.Dense(128, activation='relu'))
model.add(layers.Dropout(0.25))
model.add(layers.Dense(96, activation='softmax'))

model.compile(optimizer='adam', loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=False), metrics=['accuracy']) 
model.fit(trainImages, trainLabels, batch_size=64, epochs=120,verbose=1)


validate(model, validationImages, validationLabels)


# Generate Confussion Matrix
# predicted = model.predict(validationImages)
# predicted_classes = np.argmax(predicted, axis=1)

# confusionMatrix = np.zeros((96, 96))
# for i in range(len(validationImages)):
#     confusionMatrix[validationLabels[i],predicted_classes[i]] += 1
    
# plt.figure(figsize=(10,10))
# plt.matshow(confusionMatrix,cmap='PRGn')
# plt.colorbar()
# plt.show()



# train on megaTrain for submission

model.compile(optimizer='adam', loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=False), metrics=['accuracy']) 
model.fit(megaTrain, megaTrainLabels, batch_size=64, epochs=120,verbose=1)

createSubmission(model, testImages)


