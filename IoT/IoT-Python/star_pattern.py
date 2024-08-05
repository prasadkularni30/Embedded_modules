no_rows=int(input("Enter number of rows: "))

for row in range(0,no_rows+1):
    #column=row
    for column in range(row):
        print("*",end=" ")
    print()
for row in range(0,no_rows+1):
    for column in range(0,no_rows+1):
        if(column>=row):
            print("*",end=" ")
        else:
            print(" ",end=" ")
    print()
        
    