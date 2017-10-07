#include <stdio.h>
#include <usb.h>
int main()
{
    struct usb_bus *bus;
    struct usb_device *dev;
    usb_init();
    usb_find_busses();
    usb_find_devices();
    for (bus = usb_busses; bus; bus = bus->next)
        for (dev = bus->devices; dev; dev = dev->next)
        {
            //printf("Trying device %s/%s\n", bus->dirname, dev->filename);
            //  printf("\tID_VENDOR = 0x%04x\n", dev->descriptor.idVendor);
            //  printf("\tID_PRODUCT = 0x%04x\n", dev->descriptor.idProduct);
            if (dev->descriptor.idProduct == 0x4200)
            {
                printf("All is okey. Flash drive has founded\n");
                return 0;
            }
        }
    printf("ERROR. Can't find flash drive!!\n");
    return -1;
}