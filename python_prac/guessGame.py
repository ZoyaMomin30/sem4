number = 221
chance = 3

print("you have 3 chances ")
while chance>0:
    guess = int(input("enter your guess : "))

    if guess==number:
        print("guess is correct \n congratulations you won!")
        break
    else:
        chance=chance-1
        print("you have ",chance,"chances left")

if chance==0:
    print("your chances are over \n you lost")
print("\n thankyou for playing")    
    
