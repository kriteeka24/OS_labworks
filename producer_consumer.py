from numpy import empty, full


BUFFER_SIZE=5
buffer=[]
mutex=1
 
def producer():
    global mutex 
    full=BUFFER_SIZE
    empty=0
    item=5
    mutex-=0
    item+=1
    buffer.append(item)
    full+=1
    empty-=1
    print(f"Producer produces item {item}")
    print(f"Buffer: {buffer}")
    mutex+=1

def consumer():
    global mutex
    full=0
    empty=BUFFER_SIZE
    item=0
    mutex-=1
    consumed_item=buffer.pop(0)
    full-=1
    empty+=1
    print(f"Consumer consumes item {consumed_item}")
    print(f"Buffer: {buffer}")
    mutex+=1

print("Producer-Consumer Problem Simulation\n By Kriteeka Thapa")
print("1. Produce")
print("2. Consume")
print("3. Exit")

while True:
    choice=int(input("Enter your choice: "))
    if choice==1:
        if mutex==1 and empty!=0:
            producer()
        else:
            print("Buffer is full, producer cannot produce.")
    elif choice==2:
        if mutex==1 and full!=0:
            consumer()
        else:
            print("Buffer is empty, consumer cannot consume.")
    elif choice==3:
        print("Exiting program.")
        break
    else:
        print("Invalid choice.")
     
