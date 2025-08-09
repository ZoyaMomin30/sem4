while True:
    k=int(input("Choose an option\n1. Stack\n2. Linked List\n3. Queue\n4. Exit\n"))
    list  = []
    def stack():
        
        while True:
            choice=int(input("\nChoose operation\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n"))
            if choice==1:
                item=int(input("Enter element to push : "))
                list.append(item)
                print("Element ",item," added to Stack.")

            elif choice==2:
                if len(list)==0:
                    print("list is empty.")
                else:
                    x=list[-1]
                    stack_list.pop()
                    print("element deleted",list.pop())
                    print("the element deleted is  ",x)
    
            elif choice==3:
                if len(list)==0:
                    print("list is empty")
                else:
                    print("the top element of the stack  is : ",list[-1])

            elif choice==4:
                print(" the stack is :  ",list.copy())

            elif choice==5:
                print("exiting the stack operation")
                break
            else:
                print("invalid choice")
            
    def linked():
        while True:
            choice=int(input("\nchoose operation\n1. Add\n2. Delete\n3. Display\n4. Exit\n"))
            if choice==1:
                index=int(input("Enter the index to  insert : "))
                item=int(input("Enter the element to insert : "))
                list.insert(index,item)
                print("The element ",item," inserted at ",index,"  ")
            
            elif choice==2:
                index=int(input("Enter the index to delete : "))
                del list[index]
                print("Element ",list[index]," deleted.")

            elif choice==3:
                print("the Linked List is ",list.copy())

            elif choice==4:
                print("exiting the linked list operation....")
                break
            else:
                print("invalid choice!")
            
            
    def queue():
        while True:
            choice=int(input("\nchoose operation\n1.enqueue\n2. dequeue\n3. Display\n4. Exit\n"))

            if choice==1:
                item=int(input("enter element to enqueue  : "))
                list.append(item)
                print(" ",item,"  is added to queue")

            elif  choice==2:
                list.pop(0)
                print("element is deleted.")

            elif choice==3:
                print("The queue is : ",list.copy())

            elif choice==4:
                print("exiting the queue operation")
                break
            else:
                print("invalid choice!")
            
    if k==1:
        stack()
    elif  k==2:
        linked()
    elif k==3:
        queue()
    elif k==4:
        print("exiting..")
        break
    
    else:
        print("invalid choice!")
    




