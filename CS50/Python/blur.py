from PIL import Image, ImageFilter

before = Image.open("default.webp")
after = before.filter(ImageFilter.BoxBlur(10))
after.save("out.webp")