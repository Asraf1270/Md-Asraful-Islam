import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    c, python, java = 0, 0, 0
    for row in reader:
        favorite = row["language"]
        if favorite == "c":
            c += 1
        elif favorite == "python":
            python += 1
        elif favorite == "java":
            java += 1
    
print(f"c: {c}")
print(f"python: {python}")
print(f"java: {java}")