# TUPLE
marks =("98","78","54","91","83","93,")
print("the TUPLE is: ", marks,"\n")

print("1. Slicing the tuple from index 1 to 5 ",marks[1:6])
print("2. The number of marks(count): ",len(marks))
print("3. The sorted tuple is: ",sorted(marks))
print("4. The min and max marks are ", min(marks), "and",max(marks), "respectively.\n")

# LIST
fruits = ['apple', 'mango', 'banana', 'cherry']
print("The LIST is:", fruits, "\n")


removed_fruit = fruits.pop(2)
print("1. Removed fruit:", removed_fruit)


fruits.reverse()
print("2. Reversed list:", fruits)

fruits.sort()
print("3. Sorted list:  " ,fruits)

x=fruits.index("mango")
print("4. The index of mango:",x ,"\n")

#DICTIONARY

student={
    "Name":"Zoya Momin",
    "Roll No": 221257,
    "Branch": "Computer Engineering",
    "year":"2nd",
    "semester" : 3
}

print("The dictionary is : ",student,"\n")

student.update({"age":19})
print("1. Adding age element to the %dictionary: " ,student)
print("2. The values:  ", student.values())
student.popitem()
print("3. Removing the last item ",student)
y=student.get("Roll No")
print("4. Roll Number is: ",y,"\n")
    
#SET

sports={"badminton","tennis","football","cricket","boxing"}
x=sports.copy()

print("1. the Set is : ",x)

sports.add("swimming")
print("2. Adding swimming to the set: ",sports)

sports.remove("tennis")
print("3. Removing tennis from the set: ", sports)


sports.discard("football")
print("4. The SET after discarding a specific sport football from  the set: s",sports)










