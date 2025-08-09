#import os
import shutil

src=input("Enter the source  : ")
dest = input("enter the destination : ")
shutil.move(src,dest)

#shutil.copy('FileDir.txt','newFile.txt')



#path = input("Enter the path : ")
#files = os.listdir(path)
#print()
#print(files)


