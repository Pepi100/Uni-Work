import numpy as np
import matplotlib.pyplot as plt
from sklearn.naive_bayes import MultinomialNB
from PIL import Image # Pentru porcesari de imagine
from PIL import ImageFilter # Pentru adaugarea de noise peste datele de train -> mai multe date de antrenare
import matplotlib.pyplot as plt # Pentru afisarea matricii de confuzie
import time
​
​
​
# train
trainImages = []
trainLabels = []
​
readFile = open("/kaggle/input/unibuc-dhc-2023/train.csv",'r')
pair = readFile.readline() #trecem peste prima linie
pair = readFile.readline()
while pair:
    pair = pair.split(",")
    image = Image.open("/kaggle/input/unibuc-dhc-2023/train_images/" + pair[0])
    imageArray = np.asarray(image).flatten() 
    image.close()
    trainImages.append(imageArray) 
    trainLabels.append(int(pair[1]))
    pair = readFile.readline()
        
        
# validation
validationImages = []
validationLabels = []
​
readFile = open("/kaggle/input/unibuc-dhc-2023/val.csv",'r')
pair = readFile.readline() #trecem peste prima linie
pair = readFile.readline()
while pair:
    pair = pair.split(",")
    image = Image.open("/kaggle/input/unibuc-dhc-2023/val_images/" + pair[0])
    imageArray = np.asarray(image).flatten() 
    image.close()
    validationImages.append(imageArray) 
    validationLabels.append(int(pair[1]))
    pair = readFile.readline()
        
​
        
# test
​
​
testImages = []
testImageNames = []
        
readFile = open("/kaggle/input/unibuc-dhc-2023/test.csv",'r')
pair = readFile.readline() #trecem peste prima linie
pair = readFile.readline()
while pair:
    pair = pair.rstrip("\n")
    image = Image.open("/kaggle/input/unibuc-dhc-2023/test_images/" + pair)
    imageArray = np.asarray(image).flatten()  
    image.close()
    testImageNames.append(pair)
    testImages.append(imageArray) 
    pair = readFile.readline()
    
​
trainImages = np.stack(trainImages, axis=0)
validationImages = np.stack(validationImages, axis=0)
trainLabels = np.stack(trainLabels, axis=0)
validationLabels = np.stack(validationLabels, axis=0)
​
trainImages = trainImages/255
validationImages = validationImages/255
        
        
testImages = np.stack(testImages, axis=0)
testImages = testImages/255
​
megaTrain = np.concatenate((trainImages, validationImages),axis=0)
megaTrainLabels = np.concatenate((trainLabels, validationLabels),axis=0)
​
​
model = MultinomialNB()
# antrenarea modelului
start = time.process_time()
model.fit(trainImages, trainLabels)
print("Time taken: " + str(time.process_time() - start))
​
​
predicted = model.predict(validationImages)
​
print(model.score(validationImages, validationLabels))
​
​
​
​
model = MultinomialNB()
# antrenarea modelului
start = time.process_time()
model.fit(megaTrain, megaTrainLabels)
print("Time taken: " + str(time.process_time() - start))
​
predicted = model.predict(testImages)
f = open("submissionNB.csv", "w")
f.write("Image,Class\n")
for i in range(len(testImages)):
    string = str(testImageNames[i]).rstrip('\n') + "," + str(predicted[i]).rstrip('\n') + "\n"
    f.write(string)
f.close()
​
​
model.fit(trainImages, trainLabels)
predicted = model.predict(validationImages)
​
confusionMatrix = np.zeros((96, 96))
for i in range(len(validationImages)):
    confusionMatrix[validationLabels[i], predicted[i]] += 1
    
plt.figure(figsize=(10,10))
plt.matshow(confusionMatrix,cmap='PRGn')
plt.colorbar()
plt.show()
​
​