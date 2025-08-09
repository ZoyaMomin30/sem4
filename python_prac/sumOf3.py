def sum(n):
    result=0
    for i in str(n):
      result = result+int(i)
    return result

n=int(input("Enter a 3 digit number : "))
print("the sum of the 3 digit number is : ",sum(n))
      

    
