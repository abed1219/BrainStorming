import qrcode
img = qrcode.make(
    "one"
)
img.save()
img.show()