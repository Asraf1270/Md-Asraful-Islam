from PIL import Image as asraf, ImageFilter as rifat

before = asraf.open("default.webp")
after = before.filter(rifat.BoxBlur(10))
after.save("out1.webp")