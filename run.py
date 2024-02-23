from build import ImageModifierModule

import sys



def main():
    try:
        filename = str(input('image filename: '))
        alpha = float(input('alpha [1.0, 3.0]: '))
        gamma = int(input('gamma [0, 100]: '))

    except ValueError:
        print("!!! ValueError !!!")
        exit()

    my_obj = ImageModifierModule.ImageModifier(filename, alpha, gamma)
    my_obj.change_contrast() 
    my_obj.display_images()


if __name__ == '__main__':
    sys.exit(main())