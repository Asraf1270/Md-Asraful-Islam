people = [
    {"name": "Asraf", "number": "01912345678"},
    {"name": "Zayed", "number": "01712345678"},
    {"name": "Rifat", "number": "01612345678"}
]

name = input("Name: ")
for person in people:
     if person["name"] == name:
         number = person["number"]
         print(f"Found {number}")
         break
else:
     print("Not Found")
