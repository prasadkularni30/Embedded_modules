import json

sensor_data = {
    "temperature" : 20,
    "humidity" : 80,
    "deployed_in" : ["DESD","DIoT"],
    "status" : True
}

print("------------------------------")
print(sensor_data)
print("------------------------------")
sensor_data["data"]=100
print(sensor_data)
print("-------hum--------------------")
print(sensor_data['humidity'])
print("---------dep----------")
print(sensor_data["deployed_in"])
print("----------dep_1-----------------")
print(sensor_data["deployed_in"][1])
print("------------typr_dep-1------------------")
print(type(sensor_data["deployed_in"][1]))
print("------------------------------")
print(json.dumps(sensor_data,indent=3))

#Modify Data
sensor_data["deployed_in"].append("DAC")
sensor_data["humidity"]=97
print(json.dumps(sensor_data,indent=4))

#Remove a key value pair
sensor_data.pop("status")
print("------------------Dist post pop----")
print(json.dumps(sensor_data,indent=4))

#using Del fun
del sensor_data["deployed_in"]
print("--------dict post del opern-------")
print(json.dumps(sensor_data,indent=4))

sensor_data.update(
    {
        "acc_x_axis":78.2,
        "acc_y_axis":75.5,
        "acc_z_axis":67.76
    }
)
print("-------post update ----------")
print(json.dumps(sensor_data,indent=4))

keys_to_del_in_sensor_data=["acc_y_axis","acc_z_axis"]

for key in keys_to_del_in_sensor_data:
    if key in sensor_data:
        del sensor_data[key]
        

print("-------Dict post del opern-------")
print(json.dumps(sensor_data,indent=4))