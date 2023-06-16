import numpy as np
import matplotlib.pyplot as plt
from sklearn.naive_bayes import MultinomialNB
from PIL import Image # Pentru porcesari de imagine
from PIL import ImageFilter # Pentru adaugarea de noise peste datele de train -> mai multe date de antrenare
import matplotlib.pyplot as plt # Pentru afisarea matricii de confuzie

# %%
def rgb2gray(rgb):

    r, g, b = rgb[0], rgb[1], rgb[2]
    gray = 0.2989 * r + 0.5870 * g + 0.1140 * b

    return gray
#%%

# pentru datele de train
txtName = "unibuc-dhc-2023/train.csv"
trainImages = []
trainLabels = []

with open(txtName, "r") as reader:
    line = reader.readline()
    line = reader.readline()  # trec peste linia cu id, label
    while line != "":
        imageName, imageLabel = line.rstrip("\n").split(",")  # linia are formatul numePoza.png,valoareLabel
        imagePath = "unibuc-dhc-2023/train_images/" + imageName # dau path-ul imaginii pe care vreau sa o citesc
        image = Image.open(imagePath).convert('L')  # ma folosesc de Image din PIL pentru a deschide imaginea
        imgArray = np.array(image.getdata())  # preiau datele din aceasta imagine si le transform in np.array
                                                 # pentru a putea mai usor cu datele
        # rgb2gray(imgArray)
        
        trainImages.append(imgArray) # adaug imaginea in vectorul corespunzator
        trainLabels.append(int(imageLabel)) # adaug labelul pozei in vectorul corespunzator

        newImageArray = np.array(image.getdata()) # preiau datele din aceasta imagine si le transform in np.array
                                                  # pentru a putea mai usor cu datele
        trainImages.append(newImageArray) # adaug imaginea in vectorul corespunzator
        trainLabels.append(int(imageLabel))  # adaug labelul pozei in vectorul corespunzator

        line = reader.readline()

# pentru datele de validare - abordez aceeasi procedare ca la datele de train
validationImages = []
validationLabels = []
txtName = "unibuc-dhc-2023/val.csv"
with open(txtName, "r") as reader:
    line = reader.readline()
    line = reader.readline()  # trec peste linia cu id, label
    while line != "":
        imageName, imageLabel = line.rstrip("\n").split(",")
        imagePath = "unibuc-dhc-2023/val_images/" + imageName
        image = Image.open(imagePath).convert('L')
        imgArray = np.array(image.getdata())
        # rgb2gray(imgArray)
        validationImages.append(imgArray)
        validationLabels.append(int(imageLabel))
        line = reader.readline()
# trainImages, trainLabels, validationImages, validationLabels
arr = np.array(trainImages)
print(arr.shape)
print("test")


#%%
def values_to_bins(x,bins):
    return np.digitize(x,bins)-1
#%%






#%%
# bins =5
# X_train = values_to_bins(trainImages, bins)
# X_train = values_to_bins(trainImages, bins)

bins_vector = list(range(1, 20))
for bin_number in bins_vector:
    bins = np.linspace(0,255,num=bin_number)
    X_train = values_to_bins(trainImages, bins)
    X_val = values_to_bins(validationImages, bins)
    
    model = MultinomialNB() 
# antrenarea modelului

    model.fit(X_train, trainLabels)



    predicted = model.predict(X_val)
    print(bin_number)
    print(model.score(X_val, validationLabels))

#%%