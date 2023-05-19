from PIL import Image
x1 = -2.0
x2 = 1.0
y1 = -1.5
y2 = 1.5
max_iterations = 500
image_of_x = 1024
image_of_y = 1024
image = Image.new("RGB", (image_of_x, image_of_y))
for y in range(image_of_y):
    zy = y * (y2 - y1) / (image_of_y - 1) + y1
    for x in range(image_of_x):
        zx = x * (x2 - x1) / (image_of_x - 1) + x1
        z = zx + zy * 1j
        c = z
        for i in range(max_iterations):
            if abs(z) > 2.0:
                break
            z = z * z + c
        image.putpixel((x, y), (i % 4 * 64, i % 8 * 32, i % 16 * 16))
image.show()
