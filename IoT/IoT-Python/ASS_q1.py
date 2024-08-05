#Ask the user to enter two keys that needed to be delete from dicyt

import json

sensor_data = {
    "temperature" : 20,
    "humidity" : 80,
    "deployed_in" : ["DESD","DIoT"],
    "status" : True
}
print(json.dumps(sensor_data,indent=2))

#one way for input
del_list=[]
del_list.append(input("enter key 1: "))
del_list.append(input("enter key 2: "))

#another way for input
#del_list=[input("enter key 1: "),input("enter key 2: ")]

#not working
#del_list=[input()]

print(f"Entered Keys: {del_list}")

for key in del_list:
    if key in sensor_data:
        del sensor_data[key]
        
print(json.dumps(sensor_data,indent=2))
        
        
        

