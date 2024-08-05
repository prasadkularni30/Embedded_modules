sensor_data = {
    "temperature" : 20,
    "humidity" : 80,
    "deployed_in" : ["DESD","DIoT"],
    "status" : True
}

print(sensor_data)
print(sensor_data['humidity'])
print(sensor_data["deployed_in"])
print(sensor_data["deployed_in"][1])
print(type(sensor_data["deployed_in"][1]))

sensor_data["data"]=100
print(sensor_data)
