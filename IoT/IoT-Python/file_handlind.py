file_name="iot_data.txt"

#New way for file handeling
try:            #write business logic in try block
    with open(file_name,"r") as fd:     #open file with desripctor
        data=fd.read()
        print("-------------------")
        print(data)
except FileNotFoundError:               #Write known exception here  
    print("the file not found error")   #FileNotFoundError for file handeling if not found
except Exception as e:                  #if we don't know the exception this except line will 
    print(e)                            #print input if failed
    

file_name="iot_data_1.txt"
try:            #write business logic in try block
    with open(file_name,"w") as fd:     #open file with desripctor
        data=fd.write("Temp is 30c")
        print("-------------------")
        print(data)
        print(fd.closed)
except Exception as e:                  #if we don't know the exception this except line will 
    print(e)                            #print input if failed



#traditional way for file handeling
fd = open(file_name,"r")
data =fd.read()
print("------------------------------------")
print(data)
fd.close() 
print(fd.closed) 
