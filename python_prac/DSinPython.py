k=int(input("Choose an option\n1.LINKED LISTS\n2.STACKS\n3.QUEUES"))
if (k==1):
    linked()
elif (k==2):
    stack()
elif  (k==3):
    queue()
else:
    print("invalid choice!")

def linked():
    print("choose the operation")
    x=int(input("1.Add\n2.Delete\n3.Display"))

    class Node:
	def __init__(self, data):
		self.data = data
		self.next = None


def stack():
    print("choose the operation")
    x=int(input("1.Push\n2.Pop\n3.Peek\n4.display"))


def queue():
    print("choose the operation")
    x=int(input("1.Enqueue\n2.Dequeue\n3.Display"))

    
    
    
    
    
    



