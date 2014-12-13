#Tayseer Edouni
#taedouni@gmail.com
#tedouni@csu.fullerton.edu
#tweet-a-fortune.py
#Assignment 7
#CSPSC 233P-02 Mo/We
#https://pypi.python.org/pypi/twitter/1.10.0
#https://twitter.com/csufbot

import sqlite3
from twitter import*
import random 

#requirements 
OAUTH_TOKEN = 'NULL'
OAUTH_SECRET = 'NULL'
CONSUMER_KEY = 'NULL'
CONSUMER_SECRET = 'NULL'


#There are five pictures, random number 1-5
def getRandomImage():
    return random.randint(1,5)

#master function for tweeting 
def tweet(Twitter):
    imageNumber = getRandomImage()
    
    #Must get location of image from local computer
    if imageNumber == 1:
        imageString = 'images/1.JPG'
    elif imageNumber == 2:
        imageString = 'images/2.JPG'
    
    elif imageNumber == 3:
        imageString = 'images/3.JPG'
        
    elif imageNumber == 4:
        imageString = 'images/4.JPG'
    
    elif imageNumber == 5:
        imageString = 'images/5.JPG'
    
    status_update = getStatus()
    with open(imageString,'rb') as imageFile:
        params = {'media[]' : imageFile.read(), 'status': status_update}
    Twitter.statuses.update_with_media(**params)

#searches for an appropiate status from the freebsd_fortunes database
#status must be less than 140 characters. If it isn't then it will continue running
#until it finds a suitable text
def getStatus():
    conn = sqlite3.connect('freebsd_fortunes_clean.sl3')
    c = conn.cursor()
    while True:
        indexNumber = random.randint(1,14334)
        for row in c.execute('select aphorism from fortunes where id={};'.format(indexNumber)):
            status_update = row[0]
        if len(status_update) < 140:
            break
    
    conn.close()
    
    return status_update
    
def main():
    t = Twitter(auth=OAuth(OAUTH_TOKEN, OAUTH_SECRET, CONSUMER_KEY, CONSUMER_SECRET))
    tweet(t)
if __name__ == '__main__':
    main()