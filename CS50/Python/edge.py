from PIL import Image, ImageFilter

before = Image.open("default.webp")
after = before.filter(ImageFilter.FIND_EDGES)
after.save("outedge.webp")