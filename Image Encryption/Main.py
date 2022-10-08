from tkinter import *
from tkinter import filedialog

root = Tk()  # Creating tkinter dialog box
root.title('My App')  # Name the Dialog box title
root.geometry("400x260")  # Size of Dialog box
root.configure(bg='#D9D9D6')  # Background color of Dialog box


# Taking file for encrypting and decrypting from the local source
def encrypt_image():
    # Opening file in jpg, jpeg or png format
    file1 = filedialog.askopenfile(mode='r', filetypes=[('jpg', '*.jpg'), ('jpeg', '*.jpeg'), ('png', '*.png')])
    if file1 is not None:
        # print(file1) # -> For checking that what is type of variable of file1
        file_name = file1.name
        # print(file_name) # -> For checking that we are getting the right data for further operations

        key = entry1.get(1.0, END)  # Extracting the key that is entered by the user
        print(file_name, key)

        # Extracting data from a specific file that have path of the selected image
        specific_file = open(file_name, 'rb')  # And using rb method that will read data in byte formate
        image = specific_file.read()  # Storing all the data in the image variable
        specific_file.close()

        image = bytearray(image)  # Converting pixel data into bytearray
       
        for index, value in enumerate(image):  # Enumerate methode will provide all value of data that store in image variable
            image[index] = value ^ int(key)
        file = open(file_name, 'wb')  # Saving the file after writing the value
        file.write(image)
        file.close()


'''In the button giving name with color and border. At same time defining the encrypt_image by the command option,  
which sets the function or method to be called when the button is clicked'''

b1 = Button(root, border=5, text="Encrypt/Decrypt", width=13, bg='#f5f5f5', fg='black', command=encrypt_image)
b1.place(x=145, y=60)

entry1 = Text(root, height=1, width=15)
entry1.place(x=135, y=95)

root.mainloop()
