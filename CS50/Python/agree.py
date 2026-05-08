s = input("Do you agree ? ")

# if s == "Y" or s == "y":
#     print("Agree")
# elif s == "N" or s == "n":
#     print("Not agree")

if s in ["Y", "y", "yes"]:
    print("Agree")
elif s in ["N", "n", "no"]:
    print("Not agree")
else:
    print("Invalid")