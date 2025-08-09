class Node():                                   #make empty list
    def __init__(self,data=0,next=None,prev=None):
        self.data=data
        self.next=next
        self.prev=prev

class LinkedList():
    def __init__(self):
        self.head=None              #initializing head

    def append(self,data):

        new_node=Node(data)         #made a new_node calling node class

        if self.head is None:
            self.head=new_node
            return
        
        p_node=self.head        #initialising a p of node pointer to traverse through the linked list

        while p_node.next:          #iterate till p_node's next exists
            p_node=p_node.next      #iteration
        p_node.next=new_node        #assigning value

    def prepend(self,data):

        new_node=Node(data)
        new_node.next=self.head     #
        self.head=new_node

    def reverse(self):
        p_node=self.head
        while p_node:
            current_node=p_node
            p_node.next=current_node.prev
            print(current_node.data)
            
            
            

        

    def Print(self):
        p_node=self.head

        while p_node:
            print(p_node.data)
            p_node=p_node.next
        

linked=LinkedList()        

while True:
    k=int(input("Choose an option\n1.Add\n2.Delete\n3.Display\n4.Reverse\n5.Exit\n"))

    if k==1:
        data=int(input("enter data to add"))
        linked.append(data)

    elif k==2:
        print("\nDeleting the  element.")
        linked.delete()

    elif k==3:
        linked.Print()

    elif k==4:
        linked.reverse()

    elif k==5:
        print("exiting the program.")
        break
    else:
        print("please enter  valid choice..")
        
    



        
        

            
            
        
        
        
    
