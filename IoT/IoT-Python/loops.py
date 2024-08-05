#1-100 prime numbers
for number in range(0,100):
    if number == 0 or number == 1:
        print(f"{number} is not prime")
        continue
    prime = True
    for div in range(2,(number//2)):
        if((number % div) == 0 ):
            print(f"{number} is not prime")
            prime=False
            break
    if prime == True:
        print(f"{number} is prime")


#USER INPUT
number=int(input("Enter number: "))
prime = True
for div in range(2,int(number/2)):
     if((number % div) == 0 ):
        print(f"{number} is not prime")
        prime=False
        break
if prime == True:
        print(f"{number} is prime")