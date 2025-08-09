#username checking
username=input("enter username : ")

x = len(username)

if (x<=3  or x>=50):
    print("invalid username")

else:
    print("valid username \nthe username is ",username)


#printing game

num = int(input("enter the number of lines : "))

for i in range(1, num + 1):
      print('*' * i)
          
#number guess game

number = 221
chance = 3

print("you have 3 chances ")
while chance>0:
    guess = int(input("enter your guess"))

    if guess==number:
        print("guess is correct \n congratulations you won!")
    else:
        chance=chance-1
        print("you have ",chance,"chances left")

if chance==0:
    print("your chances are over \n you lost")
print("\n thankyou for playing")    
    

        
        
