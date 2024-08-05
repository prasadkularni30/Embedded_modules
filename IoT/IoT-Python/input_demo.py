student_name = input("Enter student name: ")
student_age = int(input("Enter student age: "))


print("Student name is {0} \nAge is {1}".format(student_name,student_age))

"""
    Input function stores data in string only
    
"""
print("student_age data type",type(student_age))


if student_age <18:
    if student_age==16:
        print("solava varis dhokyachaaa..!")
    print(f"student {student_name} is minor")
elif student_age == 18:
    print("porya 18 ch zala")
elif student_age >60:
    print("Student {0} is very old".format(student_name))
else:
    pass