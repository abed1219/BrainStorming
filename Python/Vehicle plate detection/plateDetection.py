import cv2
import matplotlib.pyplot as plt

if(region_height >= min_height and region_height <= max_height
    and region_width >= min_width and region_width <= max 
    and region_width < region_height):
    
    flag = 1
    go += 1
    print(go)
    flg, (ax1) = plt.subplots(1)
    ax1.imshow(grey_car_image, cmap="grey")
    plate_like_objects.append(binary_car_image[min_row:max_row,min_col:max_col])
    plate_objects_coordinates.append((min_row,min_col,max_row,max_col))
    rectBorder = patches.Rectangle((min_col,min_row),max_col - min_col,max_row - min_row,
                                   edgecolor="red", linwidth=2,fill=false)

    ax1.add_patch(rectBorder)
    plt.show()
    cropped_car_image = grey_car_image[min_row:max_row,min_col:max_col]
    
    print(type(cropped_car_image))
    
    changed_color = cv2.cvtColor(cropped_car_image,cv2.COLOR_BGR2GRAY)
    inverted_image = cv2.cvtColor(cropped_car_image)
    threshold_value_license_plate = threshold_otsu(inverted_image)
    
    print(threshold_value_license_plate)
    
    threshold_image = inverted_image > threshold_value_license_plate
    
    flg,(ax1) = plt.subplots(1)
    ax1.imshow(threshold_image,cmap='grey')
    plt.show()
    