import pickle
import random
import hashlib

def createPassword(phrase, fileName):
    hashedPhrase = hashlib.sha1(phrase.encode('utf-8')).hexdigest()
    """fout = open("count.txt", "r")
    count = fout.read()
    count=count+1
    fin = open("count.txt", "w")
    fin.write(count)
    fin.close()"""
    fileName = "pF"+fileName
    fin = open(fileName, "w")
    fin.write(hashedPhrase)
    fin.close()
    return True

def extractPassword(fileName):
    fileName = "pF"+fileName
    fout = open(fileName, "r")
    password = fout.read()
    fout.close()
    return password 

if __name__ == "__main__":
    print("Welcome to passwordProtect")
    while True: 
     print("Enter 1 to extract, 2 to create")
     input = int(input("Enter choice: "))
     if(input == 2):
        fileName = input("Enter name of the place the password has to be used at: ")
        fileName.lower()
        phrase = input("Enter phrase: ")
        createPassword(phrase, fileName)
     elif(input == 1):
        fileName = input("Enter the fileName: ")
        fileName.lower()
        password = extractPassword(fileName)
        print("The password is : "+password)
     else: 
         print("We are grateful for your use!")
         exit()
    



