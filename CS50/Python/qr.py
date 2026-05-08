import os
import qrcode

img = qrcode.make("https://www.youtube.com/watch?v=0eNc5lJfZFM&t=5525s")
img.save("qr.png", "PNG")