import re
import string
import os
from collections import Counter

def printHelloWorld():
    print("Hello from python!")

def printValue(v):
    print(v)

def multiplyValue(x, y):
    return x * y

def squareValue(v):
    return v * v

def getFileExists(f):
    return os.path.exists(f)

def getFileContent(file):
    # open and read the contents of the file
    with open(file, 'r') as fo:
        data = fo.read() 

    # return the data retrieved
    return data

def getWordHist(word, c):
    return "{:12.12} |{: >4}| {}".format(word, c[word], '•' * int(c[word]))

def getWord(word, c):
    return "{:12.12} {}".format(word, c[word])

def getWordCount(file):
    data = getFileContent(file)  # read the file
    data = ''.join([i.upper() if i.isalpha() else ' ' for i in data])   # remove the punctuation
    c = Counter(data.split())   # count the words

    return c

def countWords(file):
    c = getWordCount(file)

    for word in c: # Format the data on screen
        print(getWord(word, c))

def createWordListFile(wordListFile, newFileName):
    c = getWordCount(wordListFile)

    with open(newFileName, 'w') as fo:
        for word in c: # Format the data within the file
            fo.write(getWord(word, c) + "\n")

def printWordsHist(file):
    c = getWordCount(file)

    for word in c: # Format the data on screen
        print(getWordHist(word, c))

def countWord(file, wordToFind):
    c = getWordCount(file)
    count = 0

    for word in c: # Format the data on screen
        if word == wordToFind:
            count = c[word]

    return count