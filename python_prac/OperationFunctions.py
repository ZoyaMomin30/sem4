def sum (a,b):
    return a+b


def sub (a,b):
    return a-b

def mul(a,b):
    return  a*b

def div(a,b):
    return a/b

a=int(input("Enter the 1st number : "))
b=int(input("Enter the 2nd number : "))
print(" 1. SUM \n 2. SUBSTRACT \n 3. MULTIPLY \n 4. DIVIDE\n ")

k=int(input("Enter your choice : "))

if k==1:
    print("Result : ", sum(a,b))
        
elif k==2:
    print("result : ", sub(a,b))

elif k==3:
    print("result : ", mul(a,b))

elif k==4:
    print("result : ", div(a,b))    

else:
    print("invalid  choice")
        
        
