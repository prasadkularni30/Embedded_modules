def get_user_input():
    while True:
        try:
            user_input = input("Enter a number: ")
            user_input=int(user_input)
            return user_input
        except Exception as e:
            print(e)
            print(f"Enterd Value {user_input} is not a number. try again!")
            
number = get_user_input()
print("Entered Value :",number)