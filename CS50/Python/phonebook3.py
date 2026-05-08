people = {
    "Asraf": "01912345678",
    "Zayed": "01712345678",
    "Rifat": "01612345678"
}

name = input("Name:")

if name in people:
    print(f"Number {people[name]}")
else:
    print("Not found")