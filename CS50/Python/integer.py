# n = input("Input: ")
# if n.isnumeric():
#     print("Integer.")
# else:
#     print("Not integer")

try:
    n = int(input("Input: "))
    print("Integer.")

except ValueError:
    print("Not integer.")