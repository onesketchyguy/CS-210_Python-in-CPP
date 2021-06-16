import re
import string

from collections import Counter

def printHelloWorld():
    print("Hello from python!")

def printValue(v):
    print(v)

def multiplyValue(x, y):
    return x * y

def squareValue(v):
    return v * v

def getFileContent(file):
    # open and read the contents of the file
    with open(file, 'r') as fo:
        data = fo.read() 

    # return the data retrieved
    return data

def printWord(word, c):
    print("{:12.12} |{: >4}| {}".format(word, c[word], '•' * int(c[word])))

def getWordCount(file):
    data = getFileContent(file)  # read the file
    data = ''.join([i.upper() if i.isalpha() else ' ' for i in data])   # remove the punctuation
    c = Counter(data.split())   # count the words

    return c

def countWords(file):
    c = getWordCount(file)

    for word in c: # Format the data on screen
        printWord(word, c)

def countWord(file, wordToFind):
    print("Trying to open: {}".format(file))
    print("Trying to find: {}".format(wordToFind))

    c = getWordCount(file)

    for word in c: # Format the data on screen
        if word == wordToFind:
            printWord(word, c)