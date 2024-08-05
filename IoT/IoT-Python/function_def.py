number = 10
def variable_scope():
    number = 10
    print(number)

variable_scope()
print(number)


#block scope
if True:
    value = 20
    print(value)
    
cdac_acts_desd_Tudent_count = 53
    
def display_sum():
    global cdac_acts_desd_Tudent_count
    cdac_acts_desd_Tudent_count=54
    print(cdac_acts_desd_Tudent_count)

display_sum()
print(cdac_acts_desd_Tudent_count)